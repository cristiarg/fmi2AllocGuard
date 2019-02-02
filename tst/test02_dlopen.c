#include "minunit.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#include "fmi2AllocGuard.h"

#if defined(_WIN32)
# include <Windows.h>
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
# include <dlfcn.h>
#else
  // other platform .. not tested
#endif

//
// platform dependent types / functions
//

typedef
#if defined(_WIN32)
  HMODULE
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
  void*
#else
  void
#endif
  SYS_TYPE_LIBRARY_HANDLE;

//#if defined(_WIN32)
//#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
//#else
//#endif

/// param:
///   - _indication: a string to supply more context as to where the error
///       might have occured
/// return:
///   - 0 if OK
///   - non 0 otherwise
int sys_func_get_and_print_last_error(const char* const _indication)
{
#if defined(_WIN32)
  const DWORD err = GetLastError();
  if (err != 0) {
    LPVOID message_buffer = NULL;
    FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER
          | FORMAT_MESSAGE_FROM_SYSTEM
          | FORMAT_MESSAGE_IGNORE_INSERTS
        , NULL
        , err
        , MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)
        , (LPSTR)&message_buffer
        , 0
        , NULL);
    if (_indication != NULL) {
      fprintf(stderr, "error on '%s': %s\n", _indication, (LPCSTR)message_buffer);
    }
    else {
      fprintf(stderr, "%s\n", (LPCSTR)message_buffer);
    }
    LocalFree(message_buffer);
    return err;
  }
  else {
    fprintf(stderr, "there seems to have been an error on '%s' but GetLastError did not return a viable error code\n", _indication);
    fprintf(stderr, "NOTE: this might also mean incorrect usage on part of the programmer\n");
  }
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
  const char* const err = dlerror();
  if (err != NULL) {
    fprintf(stderr, "error on '%s': %s\n", _indication, err);
    return -1;
  }
  else {
    fprintf(stderr, "there seems to have been an error on '%s' but dlerror did not return a viable message\n", _indication);
    fprintf(stderr, "NOTE: this might also mean incorrect usage on part of the programmer\n");
    return -1;
  }
#else
  // ..
#endif
  return 0;
}

/// load a shared library
/// after the load call, if an error is reported, it is investigated
/// and reported to the console
SYS_TYPE_LIBRARY_HANDLE sys_func_load_library()
{
  SYS_TYPE_LIBRARY_HANDLE lib_handle =
#if defined(_WIN32)
      LoadLibrary("fmi2AllocGuard.dll")
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
      dlopen("./libfmi2AllocGuard.so", RTLD_LAZY)
#else
  // other platform .. not tested
      NULL
#endif
  ;
  if (lib_handle == NULL) {
    const int err_res = sys_func_get_and_print_last_error("LoadLibrary");
    if (err_res != 0) {
      return NULL;
    }
  }
  return lib_handle;
}

void sys_func_unload_library(const SYS_TYPE_LIBRARY_HANDLE _handle)
{
  if ( _handle != NULL ) {
#if defined(_WIN32)
    const BOOL free_res = FreeLibrary( _handle );
    if (!free_res) {
      sys_func_get_and_print_last_error("FreeLibrary");
    }
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
    dlclose( _handle );
#else
    // ..
#endif
  }
}

typedef void (*untyped_function_pointer_t)(void);

untyped_function_pointer_t sys_func_find_symbol(const SYS_TYPE_LIBRARY_HANDLE _handle, const char* const _symbol_name)
{
  untyped_function_pointer_t symbol_ptr =
#if defined(_WIN32)
      ( untyped_function_pointer_t )GetProcAddress(_handle, _symbol_name)
        // client code should convert to the appropriate function pointer
#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
      dlsym(_handle, _symbol_name)
#else
    // ..
#endif
  ;
  if (symbol_ptr == NULL) {
    sys_func_get_and_print_last_error("GetProcAddress|dlsym");
  }
  return symbol_ptr;
}

//
//
//

SYS_TYPE_LIBRARY_HANDLE fmi2_lib_handle = NULL;

// prototypes in the library header
typedef void                  ( *fmi2_guarded_init_t      )(           );
typedef int                   ( *fmi2_guarded_acquire_t   )(           );
typedef fmi2_guarded_alloc_t  ( *fmi2_guarded_get_alloc_t )( const int );
typedef fmi2_guarded_free_t   ( *fmi2_guarded_get_free_t  )( const int );
typedef int                   ( *fmi2_guarded_release_t   )( const int );

