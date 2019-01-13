void* fmi2_calloc1 ( size_t _num , size_t _size )
{
  static const int func_id = 1;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
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
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
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
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
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
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
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
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc6 ( size_t _num , size_t _size )
{
  static const int func_id = 6;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc7 ( size_t _num , size_t _size )
{
  static const int func_id = 7;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc8 ( size_t _num , size_t _size )
{
  static const int func_id = 8;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc9 ( size_t _num , size_t _size )
{
  static const int func_id = 9;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc10 ( size_t _num , size_t _size )
{
  static const int func_id = 10;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
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
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free2 ( void* _ptr )
{
  static const int func_id = 2;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free3 ( void* _ptr )
{
  static const int func_id = 3;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free4 ( void* _ptr )
{
  static const int func_id = 4;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free5 ( void* _ptr )
{
  static const int func_id = 5;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free6 ( void* _ptr )
{
  static const int func_id = 6;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free7 ( void* _ptr )
{
  static const int func_id = 7;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free8 ( void* _ptr )
{
  static const int func_id = 8;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free9 ( void* _ptr )
{
  static const int func_id = 9;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free10 ( void* _ptr )
{
  static const int func_id = 10;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

