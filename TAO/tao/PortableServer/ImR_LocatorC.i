// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html


// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:70

#if !defined (_IMPLEMENTATIONREPOSITORY_LOCATOR___CI_)
#define _IMPLEMENTATIONREPOSITORY_LOCATOR___CI_

ACE_INLINE
ImplementationRepository::Locator::Locator (
    TAO_Stub *objref,
    CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_Locator_Proxy_Broker_ (0)
{
  this->ImplementationRepository_Locator_setup_collocation (_tao_collocated);
}

ACE_INLINE
ImplementationRepository::Locator::Locator (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (ior, oc),
    the_TAO_Locator_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ci.cpp:72

TAO_PortableServer_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::Locator_ptr
  );

TAO_PortableServer_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    ImplementationRepository::Locator_ptr &
  );

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ci.cpp:81

#if !defined _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_I_
#define _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_I_

CORBA::Boolean TAO_PortableServer_Export operator<< (
    TAO_OutputCDR &,
    const ImplementationRepository::Locator::ServerNameList &
  );

CORBA::Boolean TAO_PortableServer_Export operator>> (
    TAO_InputCDR &,
    ImplementationRepository::Locator::ServerNameList &
  );

#endif /* _TAO_CDR_OP_ImplementationRepository_Locator_ServerNameList_I_ */

