#!/usr/bin/python

import sys

START_ID = 1
END_ID = 5

#
# header functions
#

def gen_header_includes( _hf ) :
  _hf.write("#include \"fmi2AllocGuard.h\"\n")
  _hf.write("#include \"PointerKeeper.hpp\"\n")
  _hf.write("\n\n")


def gen_header_consts( _hf , _start_id , _end_id ) :
  _hf.write("static const int FMI2_FUNC_INDEX_MIN = %d;\n" % (_start_id) )
  _hf.write("static const int FMI2_FUNC_INDEX_MAX = %d;\n" % (_end_id) )
  _hf.write("\n\n")


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


def gen_header_struct_array( _hf , _end_id ) :
  _hf.write("struct fmi2_guarded_alloc_free_str fmi2_guarded_bookkeeping[ %d ];\n" % (_end_id + 1))
  _hf.write("\n")

def gen_header_init( _hf ) :
  _hf.write("void fmi2_guarded_alloc_free_str_init();\n")
  _hf.write("\n")

def main_gen_header() :
  header_file = open( "fmi2_calloc_free.hpp" , "w" )

  gen_header_includes( header_file )
  gen_header_consts( header_file , START_ID , END_ID )
  gen_header_struct( header_file )
  gen_header_callocs( header_file , START_ID , END_ID )
  gen_header_frees( header_file , START_ID , END_ID )
  gen_header_struct_array( header_file , END_ID )

  header_file.close()

#
# body functions
#

def gen_body_includes( _bf ) :
  _bf.write("#include \"fmi2_calloc_free.hpp\"\n")
  _bf.write("#include <stdlib.h>\n")
  _bf.write("\n\n")


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

  _bf.write("\n")

def gen_body_init( _bf , _start_id , _end_id ) :
  _bf.write("void fmi2_guarded_alloc_free_str_init()\n")
  _bf.write("{\n")
  # first, init the idle part
  _bf.write("  for( int i = 0; i < FMI2_FUNC_INDEX_MIN ; i++ ) {\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].id             = -1;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].calloc_p       = NULL;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].free_p         = NULL;\n")
  _bf.write("    fmi2_guarded_bookkeeping[ i ].pointer_keeper = NULL;\n")
  _bf.write("  }\n")
  for i in range( _start_id , _end_id + 1 ) :
    _bf.write("\n")
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].id              = %d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].calloc_p        = fmi2_calloc%d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].free_p          = fmi2_free%d;\n" % (i, i))
    _bf.write("  fmi2_guarded_bookkeeping[ %d ].pointer_keeper  = NULL;\n" % (i))

  _bf.write("}\n")
  _bf.write("\n")

def main_gen_body() :
  body_file = open( "fmi2_calloc_free.cpp" , "w" )

  gen_body_includes( body_file )
  gen_body_callocs( body_file , START_ID , END_ID )
  gen_body_frees( body_file , START_ID , END_ID )
  gen_body_init( body_file , START_ID , END_ID )

  body_file.close()

#
# main
#

main_gen_header()
main_gen_body()



