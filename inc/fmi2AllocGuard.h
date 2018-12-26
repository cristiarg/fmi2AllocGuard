#ifndef FMI2ALLOCGUARD_H
#define FMI2ALLOCGUARD_H /*1*/

#include <stddef.h>
#include "export.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef void* ( *fmi2_guarded_alloc_t )( size_t num , size_t size );
  typedef void  ( *fmi2_guarded_free_t  )( void* obj );

  // obtain a new entry in the function table
  // the value is an opaque reference for further requests
  //
  /*FMI2ALLOCGUARD_DLL_EXPORTS*/
  size_t fmi2_guarded_acquire();

  // the getter functions
  // the entry is obtained from a previously called *_acquire
  //
  /*FMI2ALLOCGUARD_DLL_EXPORTS*/
  fmi2_guarded_alloc_t fmi2_guarded_get_alloc( const size_t entry );
  /*FMI2ALLOCGUARD_DLL_EXPORTS*/
  fmi2_guarded_free_t fmi2_guarded_get_free( const size_t entry );

  // release an entry in the function table
  // upon calling this, remaining unfreed memory pending to this entry is released
  // the entry is obtained from a previously called *_acquire
  //
  /*FMI2ALLOCGUARD_DLL_EXPORTS*/
  void fmi2_guarded_release( const size_t entry );

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FMI2ALLOCGUARD_H

// ---------------------------------------------------------
  //// - instantiate a new getter
  //// - obtain pointers to the functions
  //// - RAII style; upon destruction, all internal allocated bufffers are freed
  ////
  //class FMI2ALLOCGUARD_API getter {
  //public:
  //  getter();
  //  ~getter();

  //  getter( const getter&  ) = delete;
  //  getter(       getter&& ) = delete;
  //  getter& operator=( const getter&  ) = delete;
  //  getter& operator=(       getter&& ) = delete;

  //public:
  //  fmi2_guarded_alloc_t get_alloc() const;
  //  fmi2_guarded_free_t get_free() const;

  //private:
  //  fmi2_guarded_alloc_t a;
  //  fmi2_guarded_free_t f;
  //};



//-------------------------------------------------------------
  //class FMI2ALLOCGUARD_API allocator {

  //public: // statics
  //  static allocator& get_instance();

  //private: // ctor/dtor
  //  allocator();

  //public:
  //  // deleted methods should be public for better error messages from the compiler
  //  allocator( const allocator&  ) = delete;
  //  allocator(       allocator&& ) = delete;
  //  allocator& operator=( const allocator&  ) = delete;
  //  allocator& operator=(       allocator&& ) = delete;

  //public: // methods
  //  void obtain_new( fmi2_guarded_alloc_t& _alloc , fmi2_guarded_free_t& _free) const;
  //};

