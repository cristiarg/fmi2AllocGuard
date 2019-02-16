cmake_minimum_required (VERSION 3.0)

macro(print_all_variables)
  message(STATUS "print_all_variables------------------------------------------{")
  get_cmake_property(_variableNames VARIABLES)
  foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
  endforeach()
  message(STATUS "print_all_variables------------------------------------------}")
endmacro()

project (fmi2AllocGuard LANGUAGES C)

#########################################
# global options
#########################################

option(FMI2AG_TEST "Build tests for fmi2AllocGuard (default: OFF)" OFF)

option(FMI2AG_START_ID "Start id <numeric>" -1)
option(FMI2AG_END_ID "End id <numeric>" -1)

#########################################
# pre build step
#########################################

set( FMI2AG_SCRIPT_DO_INVOKE  OFF )
set( FMI2AG_SCRIPT_START_ID   1 )
set( FMI2AG_SCRIPT_END_ID     10 )
  # should be the same defaults as the ones in the script

if ( FMI2AG_START_ID GREATER -1 )
  message( STATUS "FMI2AG_START_ID parameter explicitly specified with value '${FMI2AG_START_ID}'" )
  set( FMI2AG_SCRIPT_START_ID ${FMI2AG_START_ID} )
  set(FMI2AG_SCRIPT_DO_INVOKE ON)
endif( FMI2AG_START_ID GREATER -1 )

if ( FMI2AG_END_ID GREATER -1 )
  message( STATUS "FMI2AG_END_ID parameter explicitly specified with value '${FMI2AG_END_ID}'" )
  set( FMI2AG_SCRIPT_END_ID ${FMI2AG_END_ID} )
  set(FMI2AG_SCRIPT_DO_INVOKE ON)
endif( FMI2AG_END_ID GREATER -1 )

if ( FMI2AG_SCRIPT_DO_INVOKE )
  message( STATUS "searching for 'python3' executable" )
  find_program(FMI2AG_SCRIPT_PYTHON_EXE "python3")
  if ( ${FMI2AG_SCRIPT_PYTHON_EXE} STRGREATER "" )
    message( STATUS "found 'python3' executable at '${FMI2AG_SCRIPT_PYTHON_EXE}'")
    message( STATUS "executing '${FMI2AG_SCRIPT_PYTHON_EXE} ${PROJECT_SOURCE_DIR}/scr/gen.py --start_id ${FMI2AG_SCRIPT_START_ID} --end_id ${FMI2AG_SCRIPT_END_ID}'" )

    execute_process(
        COMMAND "${FMI2AG_SCRIPT_PYTHON_EXE}" ${PROJECT_SOURCE_DIR}/scr/gen.py --start_id ${FMI2AG_SCRIPT_START_ID} --end_id ${FMI2AG_SCRIPT_END_ID}
        RESULT_VARIABLE FMI2AG_SCRIPT_EXEC_RESULT )

    if ( ${FMI2AG_SCRIPT_EXEC_RESULT} EQUAL 0 )
      message( STATUS "boilerplate generating script returned '${FMI2AG_SCRIPT_EXEC_RESULT}'" )
    else()
      message( FATAL_ERROR "boilerplate generating script returned '${FMI2AG_SCRIPT_EXEC_RESULT}'" )
    endif()

  else( ${FMI2AG_SCRIPT_PYTHON_EXE} STRGREATER "" )
    message( FATAL_ERROR "==== python executable was not found" )
  endif( ${FMI2AG_SCRIPT_PYTHON_EXE} STRGREATER "" )
endif( FMI2AG_SCRIPT_DO_INVOKE )

#########################################
# global cmake options
#########################################

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RULE_MESSAGES ON)

#########################################
# compiler options
#########################################

#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_C_COMPILER "/usr/bin/clang")
  # setting this, causes cmake to loop indefinitely
  # ?? probably trying to find the suggested compiler ??
  # to switch between gcc/clang, export env variable CC with compiler full path

