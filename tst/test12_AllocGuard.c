#include "minunit.h"
#include <stdbool.h>

#include "fmi2AllocGuard.h"

void test(const int _id)
{
  fmi2_guarded_alloc_t pAlloc = fmi2_guarded_get_alloc( _id );
  mu_check( pAlloc != NULL );

  fmi2_guarded_free_t pFree = fmi2_guarded_get_free( _id );
  mu_check( pFree != NULL );

  void* p1 = pAlloc( 1 , sizeof( long ) );
  mu_check( p1 != NULL );
  void* p2 = ( *pAlloc )( 1 , sizeof( long ) );
  mu_check( p2 != NULL );

  pFree( p1 );
  ( *pFree )( p2 );

  // make some alloc's and leave them to be unallocated upon release
  for (int i = 0 ; i < 100000 ; ++i ) {
    void* p3 = ( *pAlloc )( 10 , sizeof( double ) );
    mu_check( p3 != NULL );
  }
}

bool testRecursive( int* _count )
{
  const int id = fmi2_guarded_acquire();
  if ( id != FMI2_FUNC_INDEX_INVALID ) {
    *_count += 1;

    test(id);

    const bool res_rec = testRecursive( _count );

    fmi2_guarded_release(id);

    return res_rec;
  } else {
    return true; // reached invalid
  }
}

MU_TEST(TestAllocGuard)
{
  fmi2_guarded_init();
  fmi2_guarded_init();

  int count = 0;
  const bool reachedInvalid = testRecursive( &count );
  mu_check( count == ( FMI2_FUNC_INDEX_MAX - FMI2_FUNC_INDEX_MIN + 1 ) );
  mu_check( reachedInvalid );

}

int main()
{
  MU_RUN_TEST(TestAllocGuard);
  MU_REPORT();
  return 0;
}
