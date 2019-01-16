#include "minunit.h"
#include <stdlib.h>

#include "../src/bookkeeping.h"

void func_clear_free(void* _data)
{
  if (_data != NULL) {
    free(_data);
  }
}

void test_constant_invariants()
{
  mu_check( FMI2_FUNC_INDEX_MIN > 0 );
  mu_check( FMI2_FUNC_INDEX_MAX > 0 );
  mu_check( FMI2_FUNC_INDEX_MIN < FMI2_FUNC_INDEX_MAX );
  mu_check( FMI2_FUNC_INDEX_INVALID < 0 );
}

void test_empty_array_elements_at_the_beginning()
{
  for ( int i = 0 ; i < FMI2_FUNC_INDEX_MIN ; i++ ) {
    const struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ i ];
    mu_check( str->id == 0 );
    mu_check( str->calloc_p == NULL );
    mu_check( str->free_p == NULL );
    mu_check( str->pointer_keeper == NULL );
  }
}

void test_useful_array_elements()
{
  for ( int j = FMI2_FUNC_INDEX_MIN ; j <= FMI2_FUNC_INDEX_MAX ; j++ ) {
    struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ j ];
    mu_check( str->id > 0 );
    mu_check( str->calloc_p != NULL );
    mu_check( str->free_p != NULL );
    mu_check( str->pointer_keeper == NULL );

    {
      void* p1 = ( str->calloc_p )( 1 , sizeof( int ) );
      mu_check( p1 != NULL );

      mu_check( str->pointer_keeper != NULL );

      int* nr1 = ( int* )p1;
      *nr1 = 42;

      ( str->free_p )( p1 );

      mu_check( avl_clear( &str->pointer_keeper , func_clear_free ) == 0 );
      mu_check( str->pointer_keeper == NULL );
    }

    {
      void* p2 = ( str->calloc_p )( 2 , sizeof( long ) );
      mu_check( p2 != NULL );
      void* p3 = ( str->calloc_p )( 2 , sizeof( long ) );
      mu_check( p3 != NULL );

      mu_check( str->pointer_keeper != NULL );

      mu_check( avl_clear( &str->pointer_keeper , func_clear_free ) == 2 );
      mu_check( str->pointer_keeper == NULL );
    }
  }
}

MU_TEST(TestGuardedBookkeeping)
{
  test_constant_invariants();;
  test_empty_array_elements_at_the_beginning();

  fmi2_guarded_bookkeeping_init();

}

int main()
{
  MU_RUN_TEST(TestGuardedBookkeeping);
  MU_REPORT();

  return 0;
}
