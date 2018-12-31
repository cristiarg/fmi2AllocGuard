#include "fmi2AllocGuard.h"
#include "PointerKeeper.hpp"


static const int FMI2_FUNC_INDEX_MIN = 1;
static const int FMI2_FUNC_INDEX_MAX = 5;
static const int FMI2_FUNC_INDEX_INVALID = -1;


struct fmi2_guarded_alloc_free_str {
  int                  id;
  fmi2_guarded_alloc_t calloc_p;
  fmi2_guarded_free_t  free_p;
  PointerKeeper*       pointer_keeper;
};

void* fmi2_calloc1 ( size_t _num , size_t _size );
void* fmi2_calloc2 ( size_t _num , size_t _size );
void* fmi2_calloc3 ( size_t _num , size_t _size );
void* fmi2_calloc4 ( size_t _num , size_t _size );
void* fmi2_calloc5 ( size_t _num , size_t _size );

void fmi2_free1 ( void* _ptr );
void fmi2_free2 ( void* _ptr );
void fmi2_free3 ( void* _ptr );
void fmi2_free4 ( void* _ptr );
void fmi2_free5 ( void* _ptr );

struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ 6 ];

void fmi2_guarded_bookkeeping_init();

