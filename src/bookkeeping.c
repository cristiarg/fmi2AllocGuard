#include "bookkeeping.h"
#include <stdlib.h>
#include <stdio.h>

int func_comp_lt(const void* const _left, const void* const _rite)
{
  if (_left < _rite )
    return -1;
  else if (_left > _rite)
    return 1;
  else
    return 0;
}

void func_clear_nop(void* _data)
{
  if (_data != NULL) {
    _data = NULL;
  }
}

#include "calloc.define.inl"

struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ]
    = {   0
        , NULL
        , NULL
        , NULL
        , false };

void fmi2_guarded_bookkeeping_init()
{
  for( int idx_clean = 0 ; idx_clean <= FMI2_FUNC_INDEX_MAX ; ++idx_clean ) {
    fmi2_guarded_bookkeeping[ idx_clean ].id        = -1;
    fmi2_guarded_bookkeeping[ idx_clean ].calloc_p  = NULL;
    fmi2_guarded_bookkeeping[ idx_clean ].free_p    = NULL;
    if( fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper != NULL ) {
      printf("INIT: pointer_keeper NOT NULL at index %d\n", idx_clean);
      fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper = NULL;
    }
    fmi2_guarded_bookkeeping[ idx_clean ].in_use    = false;
  }

#include "init.inl"
}

