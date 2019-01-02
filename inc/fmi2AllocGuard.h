#ifndef FMI2ALLOCGUARD_H
#define FMI2ALLOCGUARD_H

#include <stddef.h>
#include "fmi2Export.h"
#include "fmi2Defines.h"

#ifdef __cplusplus
extern "C" {
#endif

  // calloc/free-like function signatures
  //
  typedef void* ( *fmi2_guarded_alloc_t )( size_t num , size_t size );
  typedef void  ( *fmi2_guarded_free_t  )( void* obj );

  // one time call
  //
  void FMI2ALLOCGUARD_API fmi2_guarded_init();

  // obtain a new entry in the function table
  // the value is an opaque reference for further requests
  //
  int FMI2ALLOCGUARD_API fmi2_guarded_acquire();

  // the getter functions
  // the entry is obtained from a previously called *_acquire
  //
  fmi2_guarded_alloc_t FMI2ALLOCGUARD_API fmi2_guarded_get_alloc( const int _id );
  fmi2_guarded_free_t FMI2ALLOCGUARD_API fmi2_guarded_get_free( const int _id );

  // release an entry in the function table
  // upon calling this, remaining unfreed memory pending to this entry is released
  // the entry is obtained from a previously called *_acquire
  //
  void FMI2ALLOCGUARD_API fmi2_guarded_release( const int _id );

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FMI2ALLOCGUARD_H

