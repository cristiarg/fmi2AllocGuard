#include "fmi2AllocGuard.h"
#include <stdlib.h>
#include <cassert>

static const size_t id = 42;

size_t fmi2_guarded_acquire()
{
  return id;
}

fmi2_guarded_alloc_t fmi2_guarded_get_alloc( const size_t entry )
{
  if( entry == id ) {
    return calloc;
  } else {
    return NULL;
  }
}

fmi2_guarded_free_t fmi2_guarded_get_free( const size_t entry )
{
  if( entry == id ) {
    return free;
  } else {
    return NULL;
  }
}

void fmi2_guarded_release( const size_t entry )
{
  assert( id == entry );
}

//namespace fmi2_alloc_guard {
//
//  getter::getter()
//      : a { nullptr }
//      , f { nullptr }
//  {
//    // TODO
//  }
//
//  getter::~getter()
//  {
//    if ( f != nullptr && a != nullptr ) {
//      // TODO
//    } else {
//      assert( f == nullptr && a == nullptr );
//    }
//  }
//
//  fmi2_guarded_alloc_t getter::get_alloc() const
//  {
//    return a;
//  }
//
//  fmi2_guarded_free_t getter::get_free() const
//  {
//    return f;
//  }
//
//}


  //allocator& allocator::get_instance()
  //{
  //  static allocator the_instance;

  //  return the_instance;
  //}

  //allocator::allocator()
  //{
  //}

  //void allocator::obtain_new( fmi2_guarded_alloc_t& _alloc , fmi2_guarded_free_t& _free) const
  //{
  //  _alloc = &calloc;
  //  _free = &free;
  //};

