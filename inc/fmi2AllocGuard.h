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
  // calling this more than once, will lead to free-ing allocated memory
  //
  void FMI2ALLOCGUARD_API fmi2_guarded_init();

  // all still existing entries are freed
  // any entry id's still held by clients becomes invalid
  //
  void FMI2ALLOCGUARD_API fmi2_guarded_clear();

  // obtain a new entry id in the function table
  // the value is an opaque reference for further requests
  // if no entry is available for use, FMI2_FUNC_INDEX_INVALID is returned
  //
  int FMI2ALLOCGUARD_API fmi2_guarded_acquire();

  // the getter functions
  // the id is obtained from a previously called *_acquire
  //
  fmi2_guarded_alloc_t FMI2ALLOCGUARD_API fmi2_guarded_get_alloc( const int _id );
  fmi2_guarded_free_t FMI2ALLOCGUARD_API fmi2_guarded_get_free( const int _id );

  // release an entry in the function table
  // upon calling this, remaining unfreed memory pending to this entry is released
  // the entry id is obtained from a previously called *_acquire
  //
  int FMI2ALLOCGUARD_API fmi2_guarded_release( const int _id );

  // TODO:
  //  - add logging/dump capability upon release/termination; or at
  //    least some sort of information as to the leaked memory; or
  //    at the very least, whether there was some leak or not (ie
  //    let fmi2_guarded_release return some info)
  //

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FMI2ALLOCGUARD_H

