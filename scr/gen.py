#!/usr/bin/python

import sys
import os

"""
A script to generate the boilerplate calloc/free indirections
that also handle bookkeeping.
"""

START_ID = 1
END_ID = 100
INVALID_ID = -1

FILE_NAME_DEFINES_BASE = "fmi2Defines"

FILE_NAME_BASE = "GuardedBookkeeping"
FILE_EXT_H = "h"
FILE_EXT_HPP = "hpp"
FILE_EXT_CPP = "cpp"

FILE_NAME_DEFINES_HEADER = "../inc/{0}.{1}".format( FILE_NAME_DEFINES_BASE , FILE_EXT_H )

FILE_NAME_HEADER  = "../src/{0}.{1}".format( FILE_NAME_BASE , FILE_EXT_HPP )
FILE_NAME_CODE    = "../src/{0}.{1}".format( FILE_NAME_BASE , FILE_EXT_CPP )

#
# header with constants
#
def gen_header_defines_include_guard_top( _hf ) :
  _hf.write(
"""#ifndef FMI2DEFINES_H
#define FMI2DEFINES_H
""")

def gen_header_defines_constants( _hf , _start_id , _end_id , _invalid_id ) :
  _hf.write( """
static const int FMI2_FUNC_INDEX_MIN = %d;
static const int FMI2_FUNC_INDEX_MAX = %d;

static const int FMI2_FUNC_INDEX_INVALID = %d;
""" % (_start_id, _end_id, _invalid_id))

def gen_header_defines_include_guard_bottom( _hf ) :
  _hf.write(
"""
#endif // FMI2DEFINES_H

""")

def main_gen_defines_header() :
  with open( FILE_NAME_DEFINES_HEADER , "w" ) as header_file :
    gen_header_defines_include_guard_top( header_file )
    gen_header_defines_constants( header_file , START_ID , END_ID , INVALID_ID )
    gen_header_defines_include_guard_bottom( header_file )
  header_file.close()

#
# header functions
#
def gen_header_include_guard_top( _hf ) :
  _hf.write(
"""#ifndef FMI2GUARDEDBOOKKEEPING_H
#define FMI2GUARDEDBOOKKEEPING_H""")

def gen_header_includes( _hf ) :
  _hf.write(
"""

#include "fmi2Export.h"
#include "fmi2AllocGuard.h"
#include "PointerKeeper.hpp" """)

def gen_header_struct( _hf ) :
  _hf.write("""

struct fmi2_guarded_alloc_free_str {
  int                  id;
  fmi2_guarded_alloc_t calloc_p;
  fmi2_guarded_free_t  free_p;
  PointerKeeper*       pointer_keeper;
};
""")

def gen_header_callocs( _hf , _start_id , _end_id ) :
  _hf.write("\n")
  for i in range( _start_id , _end_id + 1 ) :
    _hf.write("FMI2ALLOCGUARD_LOCAL void* fmi2_calloc%d ( size_t _num , size_t _size );\n" % (i) )

def gen_header_frees( _hf , _start_id , _end_id ) :
  _hf.write("\n")
  for i in range( _start_id , _end_id + 1 ) :
    _hf.write("FMI2ALLOCGUARD_LOCAL void fmi2_free%d ( void* _ptr );\n" % (i) )

def gen_header_struct_array_declaration( _hf ) :
  _hf.write("""
extern struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ];
""")

def gen_header_init( _hf ) :
  _hf.write("\n")
  _hf.write("void fmi2_guarded_bookkeeping_init();\n")

def gen_header_include_guard_bottom( _hf ) :
  _hf.write("""
#endif // FMI2GUARDEDBOOKKEEPING_H

""")

def main_gen_header() :
  with open( FILE_NAME_HEADER , "w" ) as header_file :
    gen_header_include_guard_top( header_file )
    gen_header_includes( header_file )
    #gen_header_consts( header_file , START_ID , END_ID , INVALID_ID )
    gen_header_struct( header_file )
    gen_header_callocs( header_file , START_ID , END_ID )
    gen_header_frees( header_file , START_ID , END_ID )
    gen_header_struct_array_declaration( header_file )
    gen_header_init( header_file )
    gen_header_include_guard_bottom( header_file )
  header_file.close()

#
# body functions
#
def gen_body_includes( _bf ) :
  _bf.write("#include \"%s\"\n" % (FILE_NAME_HEADER))
  _bf.write("#include <stdlib.h>\n")

def gen_body_callocs( _bf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("""

void* fmi2_calloc%d ( size_t _num , size_t _size )
{
  static const int func_id = %d;
  void* const p = calloc( _num , _size );
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool add_res = pk->add( p );
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}""" % (i, i) )

def gen_body_frees( _bf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write(
"""

void fmi2_free%d ( void* _ptr )
{
  static const int func_id = %d;
  PointerKeeper* const pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;
  const bool rem_res = pk->rem( _ptr );
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}""" % (i, i))

def gen_body_struct_array_implementation( _bf ) :
  _bf.write(
"""struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ]
    = {   0
        , NULL
        , NULL
        , NULL };

""")

def gen_body_init( _bf , _start_id , _end_id ) :
  # first, clean up, possible, double init
  _bf.write(
"""void fmi2_guarded_bookkeeping_init()
{
  for( int idx_clean = 0 ; idx_clean <= FMI2_FUNC_INDEX_MAX ; ++idx_clean ) {
    fmi2_guarded_bookkeeping[ idx_clean ].id        = -1;
    fmi2_guarded_bookkeeping[ idx_clean ].calloc_p  = NULL;
    fmi2_guarded_bookkeeping[ idx_clean ].free_p    = NULL;
    if( fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper != NULL ) {
      delete fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper;
      fmi2_guarded_bookkeeping[ idx_clean ].pointer_keeper = NULL;
    }
  }""")
  # secondly, iterate and generate for each indirection
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("""

  fmi2_guarded_bookkeeping[ %d ].id              = %d;
  fmi2_guarded_bookkeeping[ %d ].calloc_p        = &fmi2_calloc%d;
  fmi2_guarded_bookkeeping[ %d ].free_p          = &fmi2_free%d;
  fmi2_guarded_bookkeeping[ %d ].pointer_keeper  = NULL;""" % (i , i , i , i , i , i , i) )

  _bf.write("""
}

""")

def main_gen_body() :
  body_file = open( FILE_NAME_CODE , "w" )

  gen_body_includes( body_file )
  gen_body_callocs( body_file , START_ID , END_ID )
  gen_body_frees( body_file , START_ID , END_ID )
  gen_body_struct_array_implementation( body_file )
  gen_body_init( body_file , START_ID , END_ID )

  body_file.close()

#
# main
#
main_gen_defines_header()
main_gen_header()
main_gen_body()

