#include "../src/GuardedBookkeeping.hpp"
#include <stdlib.h>

#include "calloc.define.inl"

struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ]
    = {   0
        , NULL
        , NULL
        , NULL };

void fmi2_guarded_bookkeeping_init()
{
  for( int idx_clean = 0 ; idx_clean <= FMI2_FUNC_INDEX_MAX ; ++idx_clean ) {
    fmi2_guarded_bookkeeping[ idx_clean ].id        = -1;
    fmi2_guarded_bookkeeping[ idx_clean ].calloc_p  = NULL;
    fmi2_guarded_bookkeeping[ idx_clean ].free_p    = NULL;
    if( fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper != NULL ) {
      delete fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper;
      fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper = NULL;
    }
  }

#include "init.inl"
}