fmi2_guarded_init_t       ptr_fmi2_guarded_init       = NULL;
fmi2_guarded_acquire_t    ptr_fmi2_guarded_acquire    = NULL;
fmi2_guarded_get_alloc_t  ptr_fmi2_guarded_get_alloc  = NULL;
fmi2_guarded_get_free_t   ptr_fmi2_guarded_get_free   = NULL;
fmi2_guarded_release_t    ptr_fmi2_guarded_release    = NULL;

//void ( *ptr_fmi2_guarded_init )() = NULL;
//int ( *ptr_fmi2_guarded_acquire )() = NULL;
//fmi2_guarded_alloc_t ( *ptr_fmi2_guarded_get_alloc )( const int ) = NULL;
//fmi2_guarded_free_t ( *ptr_fmi2_guarded_get_free )( const int ) = NULL;
//int ( *ptr_fmi2_guarded_release )( const int ) = NULL;

void test_shared_lib_init(void)
{
  //srand( (unsigned)time(0) );
}

void test_shared_lib_teardown(void)
{
  // nop ..
  // .. cannot unload library as this is called after each test
  // the unloading of the library happens after the entire suite is done
}

MU_TEST(test_shared_lib_load)
{
  //int last_error = 0;
  //char* err = NULL;
//#if defined(_WIN32)
//  // nothing needed
//#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
//  dlerror(); // cleanup possible previous error
//#else
//  // ..
//#endif

  /*void **/
  fmi2_lib_handle =
//#if defined(_WIN32)
//      LoadLibrary("fmi2AllocGuard.dll");
//#elif defined(__linux__) || defined(__linux) || defined(__gnu_linux)
//      dlopen("./libfmi2AllocGuard.so", RTLD_LAZY)
//#else
//  // other platform .. not tested
//      NULL
//#endif
  sys_func_load_library();
  //last_error = sys_func_get_and_print_last_error(NULL);
  //mu_check(last_error == 0);
  mu_check(fmi2_lib_handle != NULL);
  //if (last_error != 0) {
  //  return;
  //}
  if (fmi2_lib_handle != NULL) {
  }
  //err = dlerror();
  //mu_check(err == NULL);
  //if (err != NULL) {
  //  fprintf(stderr, "dlopen failed: %s\n", err);
  //  return;
  //}

  printf("== fmi2_guarded_init\n");
  //*(void**)(&ptr_fmi2_guarded_init) = dlsym( fmi2_lib_handle , "fmi2_guarded_init" );
  //*(void**)(&ptr_fmi2_guarded_init) = sys_func_find_symbol(fmi2_lib_handle, "fmi2_guarded_init");
  ptr_fmi2_guarded_init = ( fmi2_guarded_init_t )sys_func_find_symbol(fmi2_lib_handle, "fmi2_guarded_init");
  //err = dlerror();
  mu_check(ptr_fmi2_guarded_init != NULL);
  //mu_check(err == NULL);
  //if (err != NULL) {
  //  fprintf(stderr, "fmi2_guarded_init NOT FOUND: %s\n", err);
  //  return;
  //}

  printf("== fmi2_guarded_acquire\n");
  //*(void**)(&ptr_fmi2_guarded_acquire) = dlsym( fmi2_lib_handle , "fmi2_guarded_acquire" );
  ptr_fmi2_guarded_acquire = ( fmi2_guarded_acquire_t )sys_func_find_symbol( fmi2_lib_handle , "fmi2_guarded_acquire" );
  //err = dlerror();
  mu_check(ptr_fmi2_guarded_acquire != NULL);
  //mu_check(err == NULL);
  //if (err != NULL ) {
  //  fprintf(stderr, "fmi2_guarded_acquire NOT FOUND: %s\n", err);
  //  return;
  //}

  printf("== fmi2_guarded_get_alloc\n");
  //*(void**)(&ptr_fmi2_guarded_get_alloc) = dlsym( fmi2_lib_handle , "fmi2_guarded_get_alloc");
  ptr_fmi2_guarded_get_alloc = ( fmi2_guarded_get_alloc_t )sys_func_find_symbol( fmi2_lib_handle , "fmi2_guarded_get_alloc");
  //err = dlerror();
  mu_check(ptr_fmi2_guarded_get_alloc != NULL);
  //mu_check(err == NULL);
  //if (err != NULL ) {
  //  fprintf(stderr, "fmi2_guarded_get_alloc NOT FOUND: %s\n", err);
  //  return;
  //}

  printf("== fmi2_guarded_get_free\n");
  //*(void**)(&ptr_fmi2_guarded_get_free) = dlsym( fmi2_lib_handle , "fmi2_guarded_get_free");
  ptr_fmi2_guarded_get_free = ( fmi2_guarded_get_free_t )sys_func_find_symbol( fmi2_lib_handle , "fmi2_guarded_get_free");
  //err = dlerror();
  mu_check(ptr_fmi2_guarded_get_free != NULL);
  //mu_check(err == NULL);
  //if (err != NULL) {
  //  fprintf(stderr, "fmi2_guarded_get_free NOT FOUND: %s\n", err);
  //  return;
  //}

  printf("== fmi2_guarded_release\n");
  //*(void**)(&ptr_fmi2_guarded_release) = dlsym( fmi2_lib_handle , "fmi2_guarded_release");
  ptr_fmi2_guarded_release = ( fmi2_guarded_release_t )sys_func_find_symbol( fmi2_lib_handle , "fmi2_guarded_release");
  //err = dlerror();
  mu_check(ptr_fmi2_guarded_release != NULL);
  //mu_check(err == NULL);
  //if (err != NULL) {
  //  fprintf(stderr, "fmi2_guarded_release NOT FOUND: %s\n", err);
  //  return;
  //}
}