if (${CMAKE_C_COMPILER_ID} STREQUAL "Clang")
  message( STATUS "compiler id = 'Clang'" )
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -pedantic -Wfloat-conversion" )
    # -Wfloat-equal       - cannot add this as MinUnit does it
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
  message( STATUS "compiler id = 'GNU'" )
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Wextra -pedantic -Wfloat-conversion" )
    # -Wfloat-equal       - cannot add this as MinUnit does it
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "Intel")
  message( STATUS "compiler id = 'Intel'" )
  message( WARNING "Not tested with 'Intel' compiler!")
elseif (${CMAKE_C_COMPILER_ID} STREQUAL "MSVC")
  message( STATUS "compiler id = 'MSVC'" )
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /TC /W4" )
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2" )
    # /TC - treat all files as C
else()
  message( STATUS "compiler not supported (not one of 'Clang', 'GNU' or 'MSVC')" )
endif()

#########################################
# library
#########################################

set(FMI2AG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")
set(FMI2AG_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

#set_source_files_properties(${FMI2AG_SOURCE_DIR}/avl.c PROPERTIES LANGUAGE CXX )
#set_source_files_properties(${FMI2AG_SOURCE_DIR}/bookkeeping.c PROPERTIES LANGUAGE CXX )
#set_source_files_properties(${FMI2AG_SOURCE_DIR}/fmi2AllocGuard.c PROPERTIES LANGUAGE CXX )

set(FMI2AG_FILES_HEADERS_PUBLIC
  ${FMI2AG_INCLUDE_DIR}/fmi2Export.h
  ${FMI2AG_INCLUDE_DIR}/fmi2Defines.h
  ${FMI2AG_INCLUDE_DIR}/fmi2AllocGuard.h )

set(FMI2AG_FILES_HEADERS_PRIVATE
  ${FMI2AG_SOURCE_DIR}/avl.h
  ${FMI2AG_SOURCE_DIR}/bookkeeping.h )

set(FMI2AG_FILES_CODE
  ${FMI2AG_SOURCE_DIR}/avl.c
  ${FMI2AG_SOURCE_DIR}/bookkeeping.c
  ${FMI2AG_SOURCE_DIR}/fmi2AllocGuard.c )

add_library(fmi2AllocGuard SHARED ${FMI2AG_FILES_CODE} ${FMI2AG_FILES_HEADERS_PUBLIC} ${FMI2AG_FILES_HEADERS_PRIVATE} )

include_directories( ${FMI2AG_INCLUDE_DIR} )
  # public includes

#add_subdirectory("${PROJECT_SOURCE_DIR}/src" src )

# needed because both .c and .cpp code files are present
#set_target_properties( fmi2AllocGuard PROPERTIES LINKER_LANGUAGE C)

# change the defined exports symbol - see inc/export.h
set_target_properties( fmi2AllocGuard PROPERTIES DEFINE_SYMBOL "FMI2ALLOCGUARD_DLL_EXPORTS")

get_target_property( fmi2AllocGuard_target_type fmi2AllocGuard TYPE )
if( fmi2AllocGuard_target_type STREQUAL "SHARED_LIBRARY" )
  # needed to allow both shared and static lib build
  # for now, we're only using shared but this can be ammended above
  add_definitions( -DFMI2ALLOCGUARD_DLL )
endif()

# by default, compilation is in Release mode
add_definitions( -DCMAKE_BUILD_TYPE=Debug )

# NOTE: to compile C-only:
# - specify language "C" when declaring project
# - remove compiler arguments that do not make sense for C (for GCC, you
#     get a warning, other compilers might not be so tolerant)
# - add property "LINKER_LANGUAGE" with "C"

#########################################
# unit testing
#########################################

if ( FMI2AG_TEST )
  set(FMI2AG_TEST_CATCH OFF)
    # not using Catch2; it requires C++ and we want to make do with C only
  set(FMI2AG_TEST_MINUNIT ON)
    # this is C only
endif()

if ( FMI2AG_TEST )
  enable_testing()

  include(ExternalProject)

  # the location of the test sources
  set(FMI2AG_TST_DIR "${PROJECT_SOURCE_DIR}/tst")

  if ( FMI2AG_TEST_CATCH )
    set(FMI2AG_FETCH_CATCH
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG c32f275a008a50ae058fcd8a43f0c387d90c929b )
      # fetching Catch1.x branch

    ExternalProject_Add(
        Catch-External
        PREFIX ${CMAKE_BINARY_DIR}/external/Catch1.x
        ${FMI2AG_FETCH_CATCH}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/external/Catch1.x/src/Catch-External/single_include/catch.hpp
                                                 ${CMAKE_BINARY_DIR}/external/Catch/include/catch.hpp
      )
    add_library(Catch INTERFACE)
    add_dependencies(Catch Catch-External)
    target_include_directories(Catch INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)

    #
    # testCatchFmi2AllocGuard
    #
                 ## test code must be able to access implementation detail headers
                 ## .. or it can use relative paths
                 ##include_directories("${PROJECT_SOURCE_DIR}/src")

                 #set ( FMI2AG_TEST_FILES_CATCH
                 #  ${FMI2AG_TST_DIR}/testMain.cpp
                 #  ${FMI2AG_TST_DIR}/test01_StaticInit.cpp
                 #  ${FMI2AG_TST_DIR}/test03_GuardedBookkeeping.cpp )
                 #  #${FMI2AG_TST_DIR}/test02_AllocGuard.cpp
                 ##file(GLOB_RECURSE unit_test_sources "${FMI2AG_TST_DIR}/*.c" "${FMI2AG_TST_DIR}/*.cpp")

                 #add_executable(testCatchFmi2AllocGuard ${FMI2AG_TEST_FILES_CATCH})
                 #target_link_libraries(testCatchFmi2AllocGuard PUBLIC Catch)
                 #target_link_libraries(testCatchFmi2AllocGuard PUBLIC fmi2AllocGuard)
                 #target_include_directories(testCatchFmi2AllocGuard PUBLIC ${FMI2AG_TST_DIR})

                 ###add_subdirectory(${PROJECT_SOURCE_DIR}/lib/Catch2)
                 ###find_package(Catch2 REQUIRED)

                 ### needed because both .c and .cpp code files are present
                 ###set_target_properties( testCatchFmi2AllocGuard PROPERTIES LINKER_LANGUAGE C)
                 ###set_source_files_properties("${PROJECT_SOURCE_DIR}/tst/*.cpp" PROPERTIES LANGUAGE C )

                 #target_compile_options(testCatchFmi2AllocGuard PUBLIC -Wall -Wfloat-conversion -pedantic -Wextra)

                 #add_test( NAME TestStaticInit         COMMAND testCatchFmi2AllocGuard TestStaticInit )
                 ##add_test( NAME TestAllocGuard         COMMAND testCatchFmi2AllocGuard TestAllocGuard )
                 #add_test( NAME TestGuardedBookkeeping COMMAND testCatchFmi2AllocGuard TestGuardedBookkeeping )
  endif()

  if ( FMI2AG_TEST_MINUNIT )
    enable_language( C )
      # enable the C compiler for the following project
      # not sure whether this option is restricted to this scope or
      # whether it propagates further on as well
    
    set(FMI2AG_FETCH_MINUNIT
        GIT_REPOSITORY https://github.com/cristiarg/minunit.git
        GIT_TAG 7bb647614d0ca1644f2e5a620a6e7583edddb4a8 )

    ExternalProject_Add(
        MinUnit-External
        PREFIX ${CMAKE_BINARY_DIR}/external/MinUnit
        ${FMI2AG_FETCH_MINUNIT}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/external/MinUnit/src/MinUnit-External/minunit.h
                                                 ${CMAKE_BINARY_DIR}/external/MinUnit/include/minunit.h
      )
    add_library(MinUnit INTERFACE)
    add_dependencies(MinUnit MinUnit-External)
    target_include_directories(MinUnit INTERFACE ${CMAKE_BINARY_DIR}/external/MinUnit/include)
      # this will clone the MinUnit repo and also, sort of, install it in an arbitrary location
      # I'm sure this process can be optimized

    #
    # testAVL
    #
    #set_source_files_properties("${FMI2AG_TST_DIR}/test11_avl.c" PROPERTIES LANGUAGE C )

    set ( FMI2AG_TEST_FILES_AVL
      ${FMI2AG_SOURCE_DIR}/avl.c
      ${FMI2AG_TST_DIR}/test11_avl.c)
    #add_definitions(-DFMI2AG_COMPILE_FOR_UNITTEST)
      # needed to allow 'extern "C"' definition for unit testing

    add_executable(testAVL ${FMI2AG_TEST_FILES_AVL})
    target_link_libraries(testAVL PRIVATE MinUnit)
    #target_link_libraries(testAVL PRIVATE fmi2AllocGuard)
    #target_include_directories(testAVL PUBLIC ${FMI2AG_TST_DIR})
    #set_target_properties( testAVL PROPERTIES LINKER_LANGUAGE C)

    add_test( NAME TestAVL COMMAND testAVL )

    #
    # testAllocGuard
    #
    set ( FMI2AG_TEST_FILES_ALLOCGUARD
      ${FMI2AG_TST_DIR}/test12_AllocGuard.c )
    add_executable( testAllocGuard ${FMI2AG_TEST_FILES_ALLOCGUARD} )
    target_link_libraries( testAllocGuard PRIVATE MinUnit )
    target_link_libraries( testAllocGuard PRIVATE fmi2AllocGuard )

    add_test( NAME TestAllocGuard COMMAND testAllocGuard )

    #
    # testGuardedBookkeeping
    #
    set ( FMI2AG_TEST_FILES_GUARDEDBOOKKEEPING
      ${FMI2AG_SOURCE_DIR}/avl.c
      ${FMI2AG_SOURCE_DIR}/bookkeeping.c
      ${FMI2AG_TST_DIR}/test03_GuardedBookkeeping.c )
    add_executable(testGuardedBookkeeping ${FMI2AG_TEST_FILES_GUARDEDBOOKKEEPING} )
    target_link_libraries( testGuardedBookkeeping PRIVATE MinUnit )
    #target_link_libraries( testGuardedBookkeeping PRIVATE fmi2AllocGuard )

    add_test( NAME TestGuardedBookkeeping COMMAND testGuardedBookkeeping )

    #
    # testLoadSharedLib
    #
    set ( FMI2AG_TEST_FILES_LOADSHAREDLIB
      ${FMI2AG_TST_DIR}/test02_dlopen.c )
    add_executable(testLoadSharedLib ${FMI2AG_TEST_FILES_LOADSHAREDLIB} )
    target_link_libraries( testLoadSharedLib PRIVATE MinUnit )
    if(UNIX)
      target_link_libraries( testLoadSharedLib PRIVATE dl )
    endif(UNIX)

    add_test( NAME TestLoadSharedLib COMMAND testLoadSharedLib )

    #
    # testUseSharedLib
    #
    set ( FMI2AG_TEST_FILES_USESHAREDLIB
      ${FMI2AG_TST_DIR}/test04_UseSharedLib.c )
    add_executable(testUseSharedLib ${FMI2AG_TEST_FILES_USESHAREDLIB} )
    target_link_libraries( testUseSharedLib PRIVATE MinUnit )
    target_link_libraries( testUseSharedLib PRIVATE fmi2AllocGuard )

    add_test( NAME TestUseSharedLib COMMAND testUseSharedLib )
  endif()
endif()

#print_all_variables()
