void* fmi2_calloc1 ( size_t _num , size_t _size )
{
  static const int func_id = 1;
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, p, func_comp_lt);
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
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free2 ( void* _ptr )
{
  static const int func_id = 2;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free3 ( void* _ptr )
{
  static const int func_id = 3;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free4 ( void* _ptr )
{
  static const int func_id = 4;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free5 ( void* _ptr )
{
  static const int func_id = 5;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free6 ( void* _ptr )
{
  static const int func_id = 6;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free7 ( void* _ptr )
{
  static const int func_id = 7;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free8 ( void* _ptr )
{
  static const int func_id = 8;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free9 ( void* _ptr )
{
  static const int func_id = 9;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free10 ( void* _ptr )
{
  static const int func_id = 10;
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ func_id ].pointer_keeper, _ptr, func_comp_lt, func_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

