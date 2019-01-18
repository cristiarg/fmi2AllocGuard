#include "bookkeeping.h"
#include <stdlib.h>
#include <stdio.h>

int func_avl_data_comp_lt(const void* const _left, const void* const _rite)
{
  if (_left < _rite )
    return -1;
  else if (_left > _rite)
    return 1;
  else
    return 0;
}

void func_avl_data_clear_free(void* _data)
{
  if (_data != NULL) {
    free(_data);
  }
}


void func_avl_data_clear_nop(void* _data)
{
  if (_data != NULL) {
    _data = NULL;
  }
}

#include "bookkeeping.define.inl"

struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ]
    = {   0  };
        //, NULL
        //, NULL
        //, NULL
        //, false };

void fmi2_guarded_bookkeeping_clear()
{
  for( int idx_wipe = 0 ; idx_wipe <= FMI2_FUNC_INDEX_MAX ; ++idx_wipe ) {
    struct fmi2_guarded_alloc_free_str* str = &fmi2_guarded_bookkeeping[ idx_wipe ];
    
    str->id        = -1;
    str->calloc_p  = NULL;
    str->free_p    = NULL;

    // the following sequence is pretty weak semantically
    // but, for the time being, no better alternative in sight
    if( str->pointer_keeper != NULL ) {
      if ( str->in_use ) {
        // it can be asssumed that we're being called to clean previously used slots
        avl_clear( &str->pointer_keeper , func_avl_data_clear_free );
      }
      else {
        str->pointer_keeper = NULL;
      }
    }

    str->in_use = false;

      //printf("INIT: pointer_keeper NOT NULL at index %d\n", idx_clean);
      //fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper = NULL;
  }
}

void fmi2_guarded_bookkeeping_init()
{
#include "bookkeeping.init.inl"
}

