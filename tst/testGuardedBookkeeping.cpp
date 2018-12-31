#include <catch.hpp>

#include "GuardedBookkeeping.h"

TEST_CASE("TestGuardedBookkeeping")
{
  CHECK( FMI2_FUNC_INDEX_MIN > 0 );
  CHECK( FMI2_FUNC_INDEX_MAX > 0 );
  CHECK( FMI2_FUNC_INDEX_MIN < FMI2_FUNC_INDEX_MAX );
  CHECK( FMI2_FUNC_INDEX_INVALID < 0 );

  for ( int i = 0 ; i < FMI2_FUNC_INDEX_MIN ; i++ ) {
    fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ i ];
    CHECK( str.id == 0 );
    CHECK( str.calloc_p == NULL );
    CHECK( str.free_p == NULL );
    CHECK( str.pointer_keeper == NULL );
  }

  fmi2_guarded_bookkeeping_init();

  // void* p = fmi2_calloc1( 1 , sizeof( long long ) );
  // fmi2_free1

  for ( int j = FMI2_FUNC_INDEX_MIN ; j <= FMI2_FUNC_INDEX_MAX ; j++ ) {
    fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ j ];
    CHECK( str.id > 0 );
    CHECK( str.calloc_p != NULL );
    CHECK( str.free_p != NULL );
    CHECK( str.pointer_keeper == NULL );

    str.pointer_keeper = new PointerKeeper();

    {
      void* p1 = ( *str.calloc_p )( 1 , sizeof( int ) );
      CHECK( p1 != NULL );

      int* nr1 = reinterpret_cast< int* >( p1 );
      *nr1 = 42;

      ( *str.free_p )( p1 );

      CHECK( str.pointer_keeper->flush() == 0 );
    }

    {
      void* p2 = ( *str.calloc_p )( 2 , sizeof( long long ) );
      void* p3 = ( *str.calloc_p )( 2 , sizeof( long long ) );

      CHECK( str.pointer_keeper->flush() == 2 );
    }

    delete str.pointer_keeper;
    str.pointer_keeper = NULL;
  }
}
