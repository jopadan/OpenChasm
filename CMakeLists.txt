cmake_minimum_required(VERSION 3.1)

project(OpenChasm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(CheckCXXSourceCompiles)
include(GNUInstallDirs)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

if(MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /D _CRT_SECURE_NO_WARNINGS /MP")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D _CRT_SECURE_NO_WARNINGS /MP")
endif()

option(BUILD_TOOLS "Enable compilation of tools" YES)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/physfs)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/tinygltf)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${CMAKE_CURRENT_SOURCE_DIR}/external/whmath
	${CMAKE_CURRENT_SOURCE_DIR}/external/physfs/src
	${CMAKE_CURRENT_SOURCE_DIR}/external/tinygltf)

# Source and header files
file(GLOB_RECURSE CHASM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE CHASM_HEADERS 
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/*.inl"
	"${CMAKE_CURRENT_SOURCE_DIR}/external/whmath/*.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/external/physfs/src/*.h"
	"${CMAKE_CURRENT_SOURCE_DIR}/external/tinygltf/*.h")

# Detect MMX support

set(SAFE_CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmmx")
endif()

CHECK_CXX_SOURCE_COMPILES("#include <mmintrin.h>
	int main(void) { __m64 v = _m_from_int(0); }"
	HAVE_MMX)

if(HAVE_MMX)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPC_MMX_INSTRUCTIONS")
else()
	set(CMAKE_CXX_FLAGS "${SAFE_CMAKE_CXX_FLAGS}")
endif()

# Configure libraries

set(CHASM_LIBS
	${SDL2_LIBRARY}
	physfs
	tinygltf
)

if(WIN32)
	set(CHASM_LIBS
		${CHASM_LIBS}
		opengl32
		ws2_32
	)
	set(CHASM_RESOURCES
		res/OpenChasm.rc
	)
else()
	set(CHASM_LIBS
		${CHASM_LIBS}
		GL
		AL
	)
endif()

# Configure executable
add_executable(${PROJECT_NAME} ${CHASM_SOURCES} ${CHASM_HEADERS} ${CHASM_RESOURCES})
target_link_libraries(${PROJECT_NAME} ${CHASM_LIBS})

# Configure tools
if(BUILD_TOOLS)
	file(GLOB_RECURSE COMMON_FILES "${CMAKE_CURRENT_SOURCE_DIR}/tools/*.cpp") 

add_executable(ps10
	${CMAKE_CURRENT_SOURCE_DIR}/tools/ps10.cpp
	${COMMON_FILES}
)
endif(BUILD_TOOLS)

