#include "PointerKeeper.hpp"
#include <stdlib.h>

namespace {
  int ptr_comp_lt_func(const void* const _left, const void* const _rite)
  {
    if (_left < _rite )
      return -1;
    else if (_left > _rite)
      return 1;
    else
      return 0;
  }

  void ptr_clear_nop_func(void* _data)
  {
    if (_data != NULL) {
      _data = NULL;
    }
  }

  void ptr_clear_func(void* _data)
  {
    if (_data != NULL) {
      free(_data);
    }
  }
}

PointerKeeper::PointerKeeper()
    : avl_root( NULL )
{
  // nop
}

PointerKeeper::~PointerKeeper()
{
  flush();
}

bool PointerKeeper::add( void* _p )
{
  if ( _p != NULL ) {
    const bool res = avl_add(&avl_root, _p, ptr_comp_lt_func);
    return res;
  }
  return false;
}

bool PointerKeeper::rem( void* _p )
{
  if ( _p != NULL ) {
    const bool res = avl_rem(&avl_root, _p, ptr_comp_lt_func, ptr_clear_nop_func);
      // this is the clean removal from bookkeeping
      // actual free-ing is done elsewhere
    return res;
  }
  return false;
}

int PointerKeeper::flush()
{
  const int res = avl_clear(&avl_root, ptr_clear_func);
  return res;
}

