#include "minunit.h"
#include <stdlib.h>
#include <time.h>

#include "../src/bookkeeping.h"

void func_clear_free(void* _data)
{
  if (_data != NULL) {
    free(_data);
  }
}

MU_TEST(TestConstantInvariants)
{
  mu_check( FMI2_FUNC_INDEX_MIN > 0 );
  mu_check( FMI2_FUNC_INDEX_MAX > 0 );
  mu_check( FMI2_FUNC_INDEX_MIN < FMI2_FUNC_INDEX_MAX );
  mu_check( FMI2_FUNC_INDEX_INVALID < 0 );
}

MU_TEST(TestIdleArrayElementsAtTheBeginningAreClean)
{
  for ( int i = 0 ; i < FMI2_FUNC_INDEX_MIN ; i++ ) {
    const struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ i ];
    mu_check( str->id == 0 );
    mu_check( str->calloc_p == NULL );
    mu_check( str->free_p == NULL );
    mu_check( str->pointer_keeper == NULL );
    mu_check( str->in_use == false );
  }
}

void CheckElementIsInitializedAndUnused( const struct fmi2_guarded_alloc_free_str* const _str )
{
  mu_check( _str->id > 0 );
  mu_check( _str->calloc_p != NULL );
  mu_check( _str->free_p != NULL );
  mu_check( _str->pointer_keeper == NULL );
  mu_check( _str->in_use == false );
}

MU_TEST(TestUsefulArrayElementsAreInitializezAndUnused)
{
  for ( int idx = FMI2_FUNC_INDEX_MIN ; idx <= FMI2_FUNC_INDEX_MAX ; ++idx ) {
    struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ idx ];

    CheckElementIsInitializedAndUnused( str );
  }
}

int uniform_distribution_impl( const int _range_low , const int _range_high , const int _rand_val )
{
  const double my_rand = _rand_val / ( 1.0 + RAND_MAX ); 
  const int range = _range_high - _range_low + 1;
  const int my_rand_scaled = ( int )( ( my_rand * range ) + _range_low );
  return my_rand_scaled;
}

int uniform_distribution( const int _range_low , const int _range_high ) {
  //double my_rand = rand()/(1.0 + RAND_MAX); 
  //int range = _range_high - _range_low + 1;
  //int my_rand_scaled = (my_rand * range) + _range_low;
  //return my_rand_scaled;
  return uniform_distribution_impl( _range_low , _range_high , rand() );
}

void AllocRandomNumberOfEntriesInElement( struct fmi2_guarded_alloc_free_str* const _str
    , int* const _alloc_count)
{
  static const int MAX_ALLOC_COUNT = 500;
  static const int MAX_ALLOC_SIZE = 500;

  *_alloc_count = uniform_distribution(1, MAX_ALLOC_COUNT);
  for (int alloc_idx = 0 ; alloc_idx < *_alloc_count ; ++alloc_idx ) {
    const int alloc_elem_size = uniform_distribution(1, MAX_ALLOC_SIZE);
    const int alloc_arr_size = uniform_distribution(1, MAX_ALLOC_COUNT);

    void* const p1 = ( _str->calloc_p )( alloc_arr_size , alloc_elem_size );
    mu_check( p1 != NULL );
  }
}

MU_TEST(TestAllocSomeRandomMemoryInEachSlotAndThenClean)
{
  for ( int j = FMI2_FUNC_INDEX_MIN ; j <= FMI2_FUNC_INDEX_MAX ; j++ ) {
    struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ j ];

    CheckElementIsInitializedAndUnused( str );

    int alloc_count = 0;
    AllocRandomNumberOfEntriesInElement( str , &alloc_count );

    mu_check( str->pointer_keeper != NULL );
    mu_check( alloc_count > 0 );

    mu_check( avl_clear( &str->pointer_keeper , func_clear_free ) == alloc_count );
    mu_check( str->pointer_keeper == NULL );
  }
}

MU_TEST(TestAllocSomeRandomMemoryInEachSlotButDoNotClean)
{
  for ( int j = FMI2_FUNC_INDEX_MIN ; j <= FMI2_FUNC_INDEX_MAX ; j++ ) {
    struct fmi2_guarded_alloc_free_str* const str = &fmi2_guarded_bookkeeping[ j ];

    CheckElementIsInitializedAndUnused( str );

    int alloc_count = 0;
    AllocRandomNumberOfEntriesInElement( str , &alloc_count );

    mu_check( str->pointer_keeper != NULL );
    mu_check( alloc_count > 0 );
  }
}

int main()
{
  srand( (unsigned)time( 0 ) );

  MU_RUN_TEST(TestConstantInvariants);

  MU_RUN_TEST(TestIdleArrayElementsAtTheBeginningAreClean);

  fmi2_guarded_bookkeeping_clear();
  fmi2_guarded_bookkeeping_init();

  MU_RUN_TEST(TestUsefulArrayElementsAreInitializezAndUnused);

  MU_RUN_TEST(TestAllocSomeRandomMemoryInEachSlotAndThenClean);

  MU_RUN_TEST(TestUsefulArrayElementsAreInitializezAndUnused);

  MU_RUN_TEST(TestAllocSomeRandomMemoryInEachSlotButDoNotClean);

  // intermediary clean-up
  fmi2_guarded_bookkeeping_clear();

  // after intermediary clean-up, all data should have been wiped
  MU_RUN_TEST(TestUsefulArrayElementsAreInitializezAndUnused);

  MU_REPORT();

  return 0;
}
