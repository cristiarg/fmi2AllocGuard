#include "fmi2AllocGuard.h"
#include <stdlib.h>

#include "GuardedBookkeeping.hpp"

void fmi2_guarded_init()
{
  fmi2_guarded_bookkeeping_init();
}

int fmi2_guarded_acquire()
{
  for( int idx = FMI2_FUNC_INDEX_MIN ; idx <= FMI2_FUNC_INDEX_MAX ; ++idx ) {
    if ( !fmi2_guarded_bookkeeping[ idx ].in_use ) {
      fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ idx ];
      str.in_use = true;
      return str.id;
    }
  }
  return FMI2_FUNC_INDEX_INVALID;
}

fmi2_guarded_alloc_t fmi2_guarded_get_alloc( const int _id )
{
  if( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ _id ];
    if ( str.in_use ) {
      return str.calloc_p;
    }
  }
  return NULL;
}

fmi2_guarded_free_t fmi2_guarded_get_free( const int _id )
{
  if ( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ _id ];
    if ( str.in_use ) {
      return str.free_p;
    }
  }
  return NULL;
}

void func_clear_free(void* _data)
{
  if (_data != NULL) {
    free(_data);
  }
}

void fmi2_guarded_release( const int _id )
{
  if ( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ _id ];
    if ( str.in_use ) {
      avl_clear( &str.pointer_keeper , func_clear_free );
      str.in_use = false;
    }
  }
}

