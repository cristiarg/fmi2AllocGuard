//#include <stdio.h>
#include "minunit.h"

#include "../src/bookkeeping.h"

MU_TEST(TestStaticInit)
{
  for( int idx = 0 ; idx <= FMI2_FUNC_INDEX_MAX ; idx++ ) {
    const struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ idx ];
    //if ( idx == 0 || idx == FMI2_FUNC_INDEX_MAX )
    //  printf( "[ %d ] %d    %p    %p    %p\n"
    //      , idx
    //      , str.id
    //      , reinterpret_cast< void* >( str.calloc_p )
    //      , reinterpret_cast< void* >( str.free_p )
    //      , reinterpret_cast< void* >( str.pointer_keeper ) );
    mu_check( str->id == 0 );
    mu_check( str->calloc_p == NULL );
    mu_check( str->free_p == NULL );
    mu_check( str->pointer_keeper == NULL );
  }
}

int main()
{
  MU_SUITE_CONFIGURE_SHOW_PROGRESS(0);

  MU_RUN_TEST(TestStaticInit);
  MU_REPORT();

  return 0;
}
