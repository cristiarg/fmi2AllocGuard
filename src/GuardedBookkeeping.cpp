#include "../src/GuardedBookkeeping.hpp"
#include <stdlib.h>


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

void* fmi2_calloc11 ( size_t _num , size_t _size )
{
  static const int func_id = 11;
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

void* fmi2_calloc12 ( size_t _num , size_t _size )
{
  static const int func_id = 12;
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

void* fmi2_calloc13 ( size_t _num , size_t _size )
{
  static const int func_id = 13;
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

void* fmi2_calloc14 ( size_t _num , size_t _size )
{
  static const int func_id = 14;
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

void* fmi2_calloc15 ( size_t _num , size_t _size )
{
  static const int func_id = 15;
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

void* fmi2_calloc16 ( size_t _num , size_t _size )
{
  static const int func_id = 16;
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

void* fmi2_calloc17 ( size_t _num , size_t _size )
{
  static const int func_id = 17;
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

void* fmi2_calloc18 ( size_t _num , size_t _size )
{
  static const int func_id = 18;
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

void* fmi2_calloc19 ( size_t _num , size_t _size )
{
  static const int func_id = 19;
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

void* fmi2_calloc20 ( size_t _num , size_t _size )
{
  static const int func_id = 20;
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

void* fmi2_calloc21 ( size_t _num , size_t _size )
{
  static const int func_id = 21;
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

void* fmi2_calloc22 ( size_t _num , size_t _size )
{
  static const int func_id = 22;
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

void* fmi2_calloc23 ( size_t _num , size_t _size )
{
  static const int func_id = 23;
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

void* fmi2_calloc24 ( size_t _num , size_t _size )
{
  static const int func_id = 24;
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

void* fmi2_calloc25 ( size_t _num , size_t _size )
{
  static const int func_id = 25;
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

void* fmi2_calloc26 ( size_t _num , size_t _size )
{
  static const int func_id = 26;
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

void* fmi2_calloc27 ( size_t _num , size_t _size )
{
  static const int func_id = 27;
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

void* fmi2_calloc28 ( size_t _num , size_t _size )
{
  static const int func_id = 28;
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

void* fmi2_calloc29 ( size_t _num , size_t _size )
{
  static const int func_id = 29;
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

void* fmi2_calloc30 ( size_t _num , size_t _size )
{
  static const int func_id = 30;
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

void* fmi2_calloc31 ( size_t _num , size_t _size )
{
  static const int func_id = 31;
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

void* fmi2_calloc32 ( size_t _num , size_t _size )
{
  static const int func_id = 32;
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

void* fmi2_calloc33 ( size_t _num , size_t _size )
{
  static const int func_id = 33;
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

void* fmi2_calloc34 ( size_t _num , size_t _size )
{
  static const int func_id = 34;
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

void* fmi2_calloc35 ( size_t _num , size_t _size )
{
  static const int func_id = 35;
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

void* fmi2_calloc36 ( size_t _num , size_t _size )
{
  static const int func_id = 36;
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

void* fmi2_calloc37 ( size_t _num , size_t _size )
{
  static const int func_id = 37;
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

void* fmi2_calloc38 ( size_t _num , size_t _size )
{
  static const int func_id = 38;
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

void* fmi2_calloc39 ( size_t _num , size_t _size )
{
  static const int func_id = 39;
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

void* fmi2_calloc40 ( size_t _num , size_t _size )
{
  static const int func_id = 40;
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

void* fmi2_calloc41 ( size_t _num , size_t _size )
{
  static const int func_id = 41;
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

void* fmi2_calloc42 ( size_t _num , size_t _size )
{
  static const int func_id = 42;
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

void* fmi2_calloc43 ( size_t _num , size_t _size )
{
  static const int func_id = 43;
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

void* fmi2_calloc44 ( size_t _num , size_t _size )
{
  static const int func_id = 44;
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

void* fmi2_calloc45 ( size_t _num , size_t _size )
{
  static const int func_id = 45;
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

void* fmi2_calloc46 ( size_t _num , size_t _size )
{
  static const int func_id = 46;
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

void* fmi2_calloc47 ( size_t _num , size_t _size )
{
  static const int func_id = 47;
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

void* fmi2_calloc48 ( size_t _num , size_t _size )
{
  static const int func_id = 48;
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

void* fmi2_calloc49 ( size_t _num , size_t _size )
{
  static const int func_id = 49;
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

void* fmi2_calloc50 ( size_t _num , size_t _size )
{
  static const int func_id = 50;
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

void* fmi2_calloc51 ( size_t _num , size_t _size )
{
  static const int func_id = 51;
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

void* fmi2_calloc52 ( size_t _num , size_t _size )
{
  static const int func_id = 52;
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

void* fmi2_calloc53 ( size_t _num , size_t _size )
{
  static const int func_id = 53;
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

void* fmi2_calloc54 ( size_t _num , size_t _size )
{
  static const int func_id = 54;
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

void* fmi2_calloc55 ( size_t _num , size_t _size )
{
  static const int func_id = 55;
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

void* fmi2_calloc56 ( size_t _num , size_t _size )
{
  static const int func_id = 56;
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

void* fmi2_calloc57 ( size_t _num , size_t _size )
{
  static const int func_id = 57;
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

void* fmi2_calloc58 ( size_t _num , size_t _size )
{
  static const int func_id = 58;
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

void* fmi2_calloc59 ( size_t _num , size_t _size )
{
  static const int func_id = 59;
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

void* fmi2_calloc60 ( size_t _num , size_t _size )
{
  static const int func_id = 60;
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

void* fmi2_calloc61 ( size_t _num , size_t _size )
{
  static const int func_id = 61;
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

void* fmi2_calloc62 ( size_t _num , size_t _size )
{
  static const int func_id = 62;
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

void* fmi2_calloc63 ( size_t _num , size_t _size )
{
  static const int func_id = 63;
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

void* fmi2_calloc64 ( size_t _num , size_t _size )
{
  static const int func_id = 64;
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

void* fmi2_calloc65 ( size_t _num , size_t _size )
{
  static const int func_id = 65;
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

void* fmi2_calloc66 ( size_t _num , size_t _size )
{
  static const int func_id = 66;
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

void* fmi2_calloc67 ( size_t _num , size_t _size )
{
  static const int func_id = 67;
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

void* fmi2_calloc68 ( size_t _num , size_t _size )
{
  static const int func_id = 68;
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

void* fmi2_calloc69 ( size_t _num , size_t _size )
{
  static const int func_id = 69;
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

void* fmi2_calloc70 ( size_t _num , size_t _size )
{
  static const int func_id = 70;
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

void* fmi2_calloc71 ( size_t _num , size_t _size )
{
  static const int func_id = 71;
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

void* fmi2_calloc72 ( size_t _num , size_t _size )
{
  static const int func_id = 72;
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

void* fmi2_calloc73 ( size_t _num , size_t _size )
{
  static const int func_id = 73;
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

void* fmi2_calloc74 ( size_t _num , size_t _size )
{
  static const int func_id = 74;
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

void* fmi2_calloc75 ( size_t _num , size_t _size )
{
  static const int func_id = 75;
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

void* fmi2_calloc76 ( size_t _num , size_t _size )
{
  static const int func_id = 76;
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

void* fmi2_calloc77 ( size_t _num , size_t _size )
{
  static const int func_id = 77;
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

void* fmi2_calloc78 ( size_t _num , size_t _size )
{
  static const int func_id = 78;
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

void* fmi2_calloc79 ( size_t _num , size_t _size )
{
  static const int func_id = 79;
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

void* fmi2_calloc80 ( size_t _num , size_t _size )
{
  static const int func_id = 80;
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

void* fmi2_calloc81 ( size_t _num , size_t _size )
{
  static const int func_id = 81;
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

void* fmi2_calloc82 ( size_t _num , size_t _size )
{
  static const int func_id = 82;
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

void* fmi2_calloc83 ( size_t _num , size_t _size )
{
  static const int func_id = 83;
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

void* fmi2_calloc84 ( size_t _num , size_t _size )
{
  static const int func_id = 84;
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

void* fmi2_calloc85 ( size_t _num , size_t _size )
{
  static const int func_id = 85;
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

void* fmi2_calloc86 ( size_t _num , size_t _size )
{
  static const int func_id = 86;
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

void* fmi2_calloc87 ( size_t _num , size_t _size )
{
  static const int func_id = 87;
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

void* fmi2_calloc88 ( size_t _num , size_t _size )
{
  static const int func_id = 88;
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

void* fmi2_calloc89 ( size_t _num , size_t _size )
{
  static const int func_id = 89;
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

void* fmi2_calloc90 ( size_t _num , size_t _size )
{
  static const int func_id = 90;
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

void* fmi2_calloc91 ( size_t _num , size_t _size )
{
  static const int func_id = 91;
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

void* fmi2_calloc92 ( size_t _num , size_t _size )
{
  static const int func_id = 92;
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

void* fmi2_calloc93 ( size_t _num , size_t _size )
{
  static const int func_id = 93;
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

void* fmi2_calloc94 ( size_t _num , size_t _size )
{
  static const int func_id = 94;
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

void* fmi2_calloc95 ( size_t _num , size_t _size )
{
  static const int func_id = 95;
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

void* fmi2_calloc96 ( size_t _num , size_t _size )
{
  static const int func_id = 96;
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

void* fmi2_calloc97 ( size_t _num , size_t _size )
{
  static const int func_id = 97;
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

void* fmi2_calloc98 ( size_t _num , size_t _size )
{
  static const int func_id = 98;
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

void* fmi2_calloc99 ( size_t _num , size_t _size )
{
  static const int func_id = 99;
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

void* fmi2_calloc100 ( size_t _num , size_t _size )
{
  static const int func_id = 100;
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

void fmi2_free11 ( void* _ptr )
{
  static const int func_id = 11;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free12 ( void* _ptr )
{
  static const int func_id = 12;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free13 ( void* _ptr )
{
  static const int func_id = 13;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free14 ( void* _ptr )
{
  static const int func_id = 14;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free15 ( void* _ptr )
{
  static const int func_id = 15;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free16 ( void* _ptr )
{
  static const int func_id = 16;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free17 ( void* _ptr )
{
  static const int func_id = 17;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free18 ( void* _ptr )
{
  static const int func_id = 18;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free19 ( void* _ptr )
{
  static const int func_id = 19;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free20 ( void* _ptr )
{
  static const int func_id = 20;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free21 ( void* _ptr )
{
  static const int func_id = 21;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free22 ( void* _ptr )
{
  static const int func_id = 22;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free23 ( void* _ptr )
{
  static const int func_id = 23;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free24 ( void* _ptr )
{
  static const int func_id = 24;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free25 ( void* _ptr )
{
  static const int func_id = 25;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free26 ( void* _ptr )
{
  static const int func_id = 26;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free27 ( void* _ptr )
{
  static const int func_id = 27;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free28 ( void* _ptr )
{
  static const int func_id = 28;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free29 ( void* _ptr )
{
  static const int func_id = 29;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free30 ( void* _ptr )
{
  static const int func_id = 30;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free31 ( void* _ptr )
{
  static const int func_id = 31;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free32 ( void* _ptr )
{
  static const int func_id = 32;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free33 ( void* _ptr )
{
  static const int func_id = 33;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free34 ( void* _ptr )
{
  static const int func_id = 34;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free35 ( void* _ptr )
{
  static const int func_id = 35;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free36 ( void* _ptr )
{
  static const int func_id = 36;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free37 ( void* _ptr )
{
  static const int func_id = 37;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free38 ( void* _ptr )
{
  static const int func_id = 38;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free39 ( void* _ptr )
{
  static const int func_id = 39;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free40 ( void* _ptr )
{
  static const int func_id = 40;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free41 ( void* _ptr )
{
  static const int func_id = 41;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free42 ( void* _ptr )
{
  static const int func_id = 42;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free43 ( void* _ptr )
{
  static const int func_id = 43;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free44 ( void* _ptr )
{
  static const int func_id = 44;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free45 ( void* _ptr )
{
  static const int func_id = 45;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free46 ( void* _ptr )
{
  static const int func_id = 46;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free47 ( void* _ptr )
{
  static const int func_id = 47;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free48 ( void* _ptr )
{
  static const int func_id = 48;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free49 ( void* _ptr )
{
  static const int func_id = 49;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free50 ( void* _ptr )
{
  static const int func_id = 50;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free51 ( void* _ptr )
{
  static const int func_id = 51;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free52 ( void* _ptr )
{
  static const int func_id = 52;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free53 ( void* _ptr )
{
  static const int func_id = 53;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free54 ( void* _ptr )
{
  static const int func_id = 54;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free55 ( void* _ptr )
{
  static const int func_id = 55;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free56 ( void* _ptr )
{
  static const int func_id = 56;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free57 ( void* _ptr )
{
  static const int func_id = 57;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free58 ( void* _ptr )
{
  static const int func_id = 58;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free59 ( void* _ptr )
{
  static const int func_id = 59;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free60 ( void* _ptr )
{
  static const int func_id = 60;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free61 ( void* _ptr )
{
  static const int func_id = 61;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free62 ( void* _ptr )
{
  static const int func_id = 62;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free63 ( void* _ptr )
{
  static const int func_id = 63;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free64 ( void* _ptr )
{
  static const int func_id = 64;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free65 ( void* _ptr )
{
  static const int func_id = 65;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free66 ( void* _ptr )
{
  static const int func_id = 66;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free67 ( void* _ptr )
{
  static const int func_id = 67;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free68 ( void* _ptr )
{
  static const int func_id = 68;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free69 ( void* _ptr )
{
  static const int func_id = 69;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free70 ( void* _ptr )
{
  static const int func_id = 70;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free71 ( void* _ptr )
{
  static const int func_id = 71;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free72 ( void* _ptr )
{
  static const int func_id = 72;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free73 ( void* _ptr )
{
  static const int func_id = 73;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free74 ( void* _ptr )
{
  static const int func_id = 74;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free75 ( void* _ptr )
{
  static const int func_id = 75;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free76 ( void* _ptr )
{
  static const int func_id = 76;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free77 ( void* _ptr )
{
  static const int func_id = 77;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free78 ( void* _ptr )
{
  static const int func_id = 78;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free79 ( void* _ptr )
{
  static const int func_id = 79;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free80 ( void* _ptr )
{
  static const int func_id = 80;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free81 ( void* _ptr )
{
  static const int func_id = 81;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free82 ( void* _ptr )
{
  static const int func_id = 82;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free83 ( void* _ptr )
{
  static const int func_id = 83;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free84 ( void* _ptr )
{
  static const int func_id = 84;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free85 ( void* _ptr )
{
  static const int func_id = 85;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free86 ( void* _ptr )
{
  static const int func_id = 86;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free87 ( void* _ptr )
{
  static const int func_id = 87;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free88 ( void* _ptr )
{
  static const int func_id = 88;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free89 ( void* _ptr )
{
  static const int func_id = 89;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free90 ( void* _ptr )
{
  static const int func_id = 90;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free91 ( void* _ptr )
{
  static const int func_id = 91;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free92 ( void* _ptr )
{
  static const int func_id = 92;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free93 ( void* _ptr )
{
  static const int func_id = 93;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free94 ( void* _ptr )
{
  static const int func_id = 94;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free95 ( void* _ptr )
{
  static const int func_id = 95;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free96 ( void* _ptr )
{
  static const int func_id = 96;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free97 ( void* _ptr )
{
  static const int func_id = 97;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free98 ( void* _ptr )
{
  static const int func_id = 98;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free99 ( void* _ptr )
{
  static const int func_id = 99;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

void fmi2_free100 ( void* _ptr )
{
  static const int func_id = 100;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ]
    = {   0
        , NULL
        , NULL
        , NULL };

void fmi2_guarded_bookkeeping_init()
{
  for( int idx_clean = 0 ; idx_clean <= FMI2_FUNC_INDEX_MAX ; ++idx_clean ) {
    fmi2_guarded_bookkeeping[ idx_clean ].id        = -1;
    fmi2_guarded_bookkeeping[ idx_clean ].calloc_p  = NULL;
    fmi2_guarded_bookkeeping[ idx_clean ].free_p    = NULL;
    if( fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper != NULL ) {
      delete fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper;
      fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper = NULL;
    }
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

  fmi2_guarded_bookkeeping[ 6 ].id              = 6;
  fmi2_guarded_bookkeeping[ 6 ].calloc_p        = &fmi2_calloc6;
  fmi2_guarded_bookkeeping[ 6 ].free_p          = &fmi2_free6;
  fmi2_guarded_bookkeeping[ 6 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 7 ].id              = 7;
  fmi2_guarded_bookkeeping[ 7 ].calloc_p        = &fmi2_calloc7;
  fmi2_guarded_bookkeeping[ 7 ].free_p          = &fmi2_free7;
  fmi2_guarded_bookkeeping[ 7 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 8 ].id              = 8;
  fmi2_guarded_bookkeeping[ 8 ].calloc_p        = &fmi2_calloc8;
  fmi2_guarded_bookkeeping[ 8 ].free_p          = &fmi2_free8;
  fmi2_guarded_bookkeeping[ 8 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 9 ].id              = 9;
  fmi2_guarded_bookkeeping[ 9 ].calloc_p        = &fmi2_calloc9;
  fmi2_guarded_bookkeeping[ 9 ].free_p          = &fmi2_free9;
  fmi2_guarded_bookkeeping[ 9 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 10 ].id              = 10;
  fmi2_guarded_bookkeeping[ 10 ].calloc_p        = &fmi2_calloc10;
  fmi2_guarded_bookkeeping[ 10 ].free_p          = &fmi2_free10;
  fmi2_guarded_bookkeeping[ 10 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 11 ].id              = 11;
  fmi2_guarded_bookkeeping[ 11 ].calloc_p        = &fmi2_calloc11;
  fmi2_guarded_bookkeeping[ 11 ].free_p          = &fmi2_free11;
  fmi2_guarded_bookkeeping[ 11 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 12 ].id              = 12;
  fmi2_guarded_bookkeeping[ 12 ].calloc_p        = &fmi2_calloc12;
  fmi2_guarded_bookkeeping[ 12 ].free_p          = &fmi2_free12;
  fmi2_guarded_bookkeeping[ 12 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 13 ].id              = 13;
  fmi2_guarded_bookkeeping[ 13 ].calloc_p        = &fmi2_calloc13;
  fmi2_guarded_bookkeeping[ 13 ].free_p          = &fmi2_free13;
  fmi2_guarded_bookkeeping[ 13 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 14 ].id              = 14;
  fmi2_guarded_bookkeeping[ 14 ].calloc_p        = &fmi2_calloc14;
  fmi2_guarded_bookkeeping[ 14 ].free_p          = &fmi2_free14;
  fmi2_guarded_bookkeeping[ 14 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 15 ].id              = 15;
  fmi2_guarded_bookkeeping[ 15 ].calloc_p        = &fmi2_calloc15;
  fmi2_guarded_bookkeeping[ 15 ].free_p          = &fmi2_free15;
  fmi2_guarded_bookkeeping[ 15 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 16 ].id              = 16;
  fmi2_guarded_bookkeeping[ 16 ].calloc_p        = &fmi2_calloc16;
  fmi2_guarded_bookkeeping[ 16 ].free_p          = &fmi2_free16;
  fmi2_guarded_bookkeeping[ 16 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 17 ].id              = 17;
  fmi2_guarded_bookkeeping[ 17 ].calloc_p        = &fmi2_calloc17;
  fmi2_guarded_bookkeeping[ 17 ].free_p          = &fmi2_free17;
  fmi2_guarded_bookkeeping[ 17 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 18 ].id              = 18;
  fmi2_guarded_bookkeeping[ 18 ].calloc_p        = &fmi2_calloc18;
  fmi2_guarded_bookkeeping[ 18 ].free_p          = &fmi2_free18;
  fmi2_guarded_bookkeeping[ 18 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 19 ].id              = 19;
  fmi2_guarded_bookkeeping[ 19 ].calloc_p        = &fmi2_calloc19;
  fmi2_guarded_bookkeeping[ 19 ].free_p          = &fmi2_free19;
  fmi2_guarded_bookkeeping[ 19 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 20 ].id              = 20;
  fmi2_guarded_bookkeeping[ 20 ].calloc_p        = &fmi2_calloc20;
  fmi2_guarded_bookkeeping[ 20 ].free_p          = &fmi2_free20;
  fmi2_guarded_bookkeeping[ 20 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 21 ].id              = 21;
  fmi2_guarded_bookkeeping[ 21 ].calloc_p        = &fmi2_calloc21;
  fmi2_guarded_bookkeeping[ 21 ].free_p          = &fmi2_free21;
  fmi2_guarded_bookkeeping[ 21 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 22 ].id              = 22;
  fmi2_guarded_bookkeeping[ 22 ].calloc_p        = &fmi2_calloc22;
  fmi2_guarded_bookkeeping[ 22 ].free_p          = &fmi2_free22;
  fmi2_guarded_bookkeeping[ 22 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 23 ].id              = 23;
  fmi2_guarded_bookkeeping[ 23 ].calloc_p        = &fmi2_calloc23;
  fmi2_guarded_bookkeeping[ 23 ].free_p          = &fmi2_free23;
  fmi2_guarded_bookkeeping[ 23 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 24 ].id              = 24;
  fmi2_guarded_bookkeeping[ 24 ].calloc_p        = &fmi2_calloc24;
  fmi2_guarded_bookkeeping[ 24 ].free_p          = &fmi2_free24;
  fmi2_guarded_bookkeeping[ 24 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 25 ].id              = 25;
  fmi2_guarded_bookkeeping[ 25 ].calloc_p        = &fmi2_calloc25;
  fmi2_guarded_bookkeeping[ 25 ].free_p          = &fmi2_free25;
  fmi2_guarded_bookkeeping[ 25 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 26 ].id              = 26;
  fmi2_guarded_bookkeeping[ 26 ].calloc_p        = &fmi2_calloc26;
  fmi2_guarded_bookkeeping[ 26 ].free_p          = &fmi2_free26;
  fmi2_guarded_bookkeeping[ 26 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 27 ].id              = 27;
  fmi2_guarded_bookkeeping[ 27 ].calloc_p        = &fmi2_calloc27;
  fmi2_guarded_bookkeeping[ 27 ].free_p          = &fmi2_free27;
  fmi2_guarded_bookkeeping[ 27 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 28 ].id              = 28;
  fmi2_guarded_bookkeeping[ 28 ].calloc_p        = &fmi2_calloc28;
  fmi2_guarded_bookkeeping[ 28 ].free_p          = &fmi2_free28;
  fmi2_guarded_bookkeeping[ 28 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 29 ].id              = 29;
  fmi2_guarded_bookkeeping[ 29 ].calloc_p        = &fmi2_calloc29;
  fmi2_guarded_bookkeeping[ 29 ].free_p          = &fmi2_free29;
  fmi2_guarded_bookkeeping[ 29 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 30 ].id              = 30;
  fmi2_guarded_bookkeeping[ 30 ].calloc_p        = &fmi2_calloc30;
  fmi2_guarded_bookkeeping[ 30 ].free_p          = &fmi2_free30;
  fmi2_guarded_bookkeeping[ 30 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 31 ].id              = 31;
  fmi2_guarded_bookkeeping[ 31 ].calloc_p        = &fmi2_calloc31;
  fmi2_guarded_bookkeeping[ 31 ].free_p          = &fmi2_free31;
  fmi2_guarded_bookkeeping[ 31 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 32 ].id              = 32;
  fmi2_guarded_bookkeeping[ 32 ].calloc_p        = &fmi2_calloc32;
  fmi2_guarded_bookkeeping[ 32 ].free_p          = &fmi2_free32;
  fmi2_guarded_bookkeeping[ 32 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 33 ].id              = 33;
  fmi2_guarded_bookkeeping[ 33 ].calloc_p        = &fmi2_calloc33;
  fmi2_guarded_bookkeeping[ 33 ].free_p          = &fmi2_free33;
  fmi2_guarded_bookkeeping[ 33 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 34 ].id              = 34;
  fmi2_guarded_bookkeeping[ 34 ].calloc_p        = &fmi2_calloc34;
  fmi2_guarded_bookkeeping[ 34 ].free_p          = &fmi2_free34;
  fmi2_guarded_bookkeeping[ 34 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 35 ].id              = 35;
  fmi2_guarded_bookkeeping[ 35 ].calloc_p        = &fmi2_calloc35;
  fmi2_guarded_bookkeeping[ 35 ].free_p          = &fmi2_free35;
  fmi2_guarded_bookkeeping[ 35 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 36 ].id              = 36;
  fmi2_guarded_bookkeeping[ 36 ].calloc_p        = &fmi2_calloc36;
  fmi2_guarded_bookkeeping[ 36 ].free_p          = &fmi2_free36;
  fmi2_guarded_bookkeeping[ 36 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 37 ].id              = 37;
  fmi2_guarded_bookkeeping[ 37 ].calloc_p        = &fmi2_calloc37;
  fmi2_guarded_bookkeeping[ 37 ].free_p          = &fmi2_free37;
  fmi2_guarded_bookkeeping[ 37 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 38 ].id              = 38;
  fmi2_guarded_bookkeeping[ 38 ].calloc_p        = &fmi2_calloc38;
  fmi2_guarded_bookkeeping[ 38 ].free_p          = &fmi2_free38;
  fmi2_guarded_bookkeeping[ 38 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 39 ].id              = 39;
  fmi2_guarded_bookkeeping[ 39 ].calloc_p        = &fmi2_calloc39;
  fmi2_guarded_bookkeeping[ 39 ].free_p          = &fmi2_free39;
  fmi2_guarded_bookkeeping[ 39 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 40 ].id              = 40;
  fmi2_guarded_bookkeeping[ 40 ].calloc_p        = &fmi2_calloc40;
  fmi2_guarded_bookkeeping[ 40 ].free_p          = &fmi2_free40;
  fmi2_guarded_bookkeeping[ 40 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 41 ].id              = 41;
  fmi2_guarded_bookkeeping[ 41 ].calloc_p        = &fmi2_calloc41;
  fmi2_guarded_bookkeeping[ 41 ].free_p          = &fmi2_free41;
  fmi2_guarded_bookkeeping[ 41 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 42 ].id              = 42;
  fmi2_guarded_bookkeeping[ 42 ].calloc_p        = &fmi2_calloc42;
  fmi2_guarded_bookkeeping[ 42 ].free_p          = &fmi2_free42;
  fmi2_guarded_bookkeeping[ 42 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 43 ].id              = 43;
  fmi2_guarded_bookkeeping[ 43 ].calloc_p        = &fmi2_calloc43;
  fmi2_guarded_bookkeeping[ 43 ].free_p          = &fmi2_free43;
  fmi2_guarded_bookkeeping[ 43 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 44 ].id              = 44;
  fmi2_guarded_bookkeeping[ 44 ].calloc_p        = &fmi2_calloc44;
  fmi2_guarded_bookkeeping[ 44 ].free_p          = &fmi2_free44;
  fmi2_guarded_bookkeeping[ 44 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 45 ].id              = 45;
  fmi2_guarded_bookkeeping[ 45 ].calloc_p        = &fmi2_calloc45;
  fmi2_guarded_bookkeeping[ 45 ].free_p          = &fmi2_free45;
  fmi2_guarded_bookkeeping[ 45 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 46 ].id              = 46;
  fmi2_guarded_bookkeeping[ 46 ].calloc_p        = &fmi2_calloc46;
  fmi2_guarded_bookkeeping[ 46 ].free_p          = &fmi2_free46;
  fmi2_guarded_bookkeeping[ 46 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 47 ].id              = 47;
  fmi2_guarded_bookkeeping[ 47 ].calloc_p        = &fmi2_calloc47;
  fmi2_guarded_bookkeeping[ 47 ].free_p          = &fmi2_free47;
  fmi2_guarded_bookkeeping[ 47 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 48 ].id              = 48;
  fmi2_guarded_bookkeeping[ 48 ].calloc_p        = &fmi2_calloc48;
  fmi2_guarded_bookkeeping[ 48 ].free_p          = &fmi2_free48;
  fmi2_guarded_bookkeeping[ 48 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 49 ].id              = 49;
  fmi2_guarded_bookkeeping[ 49 ].calloc_p        = &fmi2_calloc49;
  fmi2_guarded_bookkeeping[ 49 ].free_p          = &fmi2_free49;
  fmi2_guarded_bookkeeping[ 49 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 50 ].id              = 50;
  fmi2_guarded_bookkeeping[ 50 ].calloc_p        = &fmi2_calloc50;
  fmi2_guarded_bookkeeping[ 50 ].free_p          = &fmi2_free50;
  fmi2_guarded_bookkeeping[ 50 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 51 ].id              = 51;
  fmi2_guarded_bookkeeping[ 51 ].calloc_p        = &fmi2_calloc51;
  fmi2_guarded_bookkeeping[ 51 ].free_p          = &fmi2_free51;
  fmi2_guarded_bookkeeping[ 51 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 52 ].id              = 52;
  fmi2_guarded_bookkeeping[ 52 ].calloc_p        = &fmi2_calloc52;
  fmi2_guarded_bookkeeping[ 52 ].free_p          = &fmi2_free52;
  fmi2_guarded_bookkeeping[ 52 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 53 ].id              = 53;
  fmi2_guarded_bookkeeping[ 53 ].calloc_p        = &fmi2_calloc53;
  fmi2_guarded_bookkeeping[ 53 ].free_p          = &fmi2_free53;
  fmi2_guarded_bookkeeping[ 53 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 54 ].id              = 54;
  fmi2_guarded_bookkeeping[ 54 ].calloc_p        = &fmi2_calloc54;
  fmi2_guarded_bookkeeping[ 54 ].free_p          = &fmi2_free54;
  fmi2_guarded_bookkeeping[ 54 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 55 ].id              = 55;
  fmi2_guarded_bookkeeping[ 55 ].calloc_p        = &fmi2_calloc55;
  fmi2_guarded_bookkeeping[ 55 ].free_p          = &fmi2_free55;
  fmi2_guarded_bookkeeping[ 55 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 56 ].id              = 56;
  fmi2_guarded_bookkeeping[ 56 ].calloc_p        = &fmi2_calloc56;
  fmi2_guarded_bookkeeping[ 56 ].free_p          = &fmi2_free56;
  fmi2_guarded_bookkeeping[ 56 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 57 ].id              = 57;
  fmi2_guarded_bookkeeping[ 57 ].calloc_p        = &fmi2_calloc57;
  fmi2_guarded_bookkeeping[ 57 ].free_p          = &fmi2_free57;
  fmi2_guarded_bookkeeping[ 57 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 58 ].id              = 58;
  fmi2_guarded_bookkeeping[ 58 ].calloc_p        = &fmi2_calloc58;
  fmi2_guarded_bookkeeping[ 58 ].free_p          = &fmi2_free58;
  fmi2_guarded_bookkeeping[ 58 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 59 ].id              = 59;
  fmi2_guarded_bookkeeping[ 59 ].calloc_p        = &fmi2_calloc59;
  fmi2_guarded_bookkeeping[ 59 ].free_p          = &fmi2_free59;
  fmi2_guarded_bookkeeping[ 59 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 60 ].id              = 60;
  fmi2_guarded_bookkeeping[ 60 ].calloc_p        = &fmi2_calloc60;
  fmi2_guarded_bookkeeping[ 60 ].free_p          = &fmi2_free60;
  fmi2_guarded_bookkeeping[ 60 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 61 ].id              = 61;
  fmi2_guarded_bookkeeping[ 61 ].calloc_p        = &fmi2_calloc61;
  fmi2_guarded_bookkeeping[ 61 ].free_p          = &fmi2_free61;
  fmi2_guarded_bookkeeping[ 61 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 62 ].id              = 62;
  fmi2_guarded_bookkeeping[ 62 ].calloc_p        = &fmi2_calloc62;
  fmi2_guarded_bookkeeping[ 62 ].free_p          = &fmi2_free62;
  fmi2_guarded_bookkeeping[ 62 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 63 ].id              = 63;
  fmi2_guarded_bookkeeping[ 63 ].calloc_p        = &fmi2_calloc63;
  fmi2_guarded_bookkeeping[ 63 ].free_p          = &fmi2_free63;
  fmi2_guarded_bookkeeping[ 63 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 64 ].id              = 64;
  fmi2_guarded_bookkeeping[ 64 ].calloc_p        = &fmi2_calloc64;
  fmi2_guarded_bookkeeping[ 64 ].free_p          = &fmi2_free64;
  fmi2_guarded_bookkeeping[ 64 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 65 ].id              = 65;
  fmi2_guarded_bookkeeping[ 65 ].calloc_p        = &fmi2_calloc65;
  fmi2_guarded_bookkeeping[ 65 ].free_p          = &fmi2_free65;
  fmi2_guarded_bookkeeping[ 65 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 66 ].id              = 66;
  fmi2_guarded_bookkeeping[ 66 ].calloc_p        = &fmi2_calloc66;
  fmi2_guarded_bookkeeping[ 66 ].free_p          = &fmi2_free66;
  fmi2_guarded_bookkeeping[ 66 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 67 ].id              = 67;
  fmi2_guarded_bookkeeping[ 67 ].calloc_p        = &fmi2_calloc67;
  fmi2_guarded_bookkeeping[ 67 ].free_p          = &fmi2_free67;
  fmi2_guarded_bookkeeping[ 67 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 68 ].id              = 68;
  fmi2_guarded_bookkeeping[ 68 ].calloc_p        = &fmi2_calloc68;
  fmi2_guarded_bookkeeping[ 68 ].free_p          = &fmi2_free68;
  fmi2_guarded_bookkeeping[ 68 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 69 ].id              = 69;
  fmi2_guarded_bookkeeping[ 69 ].calloc_p        = &fmi2_calloc69;
  fmi2_guarded_bookkeeping[ 69 ].free_p          = &fmi2_free69;
  fmi2_guarded_bookkeeping[ 69 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 70 ].id              = 70;
  fmi2_guarded_bookkeeping[ 70 ].calloc_p        = &fmi2_calloc70;
  fmi2_guarded_bookkeeping[ 70 ].free_p          = &fmi2_free70;
  fmi2_guarded_bookkeeping[ 70 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 71 ].id              = 71;
  fmi2_guarded_bookkeeping[ 71 ].calloc_p        = &fmi2_calloc71;
  fmi2_guarded_bookkeeping[ 71 ].free_p          = &fmi2_free71;
  fmi2_guarded_bookkeeping[ 71 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 72 ].id              = 72;
  fmi2_guarded_bookkeeping[ 72 ].calloc_p        = &fmi2_calloc72;
  fmi2_guarded_bookkeeping[ 72 ].free_p          = &fmi2_free72;
  fmi2_guarded_bookkeeping[ 72 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 73 ].id              = 73;
  fmi2_guarded_bookkeeping[ 73 ].calloc_p        = &fmi2_calloc73;
  fmi2_guarded_bookkeeping[ 73 ].free_p          = &fmi2_free73;
  fmi2_guarded_bookkeeping[ 73 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 74 ].id              = 74;
  fmi2_guarded_bookkeeping[ 74 ].calloc_p        = &fmi2_calloc74;
  fmi2_guarded_bookkeeping[ 74 ].free_p          = &fmi2_free74;
  fmi2_guarded_bookkeeping[ 74 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 75 ].id              = 75;
  fmi2_guarded_bookkeeping[ 75 ].calloc_p        = &fmi2_calloc75;
  fmi2_guarded_bookkeeping[ 75 ].free_p          = &fmi2_free75;
  fmi2_guarded_bookkeeping[ 75 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 76 ].id              = 76;
  fmi2_guarded_bookkeeping[ 76 ].calloc_p        = &fmi2_calloc76;
  fmi2_guarded_bookkeeping[ 76 ].free_p          = &fmi2_free76;
  fmi2_guarded_bookkeeping[ 76 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 77 ].id              = 77;
  fmi2_guarded_bookkeeping[ 77 ].calloc_p        = &fmi2_calloc77;
  fmi2_guarded_bookkeeping[ 77 ].free_p          = &fmi2_free77;
  fmi2_guarded_bookkeeping[ 77 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 78 ].id              = 78;
  fmi2_guarded_bookkeeping[ 78 ].calloc_p        = &fmi2_calloc78;
  fmi2_guarded_bookkeeping[ 78 ].free_p          = &fmi2_free78;
  fmi2_guarded_bookkeeping[ 78 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 79 ].id              = 79;
  fmi2_guarded_bookkeeping[ 79 ].calloc_p        = &fmi2_calloc79;
  fmi2_guarded_bookkeeping[ 79 ].free_p          = &fmi2_free79;
  fmi2_guarded_bookkeeping[ 79 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 80 ].id              = 80;
  fmi2_guarded_bookkeeping[ 80 ].calloc_p        = &fmi2_calloc80;
  fmi2_guarded_bookkeeping[ 80 ].free_p          = &fmi2_free80;
  fmi2_guarded_bookkeeping[ 80 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 81 ].id              = 81;
  fmi2_guarded_bookkeeping[ 81 ].calloc_p        = &fmi2_calloc81;
  fmi2_guarded_bookkeeping[ 81 ].free_p          = &fmi2_free81;
  fmi2_guarded_bookkeeping[ 81 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 82 ].id              = 82;
  fmi2_guarded_bookkeeping[ 82 ].calloc_p        = &fmi2_calloc82;
  fmi2_guarded_bookkeeping[ 82 ].free_p          = &fmi2_free82;
  fmi2_guarded_bookkeeping[ 82 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 83 ].id              = 83;
  fmi2_guarded_bookkeeping[ 83 ].calloc_p        = &fmi2_calloc83;
  fmi2_guarded_bookkeeping[ 83 ].free_p          = &fmi2_free83;
  fmi2_guarded_bookkeeping[ 83 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 84 ].id              = 84;
  fmi2_guarded_bookkeeping[ 84 ].calloc_p        = &fmi2_calloc84;
  fmi2_guarded_bookkeeping[ 84 ].free_p          = &fmi2_free84;
  fmi2_guarded_bookkeeping[ 84 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 85 ].id              = 85;
  fmi2_guarded_bookkeeping[ 85 ].calloc_p        = &fmi2_calloc85;
  fmi2_guarded_bookkeeping[ 85 ].free_p          = &fmi2_free85;
  fmi2_guarded_bookkeeping[ 85 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 86 ].id              = 86;
  fmi2_guarded_bookkeeping[ 86 ].calloc_p        = &fmi2_calloc86;
  fmi2_guarded_bookkeeping[ 86 ].free_p          = &fmi2_free86;
  fmi2_guarded_bookkeeping[ 86 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 87 ].id              = 87;
  fmi2_guarded_bookkeeping[ 87 ].calloc_p        = &fmi2_calloc87;
  fmi2_guarded_bookkeeping[ 87 ].free_p          = &fmi2_free87;
  fmi2_guarded_bookkeeping[ 87 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 88 ].id              = 88;
  fmi2_guarded_bookkeeping[ 88 ].calloc_p        = &fmi2_calloc88;
  fmi2_guarded_bookkeeping[ 88 ].free_p          = &fmi2_free88;
  fmi2_guarded_bookkeeping[ 88 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 89 ].id              = 89;
  fmi2_guarded_bookkeeping[ 89 ].calloc_p        = &fmi2_calloc89;
  fmi2_guarded_bookkeeping[ 89 ].free_p          = &fmi2_free89;
  fmi2_guarded_bookkeeping[ 89 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 90 ].id              = 90;
  fmi2_guarded_bookkeeping[ 90 ].calloc_p        = &fmi2_calloc90;
  fmi2_guarded_bookkeeping[ 90 ].free_p          = &fmi2_free90;
  fmi2_guarded_bookkeeping[ 90 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 91 ].id              = 91;
  fmi2_guarded_bookkeeping[ 91 ].calloc_p        = &fmi2_calloc91;
  fmi2_guarded_bookkeeping[ 91 ].free_p          = &fmi2_free91;
  fmi2_guarded_bookkeeping[ 91 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 92 ].id              = 92;
  fmi2_guarded_bookkeeping[ 92 ].calloc_p        = &fmi2_calloc92;
  fmi2_guarded_bookkeeping[ 92 ].free_p          = &fmi2_free92;
  fmi2_guarded_bookkeeping[ 92 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 93 ].id              = 93;
  fmi2_guarded_bookkeeping[ 93 ].calloc_p        = &fmi2_calloc93;
  fmi2_guarded_bookkeeping[ 93 ].free_p          = &fmi2_free93;
  fmi2_guarded_bookkeeping[ 93 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 94 ].id              = 94;
  fmi2_guarded_bookkeeping[ 94 ].calloc_p        = &fmi2_calloc94;
  fmi2_guarded_bookkeeping[ 94 ].free_p          = &fmi2_free94;
  fmi2_guarded_bookkeeping[ 94 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 95 ].id              = 95;
  fmi2_guarded_bookkeeping[ 95 ].calloc_p        = &fmi2_calloc95;
  fmi2_guarded_bookkeeping[ 95 ].free_p          = &fmi2_free95;
  fmi2_guarded_bookkeeping[ 95 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 96 ].id              = 96;
  fmi2_guarded_bookkeeping[ 96 ].calloc_p        = &fmi2_calloc96;
  fmi2_guarded_bookkeeping[ 96 ].free_p          = &fmi2_free96;
  fmi2_guarded_bookkeeping[ 96 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 97 ].id              = 97;
  fmi2_guarded_bookkeeping[ 97 ].calloc_p        = &fmi2_calloc97;
  fmi2_guarded_bookkeeping[ 97 ].free_p          = &fmi2_free97;
  fmi2_guarded_bookkeeping[ 97 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 98 ].id              = 98;
  fmi2_guarded_bookkeeping[ 98 ].calloc_p        = &fmi2_calloc98;
  fmi2_guarded_bookkeeping[ 98 ].free_p          = &fmi2_free98;
  fmi2_guarded_bookkeeping[ 98 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 99 ].id              = 99;
  fmi2_guarded_bookkeeping[ 99 ].calloc_p        = &fmi2_calloc99;
  fmi2_guarded_bookkeeping[ 99 ].free_p          = &fmi2_free99;
  fmi2_guarded_bookkeeping[ 99 ].pointer_keeper  = NULL;

  fmi2_guarded_bookkeeping[ 100 ].id              = 100;
  fmi2_guarded_bookkeeping[ 100 ].calloc_p        = &fmi2_calloc100;
  fmi2_guarded_bookkeeping[ 100 ].free_p          = &fmi2_free100;
  fmi2_guarded_bookkeeping[ 100 ].pointer_keeper  = NULL;
}