void unload_library()
{
  if ( fmi2_lib_handle != NULL ) {
    sys_func_unload_library(fmi2_lib_handle);
    fmi2_lib_handle = NULL;
  }
}

void test_one(
      const int _id
    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free )
{
  fmi2_guarded_alloc_t pAlloc = _ptr_fmi2_guarded_get_alloc( _id );
  mu_check( pAlloc != NULL );

  fmi2_guarded_free_t pFree = _ptr_fmi2_guarded_get_free( _id );
  mu_check( pFree != NULL );

  void* p1 = pAlloc( 1 , sizeof( long ) );
  mu_check( p1 != NULL );
  void* p2 = ( *pAlloc )( 1 , sizeof( long ) );
  mu_check( p2 != NULL );

  pFree( p1 );
  pFree( p2 );

  // make some alloc's and leave them to be unallocated upon release
  for (int i = 0 ; i < 420 ; ++i ) {
    void* p3 = ( *pAlloc )( 10 , sizeof( double ) );
    mu_check( p3 != NULL );
  }
}

void test_recursive(
      fmi2_guarded_acquire_t    _ptr_fmi2_guarded_acquire
    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free
    , fmi2_guarded_release_t    _ptr_fmi2_guarded_release
    , bool*                     _reachedInvalid
    , int*                      _count )
{
  const int id = _ptr_fmi2_guarded_acquire();
  if ( id != FMI2_FUNC_INDEX_INVALID ) {
    *_count += 1;

    test_one( id, _ptr_fmi2_guarded_get_alloc, _ptr_fmi2_guarded_get_free );

    test_recursive(
          _ptr_fmi2_guarded_acquire
        , _ptr_fmi2_guarded_get_alloc
        , _ptr_fmi2_guarded_get_free
        , _ptr_fmi2_guarded_release
        , _reachedInvalid
        , _count );

    const int released_count = _ptr_fmi2_guarded_release(id);
    mu_check(released_count == 420);

  } else {
    *_reachedInvalid = true;
  }
}

//void test_start(
//      fmi2_guarded_init_t       _ptr_fmi2_guarded_init
//    , fmi2_guarded_acquire_t    _ptr_fmi2_guarded_acquire
//    , fmi2_guarded_get_alloc_t  _ptr_fmi2_guarded_get_alloc
//    , fmi2_guarded_get_free_t   _ptr_fmi2_guarded_get_free
//    , fmi2_guarded_release_t    _ptr_fmi2_guarded_release )
//{
//
//}

MU_TEST(test_shared_lib_use)
{
  ( *ptr_fmi2_guarded_init)();

  bool reachedInvalid = false;
  int count = 0;
  test_recursive(
        ptr_fmi2_guarded_acquire
      , ptr_fmi2_guarded_get_alloc
      , ptr_fmi2_guarded_get_free
      , ptr_fmi2_guarded_release
      , &reachedInvalid
      , &count );
  mu_check( count == ( FMI2_FUNC_INDEX_MAX - FMI2_FUNC_INDEX_MIN + 1 ) );
  mu_check( reachedInvalid );

  //test_start(
  //    ptr_fmi2_guarded_init
  //  , ptr_fmi2_guarded_acquire
  //  , ptr_fmi2_guarded_get_alloc
  //  , ptr_fmi2_guarded_get_free
  //  , ptr_fmi2_guarded_release );
}

MU_TEST_SUITE(test_shared_lib_suite)
{
	MU_SUITE_CONFIGURE(&test_shared_lib_init, &test_shared_lib_teardown);

	MU_RUN_TEST(test_shared_lib_load);
	MU_RUN_TEST(test_shared_lib_use);

  unload_library();
}

int main()
{
  MU_RUN_SUITE(test_shared_lib_suite);
  MU_REPORT();

  return 0;
}
