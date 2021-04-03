cmake_minimum_required(VERSION 3.17.5)
project(CMakePlayground VERSION 0.1.0 LANGUAGES CXX)

if (POLICY CMP0054)
	cmake_policy(SET CMP0054 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmakePlayground BitManipulation.cpp)

# function, foreach, macro
function(myfunc num1 num2)			# Passed by value by default
	set(${num1} 16 PARENT_SCOPE)
	message(STATUS "ARGC: " ${ARGC})
	foreach(arg IN LISTS ARGV)
		message(STATUS ${arg})
	endforeach()
endfunction()

macro(mymacro arg1 arg2)			# Passed by reference by default
	set(${arg1} 155)
endmacro()

function(loopfunc a b)
message(STATUS "### loopfunc start ###")
	foreach(arg IN LISTS ARGV)
		message(STATUS ${arg})
	endforeach()
	foreach(arg IN LISTS ARGN)
		message(STATUS ${arg})
	endforeach()
message(STATUS "### loopfunc end ###")
endfunction()


set(mynum 15)
message(STATUS "Before myfunc: " ${mynum})
myfunc(mynum 2)
message(STATUS "After myfunc: " ${mynum})

message(STATUS "Before mymacro: " ${mynum})
mymacro(mynum 3)
message(STATUS "After mymacro: " ${mynum})

loopfunc(1 2 3 4 5)



foreach(var a;b;c)
	message(STATUS ${var})
endforeach()

foreach(var RANGE 1 3)
	message(STATUS ${var})
endforeach()

### Zip list ###
list(APPEND English one two three four)
list(APPEND Bahasa satu dua tiga)

foreach(en ba IN ZIP_LISTS English Bahasa)
	message(STATUS "en=${en}, ba=${ba}")
endforeach()


set(MyList d;f;g)
message(STATUS ${MyList})


### Configuration files ###
configure_file(foo.h.in ${CMAKE_CURRENT_SOURCE_DIR}/foo.h)

### Working with files ###
file(STRINGS WorkingWithFiles.txt FileVar NEWLINE_CONSUME ENCODING UTF-8)
message(STATUS ${FileVar})

file(SHA256 ${CMAKE_CURRENT_SOURCE_DIR}/WorkingWithFiles.txt FileHash)
message(STATUS "Hash of the file: " ${FileHash})

# file(APPEND WorkingWithFiles.txt "\n" ${FileHash})

file(MAKE_DIRECTORY  ${CMAKE_CURRENT_SOURCE_DIR}/TempDir)

# file(REAL_PATH "WorkingWithFiles.txt" AbsolutePath)
# message(STATUS ${AbsolutePath})

# file(LOCK WorkingWithFiles.txt TIMEOUT 10)

### Running a command at configure time ###
find_package(Git REQUIRED)
message(STATUS ${GIT_EXECUTABLE})
execute_process(COMMAND ${GIT_EXECUTABLE} branch
				WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
				OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE CurrentBranch)

message(STATUS "CurrentBranch: " ${CurrentBranch})

### Running a command at build time ###
find_package(Python3 REQUIRED)
message(STATUS ${Python3_EXECUTABLE})

### Compiler features ###
# Print compiler features
get_property(cxx_known_features GLOBAL PROPERTY CMAKE_CXX_KNOWN_FEATURES)
list(LENGTH cxx_known_features cxx_known_features_lenght)
message(STATUS "CXX known features: Size ${cxx_known_features_lenght}")
#foreach(feature ${cxx_known_features})
#	message(STATUS ${feature})
#endforeach()

list(LENGTH CMAKE_CXX_COMPILE_FEATURES cxx_compile_features_lenght)
message(STATUS "CMAKE_CXX_COMPILE_FEATURES size: " ${cxx_compile_features_lenght})


### Useful Modules ###
include(CMakePrintHelpers)
cmake_print_properties(TARGETS cmakePlayground PROPERTIES CXX_STANDARD CXX_STANDARD_REQUIRED)
cmake_print_variables(mynum CMAKE_CXX_COMPILER PROJECT_VERSION)

include(CheckCXXCompilerFlag)
unset(CHECK_RESULT CACHE)
check_cxx_compiler_flag(/wd4018 CHECK_RESULT)
message(STATUS ${CHECK_RESULT})

# try_compile(RESULT_VAR ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR} CMakePlayground cmakePlayground)
# message(STATUS "Result of try_compile: " ${RESULT_VAR})
# try_compile(RESULT_VAR ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/BitManipulation.cpp)
# message(STATUS "Result of try_compile: " ${RESULT_VAR})

### There are default debug and release flags ###
message(STATUS "CMAKE_CXX_FLAGS_DEBUG=" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "CMAKE_CXX_FLAGS_DEBUG_INIT=" ${CMAKE_CXX_FLAGS_DEBUG_INIT})

message(STATUS "CMAKE_CXX_FLAGS_RELEASE=" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "CMAKE_CXX_FLAGS_RELEASE_INIT=" ${CMAKE_CXX_FLAGS_RELEASE_INIT})

message(STATUS "CMAKE_CXX_FLAGS=" ${CMAKE_CXX_FLAGS})

### Policies ###
cmake_policy(SET CMP0097 NEW)
# cmake_policy(SET CMP0114 NEW)

### FetchContent ###
include(FetchContent)
FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        release-1.8.1
)
FetchContent_Declare(
		myCompanyIcons
		URL https://dotsrc.dl.osdn.net/osdn/crystaldiskmark/71859/CrystalDiskMark7_0_0h.zip
		URL_HASH MD5=9BE11F22A3EDB8D8AAA2FD4C0E5CD898
)

FetchContent_MakeAvailable(googletest myCompanyIcons)
# target_link_libraries(cmakePlayground gtest)

FetchContent_GetProperties(googletest)
message(STATUS ${googletest_POPULATED})
message(STATUS ${googletest_SOURCE_DIR})

cmake_policy(PUSH)
cmake_policy(SET CMP0003 OLD) # use old-style link directories for now
target_link_libraries(cmakePlayground googletest)
cmake_policy(POP)

# Math
set(x 3)
set(y 7)
math(EXPR result "(${x} + ${y}) / 2")
message(STATUS "Result of math: " ${result})

### Query properties ###
get_cmake_property(variables VARIABLES)
message(STATUS ${variables})

get_directory_property(dir_prop SUBDIRECTORIES)
message(STATUS ${dir_prop})

get_target_property(targ_prop cmakePlayground CXX_STANDARD)
message(STATUS ${targ_prop})

# Evaluate file with both - variables and generator expresion
add_executable(net_packer BitManipulation.cpp)

set(NN_FILES a b c)
set(PACK_NET_OUTPUT out.sh)

string (REPLACE ";" " " NN_FILES_STR "${NN_FILES}")

configure_file(pack_net.in ${CMAKE_CURRENT_SOURCE_DIR}/pack_net.out)

file(GENERATE
	OUTPUT ${CMAKE_SOURCE_DIR}/pack_net.out
	INPUT ${CMAKE_SOURCE_DIR}/pack_net.out
	)

