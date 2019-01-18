#include "fmi2AllocGuard.h"
#include <stdlib.h>

#include "bookkeeping.h"

void fmi2_guarded_init()
{
  fmi2_guarded_bookkeeping_clear();
  fmi2_guarded_bookkeeping_init();
}

void fmi2_guarded_clear()
{
  fmi2_guarded_bookkeeping_clear();
}

int fmi2_guarded_acquire()
{
  for( int idx = FMI2_FUNC_INDEX_MIN ; idx <= FMI2_FUNC_INDEX_MAX ; ++idx ) {
    if ( !fmi2_guarded_bookkeeping[ idx ].in_use ) {
      struct fmi2_guarded_alloc_free_str* str = &fmi2_guarded_bookkeeping[ idx ];
      str->in_use = true;
      return str->id;
    }
  }
  return FMI2_FUNC_INDEX_INVALID;
}

fmi2_guarded_alloc_t fmi2_guarded_get_alloc( const int _id )
{
  if( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    struct fmi2_guarded_alloc_free_str* str = &fmi2_guarded_bookkeeping[ _id ];
    if ( str->in_use ) {
      return str->calloc_p;
    }
  }
  return NULL;
}

fmi2_guarded_free_t fmi2_guarded_get_free( const int _id )
{
  if ( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    struct fmi2_guarded_alloc_free_str* str = &fmi2_guarded_bookkeeping[ _id ];
    if ( str->in_use ) {
      return str->free_p;
    }
  }
  return NULL;
}

int fmi2_guarded_release( const int _id )
{
  if ( FMI2_FUNC_INDEX_MIN <= _id && _id <= FMI2_FUNC_INDEX_MAX ) {
    struct fmi2_guarded_alloc_free_str* str = &fmi2_guarded_bookkeeping[ _id ];
    if ( str->in_use ) {
      const int cleared_count = avl_clear( &str->pointer_keeper , func_avl_data_clear_free );
      str->in_use = false;
      return cleared_count;
    }
  }
  return 0;
}

