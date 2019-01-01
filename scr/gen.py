#!/usr/bin/python

import sys
import os

START_ID = 1
END_ID = 10
INVALID_ID = -1

FILE_NAME_BASE = "GuardedBookkeeping"
FILE_EXT_HEADER = "h"
FILE_EXT_CODE = "cpp"

FILE_NAME_HEADER  = "../src/{0}.{1}".format( FILE_NAME_BASE , FILE_EXT_HEADER )
FILE_NAME_CODE    = "../src/{0}.{1}".format( FILE_NAME_BASE , FILE_EXT_CODE )

#
# header functions
#
def gen_header_include_guard_top( _hf ) :
  _hf.write("#ifndef FMI2GUARDEDBOOKKEEPING_H\n")
  _hf.write("#define FMI2GUARDEDBOOKKEEPING_H\n")
  _hf.write("\n")

def gen_header_includes( _hf ) :
  _hf.write("#include \"fmi2AllocGuard.h\"\n")
  _hf.write("#include \"PointerKeeper.hpp\"\n")
  _hf.write("\n")

def gen_header_consts( _hf , _start_id , _end_id , _invalid_id ) :
  _hf.write("static const int FMI2_FUNC_INDEX_MIN = %d;\n" % (_start_id) )
  _hf.write("static const int FMI2_FUNC_INDEX_MAX = %d;\n" % (_end_id) )
  _hf.write("\n")
  _hf.write("static const int FMI2_FUNC_INDEX_INVALID = %d;\n" % (_invalid_id) )
  _hf.write("\n")

def gen_header_struct( _hf ) :
  _hf.write("struct fmi2_guarded_alloc_free_str {\n")
  _hf.write("  int                  id;\n")
  _hf.write("  fmi2_guarded_alloc_t calloc_p;\n")
  _hf.write("  fmi2_guarded_free_t  free_p;\n")
  _hf.write("  PointerKeeper*       pointer_keeper;\n")
  _hf.write("};\n")
  _hf.write("\n")

def gen_header_callocs( _hf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _hf.write("void* fmi2_calloc%d ( size_t _num , size_t _size );\n" % (i) )
  _hf.write("\n")

def gen_header_frees( _hf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _hf.write("void fmi2_free%d ( void* _ptr );\n" % (i) )
  _hf.write("\n")

def gen_header_struct_array_declaration( _hf ) :
  _hf.write("extern struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ];\n")
  _hf.write("\n")

def gen_header_init( _hf ) :
  _hf.write("void fmi2_guarded_bookkeeping_init();\n")
  _hf.write("\n")

def gen_header_include_guard_bottom( _hf ) :
  _hf.write("#endif // FMI2GUARDEDBOOKKEEPING_H\n")
  _hf.write("\n")

def main_gen_header() :
  with open( FILE_NAME_HEADER , "w" ) as header_file :
    gen_header_include_guard_top( header_file )
    gen_header_includes( header_file )
    gen_header_consts( header_file , START_ID , END_ID , INVALID_ID )
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
  _bf.write("\n")

def gen_body_callocs( _bf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("void* fmi2_calloc%d ( size_t _num , size_t _size )\n" % (i) )
    _bf.write("{\n")
    _bf.write("  static const int func_id = %d;\n" % (i))
    _bf.write("  void* p = calloc( _num , _size );\n")
    _bf.write("  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;\n")
    _bf.write("  const bool add_res = pk->add( p );\n")
    _bf.write("  if( add_res ) {\n")
    _bf.write("    return p;\n")
    _bf.write("  } else {\n")
    _bf.write("    free( p );\n")
    _bf.write("    return NULL;\n")
    _bf.write("  }\n")
    _bf.write("}\n")
    _bf.write("\n")
  _bf.write("\n")

def gen_body_frees( _bf , _start_id , _end_id ) :
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("void fmi2_free%d ( void* _ptr )\n" % (i) )
    _bf.write("{\n")
    _bf.write("  static const int func_id = %d;\n" % (i))
    _bf.write("  PointerKeeper* pk = fmi2_guarded_bookkeeping[ func_id ].pointer_keeper;\n")
    _bf.write("  const bool rem_res = pk->rem( _ptr );\n")
    _bf.write("  if( !rem_res ) {\n")
    _bf.write("    //TODO: assert? error?\n")
    _bf.write("  }\n")
    _bf.write("  free( _ptr );\n")
    _bf.write("}\n")
    _bf.write("\n")

def gen_body_struct_array_implementation( _bf ) :
  _bf.write("struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ FMI2_FUNC_INDEX_MAX + 1 ];\n")
  _bf.write("\n")

def gen_body_init( _bf , _start_id , _end_id ) :
  _bf.write("void fmi2_guarded_bookkeeping_init()\n")
  _bf.write("{\n")
  # first, init the idle part
  _bf.write("  for( int i = 0; i < FMI2_FUNC_INDEX_MIN ; i++ ) {\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].id             = -1;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].calloc_p       = NULL;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].free_p         = NULL;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].pointer_keeper = NULL;\n")
  _bf.write("  }\n")
  # secondly, iterate and generate for each indirection
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("\n")
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].id              = %d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].calloc_p        = &fmi2_calloc%d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].free_p          = &fmi2_free%d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].pointer_keeper  = NULL;\n" % (i))
  _bf.write("}\n")
  _bf.write("\n")

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
main_gen_header()
main_gen_body()
