#include "minunit.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#include "fmi2AllocGuard.h"

//void testOne(
//      const int _id
//    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
//    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free )
//{
//  fmi2_guarded_alloc_t pAlloc = _ptr_fmi2_guarded_get_alloc( _id );
//  mu_check( pAlloc != NULL );
//
//  fmi2_guarded_free_t pFree = _ptr_fmi2_guarded_get_free( _id );
//  mu_check( pFree != NULL );
//
//  void* p1 = pAlloc( 1 , sizeof( long ) );
//  mu_check( p1 != NULL );
//  void* p2 = ( *pAlloc )( 1 , sizeof( long ) );
//  mu_check( p2 != NULL );
//
//  pFree( p1 );
//  pFree( p2 );
//
//  // make some alloc's and leave them to be unallocated upon release
//  for (int i = 0 ; i < 42 ; ++i ) {
//    void* p3 = ( *pAlloc )( 10 , sizeof( double ) );
//    mu_check( p3 != NULL );
//  }
//}

//void testRecursive(
//      fmi2_guarded_acquire_t    _ptr_fmi2_guarded_acquire
//    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
//    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free
//    , fmi2_guarded_release_t    _ptr_fmi2_guarded_release
//    , bool*                     _reachedInvalid
//    , int*                      _count )
//{
//  const int id = _ptr_fmi2_guarded_acquire();
//  if ( id != FMI2_FUNC_INDEX_INVALID ) {
//    *_count += 1;
//
//    testOne( id, _ptr_fmi2_guarded_get_alloc, _ptr_fmi2_guarded_get_free );
//
//    testRecursive(
//          _ptr_fmi2_guarded_acquire
//        , _ptr_fmi2_guarded_get_alloc
//        , _ptr_fmi2_guarded_get_free
//        , _ptr_fmi2_guarded_release
//        , _reachedInvalid
//        , _count );
//
//    const int released_count = _ptr_fmi2_guarded_release(id);
//    mu_check(released_count == 42);
//
//  } else {
//    *_reachedInvalid = true;
//  }
//}

MU_TEST(test_shared_lib_use)
{
  // init library internals
  // one time per-address-space call
  fmi2_guarded_init();

  const int entry_id = fmi2_guarded_acquire();
  mu_check( entry_id != FMI2_FUNC_INDEX_INVALID );
  if ( entry_id == FMI2_FUNC_INDEX_INVALID ) {
    return;
  }

  // obtain function pointers of the calloc/free-like functions
  // corresponding to the entry id obtained above
  fmi2_guarded_alloc_t ptr_alloc_func = fmi2_guarded_get_alloc( entry_id );
  mu_check( ptr_alloc_func != NULL );

  fmi2_guarded_free_t ptr_free_func = fmi2_guarded_get_free( entry_id );
  mu_check( ptr_free_func != NULL );

  //bool reachedInvalid = false;
  //int count = 0;
  //testRecursive(
  //      _ptr_fmi2_guarded_acquire
  //    , _ptr_fmi2_guarded_get_alloc
  //    , _ptr_fmi2_guarded_get_free
  //    , _ptr_fmi2_guarded_release
  //    , &reachedInvalid
  //    , &count );
  //mu_check( count == ( FMI2_FUNC_INDEX_MAX - FMI2_FUNC_INDEX_MIN + 1 ) );
  //mu_check( reachedInvalid );

  // cleanup whatever's left
  // after calling this, it is possible to call
  // again the init (even in the same adress space)
  fmi2_guarded_clear();
}

MU_TEST_SUITE(test_use_shared_lib_suite)
{
	//MU_SUITE_CONFIGURE(&test_shared_lib_init, &test_shared_lib_teardown);

	//MU_RUN_TEST(test_shared_lib_load);
	MU_RUN_TEST(test_shared_lib_use);
}

int main()
{
  MU_RUN_SUITE(test_use_shared_lib_suite);
  MU_REPORT();

  return 0;
}
