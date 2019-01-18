#ifndef FMI2GUARDEDBOOKKEEPING_H
#define FMI2GUARDEDBOOKKEEPING_H

#include "fmi2Export.h"
#include "fmi2AllocGuard.h"
#include "avl.h"

struct fmi2_guarded_alloc_free_str {
  int                  id;
  fmi2_guarded_alloc_t calloc_p;
  fmi2_guarded_free_t  free_p;
  struct avl_node*     pointer_keeper;
  bool                 in_use;
};

#include "bookkeeping.declare.inl"

int   func_avl_data_comp_lt(const void* const _left, const void* const _rite);
void  func_avl_data_clear_free(void* _data);
void  func_avl_data_clear_nop(void* _data);

extern struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ];

void fmi2_guarded_bookkeeping_clear();
void fmi2_guarded_bookkeeping_init();

#endif // FMI2GUARDEDBOOKKEEPING_H

