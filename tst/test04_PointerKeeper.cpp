#include <catch.hpp>

#include "../src/PointerKeeper.hpp"

TEST_CASE("TestPointerKeeper")
{
  PointerKeeper pk;

  CHECK( false == pk.add( NULL ) );
  CHECK( false == pk.rem( NULL ) );

  void* pInt = calloc( 1 , sizeof( int ) );

  CHECK( pk.add( pInt ) );
  CHECK( pk.add( pInt ) == false );

  CHECK( pk.rem( pInt ) );
  CHECK( pk.rem( pInt ) == false );

  CHECK( false == pk.flush() );

  CHECK( pk.add( pInt ) );
  void* pInt2 = calloc( 1 , sizeof( int ) );
  CHECK( pk.add( pInt2 ) );
  CHECK( 2 == pk.flush() );
}
