#include "PointerKeeper.hpp"
#include <stdlib.h>

PointerKeeper::PointerKeeper()
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
    const std::pair< PointerToVoidSet_t::iterator , bool > res = pointerToVoiSet.insert( _p );
    return res.second;
  }
  return false;
}

bool PointerKeeper::rem( void* _p )
{
  if ( _p != NULL ) {
    const PointerToVoidSet_t::iterator it = pointerToVoiSet.find( _p );
    if ( it != pointerToVoiSet.end() ) {
      pointerToVoiSet.erase( it );
      return true;
    }
  }
  return false;
}

int PointerKeeper::flush()
{
  const int res = pointerToVoiSet.size();
        PointerToVoidSet_t::iterator it     = pointerToVoiSet.begin();
  const PointerToVoidSet_t::iterator itEnd  = pointerToVoiSet.end();
  for( ; it != itEnd ; it++ ) {
    free( *it );
    // TODO: provide this function from afar
  }
  pointerToVoiSet.clear();
  return res;
}

