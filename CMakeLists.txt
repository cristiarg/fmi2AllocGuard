cmake_minimum_required (VERSION 3.0)

macro(print_all_variables)
  message(STATUS "print_all_variables------------------------------------------{")
  get_cmake_property(_variableNames VARIABLES)
  foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
  endforeach()
  message(STATUS "print_all_variables------------------------------------------}")
endmacro()

project (fmi2AllocGuard LANGUAGES CXX)

# tune some cmake options
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RULE_MESSAGES ON)

#########################################
# compiler options
#########################################

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if( CMAKE_CXX_COMPILER_ID STREQUAL "GNU" )
  #message( STATUS "compiler id = 'GNU'" )
elseif( CMAKE_CXX_COMPILER_ID STREQUAL "MSVC" )
  #message( STATUS "compiler id = 'MSVC'" )
endif()

#########################################
# library
#########################################

set(FMI2AG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/inc")
set(FMI2AG_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

set(FMI2AG_FILES_HEADERS_PUBLIC
  ${FMI2AG_INCLUDE_DIR}/fmi2Export.h
  ${FMI2AG_INCLUDE_DIR}/fmi2Defines.h
  ${FMI2AG_INCLUDE_DIR}/fmi2AllocGuard.h )

set(FMI2AG_FILES_HEADERS_PRIVATE
  ${FMI2AG_SOURCE_DIR}/GuardedBookkeeping.hpp
  ${FMI2AG_SOURCE_DIR}/PointerKeeper.hpp )

set(FMI2AG_FILES_CODE
  ${FMI2AG_SOURCE_DIR}/GuardedBookkeeping.cpp
  ${FMI2AG_SOURCE_DIR}/PointerKeeper.cpp
  ${FMI2AG_SOURCE_DIR}/fmi2AllocGuard.cpp )

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

option(FMI2AG_TESTS "Build tests for fmi2AllocGuard. Default: ON" ON)
if ( FMI2AG_TESTS )
  enable_testing()

  set(FMI2AG_FETCH_CATCH
      GIT_REPOSITORY https://github.com/catchorg/Catch2
      GIT_TAG c32f275a008a50ae058fcd8a43f0c387d90c929b )
    # fetching Catch1.x branch

  include(ExternalProject)

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

  # implementation detail includes
  include_directories("${PROJECT_SOURCE_DIR}/src")

  set(FMI2AG_TST_DIR "${PROJECT_SOURCE_DIR}/tst")
  file(GLOB_RECURSE unit_test_sources "${FMI2AG_TST_DIR}/*.c" "${FMI2AG_TST_DIR}/*.cpp")

  add_executable(testFmi2AllocGuard ${unit_test_sources})
  target_link_libraries(testFmi2AllocGuard PUBLIC fmi2AllocGuard Catch)
  target_include_directories(testFmi2AllocGuard PUBLIC ${FMI2AG_TST_DIR})

  ##add_subdirectory(${PROJECT_SOURCE_DIR}/lib/Catch2)
  ##find_package(Catch2 REQUIRED)

  ## needed because both .c and .cpp code files are present
  ##set_target_properties( testFmi2AllocGuard PROPERTIES LINKER_LANGUAGE C)
  ##set_source_files_properties("${PROJECT_SOURCE_DIR}/tst/*.cpp" PROPERTIES LANGUAGE C )

  target_compile_options(testFmi2AllocGuard PUBLIC -Wall -Wfloat-conversion -Wpedantic -Wextra)

  add_test(NAME Test1 COMMAND testFmi2AllocGuard)
endif()

#print_all_variables()
