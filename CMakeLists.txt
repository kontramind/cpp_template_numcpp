cmake_minimum_required(VERSION 3.15)

find_package(Boost 1.72.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Set the project name to your project name, my project isn't very descriptive
project(myproject CXX)
include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# # enable doxygen
# include(cmake/Doxygen.cmake)
# enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
# option(ENABLE_TESTING "Enable Test Builds" ON)
# option(CPP_ENABLE_NUMCPP "Enable compilation of NumCpp" OFF)

# # Very basic PCH example
# option(ENABLE_PCH "Enable Precompiled Headers" OFF)
# if (ENABLE_PCH)
#   # This sets a global PCH parameter, each project will build its own PCH, which
#   # is a good idea if any #define's change
#   # 
#   # 
#   target_precompile_headers(project_options INTERFACE <vector> <string> <map> <utility>)
# endif()


# Set up some extra Conan dependencies based on our needs
# before loading Conan
# set(CONAN_EXTRA_REQUIRES "")
# set(CONAN_EXTRA_OPTIONS "")
# set(CONAN_EXTRA_REQUIRES ${CONAN_EXTRA_REQUIRES}
#   boost/1.69.0@conan/stable
# )

# include(cmake/Conan.cmake)
# run_conan()

add_subdirectory(extern/Catch2)
add_subdirectory(extern/NumCpp)

# if(ENABLE_TESTING)
#   enable_testing()
#   message(
#     "Building Tests. Be sure to check out test/constexpr_tests for constexpr testing"
#   )
#   add_subdirectory(test)
# endif()

# if(ENABLE_FUZZING)
#   message(
#     "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html"
#   )
#   add_subdirectory(fuzz_test)
# endif()


add_subdirectory(src)
