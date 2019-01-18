#!/usr/bin/python

import sys
import os

"""
A script to generate the boilerplate calloc/free indirections
declaration, definitions and initialization code.
See src/GuardedBookkeeping for inclusions.
"""

START_ID = 1
END_ID = 10
INVALID_ID = -1

FILE_NAME_HEADER_DEFINES = "../inc/fmi2Defines.h"
FILE_NAME_BOOKKEEPING_DECLARE_INLINE = "../src/bookkeeping.declare.inl"
FILE_NAME_BOOKKEEPING_DEFINE_INLINE = "../src/bookkeeping.define.inl"
FILE_NAME_BOOKKEEPING_INIT_INLINE = "../src/bookkeeping.init.inl"

#
# public header with constants
#

def gen_header_defines_include_guard_top( _hf ) :
  _hf.write(
"""#ifndef FMI2DEFINES_H
#define FMI2DEFINES_H
""")

def gen_header_defines_constants( _hf , _start_id , _end_id , _invalid_id ) :
  _hf.write( """
#define FMI2_FUNC_INDEX_MIN %d
#define FMI2_FUNC_INDEX_MAX %d

#define FMI2_FUNC_INDEX_INVALID %d
""" % (_start_id, _end_id, _invalid_id))

def gen_header_defines_include_guard_bottom( _hf ) :
  _hf.write(
"""
#endif // FMI2DEFINES_H

""")

def main_gen_header_defines() :
  with open( FILE_NAME_HEADER_DEFINES , "w" ) as inline_file :
    gen_header_defines_include_guard_top( inline_file )
    gen_header_defines_constants( inline_file , START_ID , END_ID , INVALID_ID )
    gen_header_defines_include_guard_bottom( inline_file )
  inline_file.close()

#
# calloc/free declare inline file
#
def gen_calloc_declare_inline( _f ) :
  for i in range( START_ID , END_ID + 1 ) :
    _f.write("FMI2ALLOCGUARD_LOCAL void* fmi2_calloc%d ( size_t _num , size_t _size );\n" % (i) )

def gen_free_declare_inline( _f ) :
  for i in range( START_ID , END_ID + 1 ) :
    _f.write("FMI2ALLOCGUARD_LOCAL void fmi2_free%d ( void* _ptr );\n" % (i) )

def main_gen_calloc_free_declare_inline() :
  with open( FILE_NAME_BOOKKEEPING_DECLARE_INLINE , "w" ) as inline_file :
    gen_calloc_declare_inline( inline_file )
    inline_file.write("\n")
    gen_free_declare_inline( inline_file )
    inline_file.write("\n")
  inline_file.close()

#
# calloc/free define inline file
#
def gen_calloc_define_inline( _f ) :
  for i in range( START_ID , END_ID + 1 ) :
    _f.write(
"""void* fmi2_calloc%d ( size_t _num , size_t _size )
{
  void* const p = calloc( _num , _size );
  const bool add_res = avl_add(&fmi2_guarded_bookkeeping[ %d ].pointer_keeper, p, func_avl_data_comp_lt);
  if( add_res ) {
    return p;
  } else {
    free( p );
    return NULL;
  }
}

""" % (i, i) )

def gen_free_define_inline( _f ) :
  for i in range( START_ID , END_ID + 1 ) :
    _f.write(
"""void fmi2_free%d ( void* _ptr )
{
  const bool rem_res = avl_rem(&fmi2_guarded_bookkeeping[ %d ].pointer_keeper, _ptr, func_avl_data_comp_lt, func_avl_data_clear_nop);
  if( !rem_res ) {
    //TODO: assert? error?
  }
  free( _ptr );
}

""" % (i, i) )

def main_gen_calloc_free_define_inline() :
  with open( FILE_NAME_BOOKKEEPING_DEFINE_INLINE , "w" ) as inline_file :
    gen_calloc_define_inline( inline_file )
    gen_free_define_inline( inline_file )
  inline_file.close()

#
# init inline file
#
def gen_init_inline( _f ) :
  for i in range( START_ID , END_ID + 1 ) :
    _f.write(
"""  fmi2_guarded_bookkeeping[ %d ].id              = %d;
  fmi2_guarded_bookkeeping[ %d ].calloc_p        = &fmi2_calloc%d;
  fmi2_guarded_bookkeeping[ %d ].free_p          = &fmi2_free%d;
  fmi2_guarded_bookkeeping[ %d ].pointer_keeper  = NULL;
  fmi2_guarded_bookkeeping[ %d ].in_use          = false;

""" % (i , i , i , i , i , i , i, i) )

def main_gen_init() :
  with open( FILE_NAME_BOOKKEEPING_INIT_INLINE , "w" ) as inline_file :
    gen_init_inline( inline_file )
  inline_file.close()

#
# main
#
main_gen_header_defines()
main_gen_calloc_free_declare_inline()
main_gen_calloc_free_define_inline()
main_gen_init()
#main_gen_header()
#main_gen_body()

