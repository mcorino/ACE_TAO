#include "PICurrent_Guard.h"

#if TAO_HAS_INTERCEPTORS == 1


ACE_RCSID (PortableServer,
           PICurrent_Guard,
           "$Id$")


#include "tao/ORB_Core.h"
#include "tao/TAO_Server_Request.h"
#include "tao/PICurrent_Copy_Callback.h"


TAO::PICurrent_Guard::PICurrent_Guard (TAO_ServerRequest &server_request,
                                       bool tsc_to_rsc)
  : src_ (0),
    dest_ (0),
    copy_callback_ (server_request.pi_current_copy_callback ()),
    tsc_to_rsc_ (tsc_to_rsc)
{
  // This constructor is used on the server side.

  // Retrieve the thread scope current (no TSS access incurred yet).
  PICurrent * pi_current = server_request.orb_core ()->pi_current ();

  // If the slot count is zero, there is nothing to copy.  Prevent any
  // copying (and hence TSS accesses) from occurring.
  if (pi_current != 0 && pi_current->slot_count () != 0)
    {
      // Retrieve the request scope current.
      PICurrent_Impl * rsc = &server_request.rs_pi_current ();

      // Retrieve the thread scope current.
      PICurrent_Impl * tsc = pi_current->tsc ();

      if (tsc_to_rsc)
        {
          // TSC to RSC copy.
          // Occurs after receive_request() interception point and
          // upcall.
          this->src_  = tsc;
          this->dest_ = rsc;
        }
      else
        {
          // RSC to TSC copy.
          // Occurs after receive_request_service_contexts()
          // interception point.
          this->src_  = rsc;
          this->dest_ = tsc;
        }
    }
}

TAO::PICurrent_Guard::~PICurrent_Guard (void)
{
  if (this->src_ != 0 && this->dest_ != 0
      & this->src_ != this->dest_)
    {
      // This copy better be exception-safe!
      this->dest_->lc_slot_table (this->src_);

      // PICurrent will potentially have to call back on the request
      // scope current so that it can deep copy the contents of the
      // thread scope current if the contents of the thread scope
      // current are about to be modified.  It is necessary to do this
      // deep copy once in order to completely isolate the request
      // scope current from the thread scope current.  This is only
      // necessary, if the thread scope current is modified after its
      // contents have been *logically* copied to the request scope
      // current.  The same goes for the reverse, i.e. RSC to TSC.
      this->copy_callback_.src_and_dst (this->src_, this->dest_);
      this->src_->copy_callback (&this->copy_callback_);
    }
}


#endif  /* TAO_HAS_INTERCEPTORS == 1 */
