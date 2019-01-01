#include <stdio.h>
#include <stdlib.h>
#include <catch.hpp>

#include "fmi2AllocGuard.h"
#include "../src/GuardedBookkeeping.h"

struct TestEntry {
  TestEntry( const int _id )
      : id( _id )
  {
  }

  ~TestEntry()
  {
    fmi2_guarded_release( id );
  }

  void test()
  {
    fmi2_guarded_alloc_t pAlloc = fmi2_guarded_get_alloc( id );
    REQUIRE( pAlloc != NULL );

    fmi2_guarded_free_t pFree = fmi2_guarded_get_free( id );
    REQUIRE( pFree != NULL );

    void* p1 = ( *pAlloc )( 1 , sizeof( long ) );
    REQUIRE( p1 != NULL );
    void* p2 = ( *pAlloc )( 1 , sizeof( long ) );
    REQUIRE( p2 != NULL );

    ( *pFree )( p1 );
    ( *pFree )( p2 );

    void* p3 = ( *pAlloc )( 1 , sizeof( double ) );
  }

private:
  const int id;
};

void testRecursive( int& _count )
{
  const int id = fmi2_guarded_acquire();
  if ( id != FMI2_FUNC_INDEX_INVALID ) {
    _count += 1;
    TestEntry te( id );
    te.test();

    testRecursive( _count );

  } else {
    return;
  }
}

TEST_CASE("Test1")
{
  fmi2_guarded_init();

  int count = 0;
  testRecursive( count );
}
