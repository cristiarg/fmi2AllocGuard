#include "../src/GuardedBookkeeping.h"
#include <stdlib.h>


void* fmi2_calloc1 ( size_t _num , size_t _size )
{
  static const int func_id = 1;
  void* p = calloc( _num , _size );
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc2 ( size_t _num , size_t _size )
{
  static const int func_id = 2;
  void* p = calloc( _num , _size );
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc3 ( size_t _num , size_t _size )
{
  static const int func_id = 3;
  void* p = calloc( _num , _size );
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc4 ( size_t _num , size_t _size )
{
  static const int func_id = 4;
  void* p = calloc( _num , _size );
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc5 ( size_t _num , size_t _size )
{
  static const int func_id = 5;
  void* p = calloc( _num , _size );
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}


void fmi2_free1 ( void* _ptr )
{
  static const int func_id = 1;
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free2 ( void* _ptr )
{
  static const int func_id = 2;
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free3 ( void* _ptr )
{
  static const int func_id = 3;
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free4 ( void* _ptr )
{
  static const int func_id = 4;
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free5 ( void* _ptr )
{
  static const int func_id = 5;
  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}


void fmi2_guarded_bookkeeping_init()
{
  for( int i = 0; i < FMI2_FUNC_INDEX_MIN ; i++ ) {
    fmi2_guarded_bookkeeping[ i ].id             = -1;
    fmi2_guarded_bookkeeping[ i ].calloc_p       = NULL;
    fmi2_guarded_bookkeeping[ i ].free_p         = NULL;
    fmi2_guarded_bookkeeping[ i ].pointer_keeper = NULL;
  }

  fmi2_guarded_bookkeeping[ 1 ].id              = 1;
  fmi2_guarded_bookkeeping[ 1 ].calloc_p        = &fmi2_calloc1;
  fmi2_guarded_bookkeeping[ 1 ].free_p          = &fmi2_free1;
  fmi2_guarded_bookkeeping[ 1 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 2 ].id              = 2;
  fmi2_guarded_bookkeeping[ 2 ].calloc_p        = &fmi2_calloc2;
  fmi2_guarded_bookkeeping[ 2 ].free_p          = &fmi2_free2;
  fmi2_guarded_bookkeeping[ 2 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 3 ].id              = 3;
  fmi2_guarded_bookkeeping[ 3 ].calloc_p        = &fmi2_calloc3;
  fmi2_guarded_bookkeeping[ 3 ].free_p          = &fmi2_free3;
  fmi2_guarded_bookkeeping[ 3 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 4 ].id              = 4;
  fmi2_guarded_bookkeeping[ 4 ].calloc_p        = &fmi2_calloc4;
  fmi2_guarded_bookkeeping[ 4 ].free_p          = &fmi2_free4;
  fmi2_guarded_bookkeeping[ 4 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 5 ].id              = 5;
  fmi2_guarded_bookkeeping[ 5 ].calloc_p        = &fmi2_calloc5;
  fmi2_guarded_bookkeeping[ 5 ].free_p          = &fmi2_free5;
  fmi2_guarded_bookkeeping[ 5 ].pointer_keeper  = NULL;
}

