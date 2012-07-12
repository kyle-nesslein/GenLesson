#######################################
# CMAKE websightxml
#######################################
project(websightxml)
cmake_minimum_required(VERSION 2.4)

if(UNIX)
	#add_definitions(-Wall -DGCC -g)
	add_definitions(-DGCC -g)
endif(UNIX)

if(APPLE)
	set (CMAKE_OSX_ARCHITECTURES "i386 ppc")
	set (CMAKE_OSX_SYSROOT /Developer/SDKs/MacOSX10.4u.sdk)
	set (CMAKE_C++_FLAGS -mmacosx-version-min=10.4)
endif(APPLE)

if(WIN32)
 add_definitions(-DWINVER=0x0400 -DWIN32)
 if(${CMAKE_GENERATOR} STREQUAL "Visual Studio 6")
  add_definitions(-DVC6)
 elseif(${CMAKE_GENERATOR} STREQUAL "Visual Studio 8 2005")
  add_definitions(-DVC2005)
 endif(${CMAKE_GENERATOR} STREQUAL "Visual Studio 6")
endif(WIN32)

add_subdirectory(src)
