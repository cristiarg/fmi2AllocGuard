#!/usr/bin/python

import argparse
import sys
import os

"""
A script to generate the boilerplate calloc/free indirections
declaration, definitions and initialization code.
See src/GuardedBookkeeping for inclusions.
"""

INVALID_ID = -1

FILE_NAME_HEADER_DEFINES              = "inc/fmi2Defines.h"
FILE_NAME_BOOKKEEPING_DECLARE_INLINE  = "src/bookkeeping.declare.inl"
FILE_NAME_BOOKKEEPING_DEFINE_INLINE   = "src/bookkeeping.define.inl"
FILE_NAME_BOOKKEEPING_INIT_INLINE     = "src/bookkeeping.init.inl"

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

def main_gen_header_defines( _project_dir , _start_id , _end_id ) :
  file_abs_path = os.path.join( _project_dir  , FILE_NAME_HEADER_DEFINES )
  try :
    print("INFO: opening file '" + file_abs_path + "' for writing" )
    with open( file_abs_path , "w" ) as inline_file :
      print("INFO:   opened" )
      gen_header_defines_include_guard_top( inline_file )
      gen_header_defines_constants( inline_file , _start_id , _end_id , INVALID_ID )
      gen_header_defines_include_guard_bottom( inline_file )
      print("INFO:   wrote" )
    inline_file.close()
  except IOError as x :
    print( "ERROR: cannot open file '" + file_abs_path + "' for writing: " + x.strerror , file=sys.stderr )

#
# calloc/free declare inline file
#

def gen_calloc_declare_inline( _f , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _f.write("FMI2ALLOCGUARD_LOCAL void* fmi2_calloc%d ( size_t _num , size_t _size );\n" % (i) )

def gen_free_declare_inline( _f , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _f.write("FMI2ALLOCGUARD_LOCAL void fmi2_free%d ( void* _ptr );\n" % (i) )

def main_gen_calloc_free_declare_inline( _project_dir , _start_id , _end_id ) :
  file_abs_path = os.path.join( _project_dir  , FILE_NAME_BOOKKEEPING_DECLARE_INLINE )
  try :
    print("INFO: opening file '" + file_abs_path + "' for writing" )
    with open( file_abs_path , "w" ) as inline_file :
      print("INFO:   opened" )
      gen_calloc_declare_inline( inline_file , _start_id , _end_id )
      inline_file.write("\n")
      gen_free_declare_inline( inline_file , _start_id , _end_id )
      inline_file.write("\n")
      print("INFO:   wrote" )
    inline_file.close()
  except IOError as x :
    print( "ERROR: cannot open file '" + file_abs_path + "' for writing: " + x.strerror , file=sys.stderr )

#
# calloc/free define inline file
#

def gen_calloc_define_inline( _f , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
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

def gen_free_define_inline( _f , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
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

def main_gen_calloc_free_define_inline( _project_dir , _start_id , _end_id ) :
  file_abs_path = os.path.join( _project_dir , FILE_NAME_BOOKKEEPING_DEFINE_INLINE )
  try :
    print("INFO: opening file '" + file_abs_path + "' for writing" )
    with open( file_abs_path , "w" ) as inline_file :
      print("INFO:   opened" )
      gen_calloc_define_inline( inline_file , _start_id , _end_id )
      gen_free_define_inline( inline_file, _start_id , _end_id )
      print("INFO:   wrote" )
    inline_file.close()
  except IOError as x :
    print( "ERROR: cannot open file '" + file_abs_path + "' for writing: " + x.strerror , file=sys.stderr )

#
# init inline file
#

def gen_init_inline( _f , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _f.write(
"""  fmi2_guarded_bookkeeping[ %d ].id              = %d;
  fmi2_guarded_bookkeeping[ %d ].calloc_p        = &fmi2_calloc%d;
  fmi2_guarded_bookkeeping[ %d ].free_p          = &fmi2_free%d;
  fmi2_guarded_bookkeeping[ %d ].pointer_keeper  = NULL;
  fmi2_guarded_bookkeeping[ %d ].in_use          = false;

""" % (i , i , i , i , i , i , i, i) )

def main_gen_init( _project_dir , _start_id , _end_id ) :
  file_abs_path = os.path.join( _project_dir , FILE_NAME_BOOKKEEPING_INIT_INLINE )
  try :
    print("INFO: opening file '" + file_abs_path + "' for writing" )
    with open( file_abs_path , "w" ) as inline_file :
      print("INFO:   writing ... ", end='')
      gen_init_inline( inline_file , _start_id , _end_id )
      print("done" )
    inline_file.close()
  except IOError as x :
    print( "ERROR: cannot open file '" + file_abs_path + "' for writing: " + x.strerror , file=sys.stderr )

#
# arguments processing
#

def get_project_dir( _sys_argv0 ) :
  argv0_dir = os.path.dirname( _sys_argv0 )
  argv0_abs_dir = os.path.abspath( argv0_dir )
  return os.path.dirname( argv0_abs_dir )

def arguments_get_parser() :
  prs = argparse.ArgumentParser(description='Generate boilerplate code for the fmi2AllocGuard library.')
  prs.add_argument('-s', '--start_id', type=int, metavar='<numeric>', default= 1, help="the first entry id", required=False)
  prs.add_argument('-e', '--end_id', type=int, metavar='<numeric>'  , default=10, help="the last entry id" , required=False)
  return prs

def arguments_validate_and_bail( _args ) :
  if _args.start_id < 0 or _args.end_id < 0 :
    print('ERROR: start_id and end_id must be positive numbers');
    sys.exit(-1)
  if _args.start_id >= _args.end_id :
    print('ERROR: start_id (%d) must be smaller than end_id (%d)'
        % (_args.start_id, _args.end_id));
    sys.exit(-1)

#
# main
#

# minimal command line arguments to allow calling from cmake
prs = arguments_get_parser()
args = prs.parse_args()
arguments_validate_and_bail( args )

# allow for the script to be called from anywhere
# this assumes the script's relative position within the code tree
project_dir = get_project_dir( sys.argv[ 0 ] )
print( "INFO: working in project directory '" + project_dir + "'" )

main_gen_header_defines( project_dir , args.start_id , args.end_id )
main_gen_calloc_free_declare_inline( project_dir , args.start_id , args.end_id )
main_gen_calloc_free_define_inline( project_dir , args.start_id , args.end_id )
main_gen_init( project_dir , args.start_id , args.end_id )


