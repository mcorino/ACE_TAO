// This may look like C, but it's really -*- C++ -*-
#ifndef BE_TEMPLATE_MODULE_REF_H
#define BE_TEMPLATE_MODULE_REF_H

#include "be_field.h"

#include "ast_template_module_ref.h"

class be_template_module_ref
  : public virtual AST_Template_Module_Ref,
    public virtual be_field
{
public:
  be_template_module_ref (UTL_ScopedName *n,
                           AST_Template_Module *ref,
                           UTL_StrList *param_refs);

  virtual ~be_template_module_ref ();

  // Cleanup function.
  virtual void destroy ();

  // Visiting.
  virtual int accept (be_visitor *visitor);
};

#endif           // BE_TEMPLATE_MODULE_REF_H
