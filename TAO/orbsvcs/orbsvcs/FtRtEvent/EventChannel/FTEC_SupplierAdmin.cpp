// $Id$

#include "orbsvcs/orbsvcs/Event/EC_ProxySupplier.h"
#include "orbsvcs/orbsvcs/Event/EC_Event_Channel_Base.h"
#include "FTEC_SupplierAdmin.h"
#include "FTEC_ProxyConsumer.h"
#include "tao/Stub.h"

ACE_RCSID (EventChannel,
           TAO_FTEC_SupplierAdmin,
           "$Id$")


const FtRtecEventChannelAdmin::OperationType
TAO_FTEC_SupplierAdmin::OBTAIN_ID = FtRtecEventChannelAdmin::OBTAIN_PUSH_CONSUMER;

TAO_FTEC_SupplierAdmin::TAO_FTEC_SupplierAdmin (TAO_EC_Event_Channel_Base *ec)
  : TAO_EC_SupplierAdmin (ec)
  , FT_Aspect(this, this->event_channel_->supplier_poa ())
{
}

TAO_FTEC_SupplierAdmin::~TAO_FTEC_SupplierAdmin()
{
}


RtecEventChannelAdmin::ProxyPushConsumer_ptr
TAO_FTEC_SupplierAdmin::obtain_push_consumer (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((CORBA::SystemException))
{
  return obtain_proxy(ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_FTEC_SupplierAdmin::disconnect(RtecEventChannelAdmin::ProxyPushConsumer_ptr obj)
{
  ACE_TRY_NEW_ENV {
    obj->disconnect_push_consumer(ACE_ENV_SINGLE_ARG_PARAMETER);
    ACE_TRY_CHECK;
  }
  ACE_CATCHALL
  {
  }
  ACE_ENDTRY;
}





