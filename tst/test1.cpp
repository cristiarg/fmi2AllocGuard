#include <stdio.h>
#include <stdlib.h>
#include <catch.hpp>

#include "fmi2AllocGuard.h"

TEST_CASE("Test1")
{
  const size_t id = fmi2_guarded_acquire();
  CHECK( id == 42 );

  fmi2_guarded_alloc_t pAlloc = fmi2_guarded_get_alloc( id );
  CHECK( pAlloc != NULL );
  fmi2_guarded_alloc_t pAllocNull = fmi2_guarded_get_alloc( -1 );
  CHECK( pAllocNull == NULL );

  fmi2_guarded_free_t pFree = fmi2_guarded_get_free( id );
  CHECK( pFree != NULL );
  fmi2_guarded_free_t pFreeNull = fmi2_guarded_get_free( -1 );
  CHECK( pFreeNull == NULL );

  fmi2_guarded_release( id );
  //fmi2_guarded_release( -1 );
    // TODO: to be further investigated how to actually check that some call asserts
}
