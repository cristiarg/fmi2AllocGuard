#include "fmi2AllocGuard.h"
#include <stdlib.h>
#include <cassert>

static const size_t id = 42;

size_t fmi2_guarded_acquire()
{
  return id;
}

fmi2_guarded_alloc_t fmi2_guarded_get_alloc( const size_t entry )
{
  if( entry == id ) {
    return calloc;
  } else {
    return NULL;
  }
}

fmi2_guarded_free_t fmi2_guarded_get_free( const size_t entry )
{
  if( entry == id ) {
    return free;
  } else {
    return NULL;
  }
}

void fmi2_guarded_release( const size_t entry )
{
  assert( id == entry );
}

