#include "minunit.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#include "fmi2AllocGuard.h"

//#include <dlfcn.h>
//
//void * fmi2_lib_handle = NULL;
//
//// prototypes in the library header
//typedef void                  ( *fmi2_guarded_init_t      )(           );
//typedef int                   ( *fmi2_guarded_acquire_t   )(           );
//typedef fmi2_guarded_alloc_t  ( *fmi2_guarded_get_alloc_t )( const int );
//typedef fmi2_guarded_free_t   ( *fmi2_guarded_get_free_t  )( const int );
//typedef int                   ( *fmi2_guarded_release_t   )( const int );
//
//fmi2_guarded_init_t       ptr_fmi2_guarded_init       = NULL;
//fmi2_guarded_acquire_t    ptr_fmi2_guarded_acquire    = NULL;
//fmi2_guarded_get_alloc_t  ptr_fmi2_guarded_get_alloc  = NULL;
//fmi2_guarded_get_free_t   ptr_fmi2_guarded_get_free   = NULL;
//fmi2_guarded_release_t    ptr_fmi2_guarded_release    = NULL;
//
////void ( *ptr_fmi2_guarded_init )() = NULL;
////int ( *ptr_fmi2_guarded_acquire )() = NULL;
////fmi2_guarded_alloc_t ( *ptr_fmi2_guarded_get_alloc )( const int ) = NULL;
////fmi2_guarded_free_t ( *ptr_fmi2_guarded_get_free )( const int ) = NULL;
////int ( *ptr_fmi2_guarded_release )( const int ) = NULL;

void test_shared_lib_init()
{
  srand( (unsigned)time(0) );
}

void test_shared_lib_teardown()
{
  //if ( fmi2_lib_handle != NULL ) {
  //  dlclose( fmi2_lib_handle );
  //  fmi2_lib_handle = NULL;
  //}
}

//MU_TEST(test_shared_lib_load)
//{
//  char* err = NULL;
//  dlerror(); // cleanup possible previous error
//  void * fmi2_lib_handle = dlopen("./libfmi2AllocGuard.so", RTLD_LAZY);
//  err = dlerror();
//  mu_check(fmi2_lib_handle != NULL);
//  mu_check(err == NULL);
//  if (err != NULL) {
//    fprintf(stderr, "dlopen failed: %s\n", err);
//    return;
//  }
//
//  *(void**)(&ptr_fmi2_guarded_init) = dlsym( fmi2_lib_handle , "fmi2_guarded_init" );
//  err = dlerror();
//  mu_check(ptr_fmi2_guarded_init != NULL);
//  mu_check(err == NULL);
//  if (err != NULL) {
//    fprintf(stderr, "fmi2_guarded_init NOT FOUND: %s\n", err);
//    return;
//  }
//
//  *(void**)(&ptr_fmi2_guarded_acquire) = dlsym( fmi2_lib_handle , "fmi2_guarded_acquire" );
//  err = dlerror();
//  mu_check(ptr_fmi2_guarded_acquire != NULL);
//  mu_check(err == NULL);
//  if (err != NULL ) {
//    fprintf(stderr, "fmi2_guarded_acquire NOT FOUND: %s\n", err);
//    return;
//  }
//
//  *(void**)(&ptr_fmi2_guarded_get_alloc) = dlsym( fmi2_lib_handle , "fmi2_guarded_get_alloc");
//  err = dlerror();
//  mu_check(ptr_fmi2_guarded_get_alloc != NULL);
//  mu_check(err == NULL);
//  if (err != NULL ) {
//    fprintf(stderr, "fmi2_guarded_get_alloc NOT FOUND: %s\n", err);
//    return;
//  }
//
//  *(void**)(&ptr_fmi2_guarded_get_free) = dlsym( fmi2_lib_handle , "fmi2_guarded_get_free");
//  err = dlerror();
//  mu_check(ptr_fmi2_guarded_get_free != NULL);
//  mu_check(err == NULL);
//  if (err != NULL) {
//    fprintf(stderr, "fmi2_guarded_get_free NOT FOUND: %s\n", err);
//    return;
//  }
//
//  *(void**)(&ptr_fmi2_guarded_release) = dlsym( fmi2_lib_handle , "fmi2_guarded_release");
//  err = dlerror();
//  mu_check(ptr_fmi2_guarded_release != NULL);
//  mu_check(err == NULL);
//  if (err != NULL) {
//    fprintf(stderr, "fmi2_guarded_release NOT FOUND: %s\n", err);
//    return;
//  }
//
//}
//
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
//
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
//
//void testStart(
//      fmi2_guarded_init_t       _ptr_fmi2_guarded_init
//    , fmi2_guarded_acquire_t    _ptr_fmi2_guarded_acquire
//    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
//    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free
//    , fmi2_guarded_release_t    _ptr_fmi2_guarded_release )
//{
//  _ptr_fmi2_guarded_init();
//
//  bool reachedInvalid = false;
//  int count = 0;
//  testRecursive(
//        _ptr_fmi2_guarded_acquire
//      , _ptr_fmi2_guarded_get_alloc
//      , _ptr_fmi2_guarded_get_free
//      , _ptr_fmi2_guarded_release
//      , &reachedInvalid
//      , &count );
//  mu_check( count == ( FMI2_FUNC_INDEX_MAX - FMI2_FUNC_INDEX_MIN + 1 ) );
//  mu_check( reachedInvalid );
//}

MU_TEST(test_shared_lib_use)
{
  //testStart(
  //    ptr_fmi2_guarded_init
  //  , ptr_fmi2_guarded_acquire
  //  , ptr_fmi2_guarded_get_alloc
  //  , ptr_fmi2_guarded_get_free
  //  , ptr_fmi2_guarded_release );

  fmi2_guarded_init();
  fmi2_guarded_clear();
}

MU_TEST_SUITE(test_use_shared_lib_suite)
{
	MU_SUITE_CONFIGURE(&test_shared_lib_init, &test_shared_lib_teardown);


	//MU_RUN_TEST(test_shared_lib_load);
	MU_RUN_TEST(test_shared_lib_use);
}

int main()
{
  MU_RUN_SUITE(test_use_shared_lib_suite);
  MU_REPORT();

  return 0;
}
