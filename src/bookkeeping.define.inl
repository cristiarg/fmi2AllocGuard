void* fmi2_calloc1 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 1 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc2 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 2 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc3 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 3 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc4 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 4 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc5 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 5 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc6 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 6 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc7 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 7 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc8 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 8 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc9 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 9 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void* fmi2_calloc10 ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ 10 ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

void fmi2_free1 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 1 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free2 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 2 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free3 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 3 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free4 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 4 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free5 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 5 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free6 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 6 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free7 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 7 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free8 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 8 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free9 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 9 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free10 ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ 10 ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

