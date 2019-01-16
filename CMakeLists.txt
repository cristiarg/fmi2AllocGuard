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

# tune some cmake options
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RULE_MESSAGES ON)

#########################################
# compiler options
#########################################

#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
#  #message( STATUS "compiler id = 'GNU'" )
#elseif( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
#  #message( STATUS "compiler id = 'MSVC'" )
#endif()

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

# public includes
include_directories( ${FMI2AG_INCLUDE_DIR} )

#add_subdirectory("${PROJECT_SOURCE_DIR}/src" src )

# compilation flags
target_compile_options(fmi2AllocGuard PUBLIC -Wall -Wfloat-conversion -Wpedantic -Wextra)

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

option(FMI2AG_TEST "Build tests for fmi2AllocGuard. Default: ON" ON)

if ( FMI2AG_TEST )
  set(FMI2AG_TEST_CATCH ON)
  set(FMI2AG_TEST_MINUNIT ON)
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

                 #target_compile_options(testCatchFmi2AllocGuard PUBLIC -Wall -Wfloat-conversion -Wpedantic -Wextra)

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
        GIT_REPOSITORY https://github.com/siu/minunit.git
        GIT_TAG 8af0cf5b675dc0a070475659a54ec044f1a6b4d0 )

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

    #
    # testAVL
    #
    #set_source_files_properties("${FMI2AG_TST_DIR}/test11_avl.c" PROPERTIES LANGUAGE C )

    set ( FMI2AG_TEST_FILES_AVL
      ${FMI2AG_TST_DIR}/test11_avl.c)
    add_definitions(-DFMI2AG_COMPILE_FOR_UNITTEST)
      # needed to allow 'extern "C"' definition for unit testing

    add_executable(testAVL ${FMI2AG_TEST_FILES_AVL})
    target_link_libraries(testAVL PRIVATE MinUnit)
    target_link_libraries(testAVL PUBLIC fmi2AllocGuard)
    #target_include_directories(testAVL PUBLIC ${FMI2AG_TST_DIR})
    target_compile_options(testAVL PUBLIC -Wall -Wfloat-conversion -Wpedantic -Wextra)
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
    target_compile_options(testAllocGuard PRIVATE -Wall -Wfloat-conversion -Wpedantic -Wextra)

    add_test( NAME TestAllocGuard COMMAND testAllocGuard )

    #
    # testStaticInit
    #
    set ( FMI2AG_TEST_FILES_STATICINIT
      ${FMI2AG_TST_DIR}/test01_StaticInit.c )
    add_executable(testStaticInit ${FMI2AG_TEST_FILES_STATICINIT} )
    target_link_libraries( testStaticInit PRIVATE MinUnit )
    target_link_libraries( testStaticInit PRIVATE fmi2AllocGuard )
    target_compile_options(testStaticInit PRIVATE -Wall -Wfloat-conversion -Wpedantic -Wextra)

    add_test( NAME TestStaticInit COMMAND testStaticInit )

    #
    # testGuardedBookkeeping
    #
    set ( FMI2AG_TEST_FILES_GUARDEDBOOKKEEPING
      ${FMI2AG_TST_DIR}/test03_GuardedBookkeeping.c )
    add_executable(testGuardedBookkeeping ${FMI2AG_TEST_FILES_GUARDEDBOOKKEEPING} )
    target_link_libraries( testGuardedBookkeeping PRIVATE MinUnit )
    target_link_libraries( testGuardedBookkeeping PRIVATE fmi2AllocGuard )
    target_compile_options(testGuardedBookkeeping PRIVATE -Wall -Wfloat-conversion -Wpedantic -Wextra)

    add_test( NAME TestGuardedBookkeeping COMMAND testGuardedBookkeeping )
  endif()
endif()

#print_all_variables()
