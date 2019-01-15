#include <catch.hpp>
#include <stdio.h>

#include "../src/bookkeeping.h"

TEST_CASE("TestStaticInit")
{
  SECTION( "static initialization" ) {
    for( int idx = 0 ; idx <= FMI2_FUNC_INDEX_MAX ; idx++ ) {
      fmi2_guarded_alloc_free_str& str = fmi2_guarded_bookkeeping[ idx ];
      //if ( idx == 0 || idx == FMI2_FUNC_INDEX_MAX )
      //  printf( "[ %d ] %d    %p    %p    %p\n"
      //      , idx
      //      , str.id
      //      , reinterpret_cast< void* >( str.calloc_p )
      //      , reinterpret_cast< void* >( str.free_p )
      //      , reinterpret_cast< void* >( str.pointer_keeper ) );
      REQUIRE( str.id == 0 );
      REQUIRE( str.calloc_p == NULL );
      REQUIRE( str.free_p == NULL );
      REQUIRE( str.pointer_keeper == NULL );
    }
  }
}


