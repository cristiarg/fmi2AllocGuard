#include <catch.hpp>

#include "../src/GuardedBookkeeping.hpp"

TEST_CASE("TestGuardedBookkeeping")
{
  SECTION( "constant invariants" ) {
    REQUIRE( FMI2_FUNC_INDEX_MIN > 0 );
    REQUIRE( FMI2_FUNC_INDEX_MAX > 0 );
    REQUIRE( FMI2_FUNC_INDEX_MIN < FMI2_FUNC_INDEX_MAX );
    REQUIRE( FMI2_FUNC_INDEX_INVALID < 0 );
  }

  SECTION( "empty array elements at the beginning" ) {
    for ( int i = 0 ; i < FMI2_FUNC_INDEX_MIN ; i++ ) {
      fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ i ];
      REQUIRE( str.id == -1 );
      REQUIRE( str.calloc_p == NULL );
      REQUIRE( str.free_p == NULL );
      REQUIRE( str.pointer_keeper == NULL );
    }
  }

  fmi2_guarded_bookkeeping_init();

  SECTION( "useful array elements" ) {
    for ( int j = FMI2_FUNC_INDEX_MIN ; j <= FMI2_FUNC_INDEX_MAX ; j++ ) {
      fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ j ];
      REQUIRE( str.id > 0 );
      REQUIRE( str.calloc_p != NULL );
      REQUIRE( str.free_p != NULL );
      REQUIRE( str.pointer_keeper == NULL );

      str.pointer_keeper = new PointerKeeper();

      {
        void* p1 = ( *str.calloc_p )( 1 , sizeof( int ) );
        REQUIRE( p1 != NULL );

        int* nr1 = reinterpret_cast< int* >( p1 );
        *nr1 = 42;

        ( *str.free_p )( p1 );

        REQUIRE( str.pointer_keeper->flush() == 0 );
      }

      {
        void* p2 = ( *str.calloc_p )( 2 , sizeof( long ) );
        void* p3 = ( *str.calloc_p )( 2 , sizeof( long ) );

        REQUIRE( str.pointer_keeper->flush() == 2 );
      }

      delete str.pointer_keeper;
      str.pointer_keeper = NULL;
    }
  }
}
