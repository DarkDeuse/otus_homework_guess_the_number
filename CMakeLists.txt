cmake_minimum_required(VERSION 3.5)

project(guess_the_number)

add_executable(guess_the_number
			  guess_the_number.cpp
			  random_value.cpp
			  random_value.h
			  file_worker.cpp
			  file_worker.h
			  game_back.cpp
			  game_back.h

)

set_target_properties(guess_the_number PROPERTIES 
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

target_compile_options(guess_the_number PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

target_compile_options(guess_the_number PRIVATE /EHsc /W4 /WX)

endif()