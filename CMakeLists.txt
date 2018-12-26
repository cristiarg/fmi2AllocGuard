cmake_minimum_required (VERSION 3.0)

project (fmi2AllocGuard LANGUAGES CXX)

# tune some cmake options
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RULE_MESSAGES ON)


#
# the shared library
#

file(GLOB_RECURSE shared_lib_sources "${PROJECT_SOURCE_DIR}/src/*.c" "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(fmi2AllocGuard SHARED ${shared_lib_sources})

# public includes
include_directories("${PROJECT_SOURCE_DIR}/inc")

# implementation detail includes
include_directories("${PROJECT_SOURCE_DIR}/src/inc")

#add_subdirectory("${PROJECT_SOURCE_DIR}/src" src )

# compilation flags
target_compile_options(fmi2AllocGuard PUBLIC -std=c++03 -Wall -Wfloat-conversion)

# needed because both .c and .cpp code files are present
#set_target_properties( fmi2AllocGuard PROPERTIES LINKER_LANGUAGE C)
  # seems this causes linking of empty binary; smth's missing maybe
  # or maybe it works in conjunction with "LANGUAGES C" above

# change the defined exports symbol - see inc/export.h
set_target_properties( fmi2AllocGuard PROPERTIES DEFINE_SYMBOL "FMI2ALLOCGUARD_DLL_EXPORTS")

#
# the unit test executable
#

## TODO: add a verification whether the lib/Catch2 actually exists
#
#file(GLOB_RECURSE unit_test_sources "${PROJECT_SOURCE_DIR}/tst/*.cpp")
#
#add_executable(testFmi2AllocGuard ${unit_test_sources})
#
#add_subdirectory(lib/Catch2)
#
#target_link_libraries(testFmi2AllocGuard Catch2::Catch2)
#
#target_compile_options(testFmi2AllocGuard PUBLIC -std=c++11 -Wall -Wfloat-conversion)

