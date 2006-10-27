/* -*- C++ -*- */

// =================================================================
/**
 * @file IIOP_Current_Loader.cpp
 *
 * $Id$
 *
 * @author Iliyan Jeliazkov <iliyan@ociweb.com>
 *
 */
// =================================================================


#include "ace/Service_Config.h"

#include "tao/ORBInitializer_Registry.h"
#include "tao/ORB_Constants.h"

#include "tao/PI/PI.h"

#include "orbsvcs/Transport_Current/Current_ORBInitializer.h"
#include "orbsvcs/Transport_Current/IIOP_Current_Loader.h"
#include "orbsvcs/Transport_Current/IIOP_Current_Impl.h"

ACE_RCSID (Transport_Current,
           IIOP_Current_Loader,
           "$Id$")

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
  namespace Transport
  {
    namespace IIOP
    {
      /// Initializes object when dynamic linking occurs.
      int
      Current_Loader::init (int, ACE_TCHAR *[])
      {
        PortableInterceptor::ORBInitializer_ptr tmp = 0;
        ACE_NEW_THROW_EX (tmp,
                          Current_ORBInitializer<IIOP_Current_Impl> (ACE_TEXT ("TAO::Transport::IIOP::Current")),
                          CORBA::NO_MEMORY (CORBA::SystemException::_tao_minor_code (TAO::VMCID,
                                                                                     ENOMEM),
                                            CORBA::COMPLETED_NO));
        ACE_TRY_CHECK;

        PortableInterceptor::ORBInitializer_var initializer (tmp);

        PortableInterceptor::register_orb_initializer (initializer.in ()
                                                       ACE_ENV_ARG_PARAMETER);
        ACE_TRY_CHECK;

        return 0;
      }
    }

  }
}


#if defined (TAO_AS_STATIC_LIBS)
ACE_STATIC_SVC_REQUIRE (TAO_Transport_IIOP_Current_Loader);

namespace TAO
{
  namespace Transport
  {
    namespace IIOP
    {
      int current_static_initializer (void)
      {
        ACE_STATIC_SVC_REGISTER (TAO_Transport_IIOP_Current_Loader);
        return 0;
      }
    }
  }
}
#endif /* defined (TAO_AS_STATIC_LIBS) */


TAO_END_VERSIONED_NAMESPACE_DECL

ACE_STATIC_SVC_DEFINE (TAO_Transport_IIOP_Current_Loader,
                       ACE_TEXT ("TAO_Transport_IIOP_Current_Loader"),
                       ACE_SVC_OBJ_T,
                       &ACE_SVC_NAME (TAO_Transport_IIOP_Current_Loader),
                       ACE_Service_Type::DELETE_THIS | ACE_Service_Type::DELETE_OBJ,
                       0)

ACE_FACTORY_NAMESPACE_DEFINE (TAO_Transport_Current,
                              TAO_Transport_IIOP_Current_Loader,
                              TAO::Transport::IIOP::Current_Loader)
