
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl Executor_Destructor_Interceptor
// ------------------------------
#ifndef EXECUTOR_DESTRUCTOR_INTERCEPTOR_EXPORT_H
#define EXECUTOR_DESTRUCTOR_INTERCEPTOR_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL)
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL */

#if !defined (EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL)
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL 1
#endif /* ! EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL */

#if defined (EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL) && (EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL == 1)
#  if defined (EXECUTOR_DESTRUCTOR_INTERCEPTOR_BUILD_DLL)
#    define Executor_Destructor_Interceptor_Export ACE_Proper_Export_Flag
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* EXECUTOR_DESTRUCTOR_INTERCEPTOR_BUILD_DLL */
#    define Executor_Destructor_Interceptor_Export ACE_Proper_Import_Flag
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* EXECUTOR_DESTRUCTOR_INTERCEPTOR_BUILD_DLL */
#else /* EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL == 1 */
#  define Executor_Destructor_Interceptor_Export
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARATION(T)
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* EXECUTOR_DESTRUCTOR_INTERCEPTOR_HAS_DLL == 1 */

// Set EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE)
#  if (ACE_NTRACE == 1)
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE */

#if (EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE == 1)
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_TRACE(X)
#else /* (EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define EXECUTOR_DESTRUCTOR_INTERCEPTOR_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (EXECUTOR_DESTRUCTOR_INTERCEPTOR_NTRACE == 1) */

#endif /* EXECUTOR_DESTRUCTOR_INTERCEPTOR_EXPORT_H */

// End of auto generated file.