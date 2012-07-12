

#######################################
# set directories, src and headers.
set (GENL 		${CMAKE_CURRENT_SOURCE_DIR})
set (SRC 	${GENL})

set (CORESRC "GenLesson.cpp lesson.cpp LibWrapper.cpp nchord.cpp note.cpp part.cpp voice.cpp")
#set (HEADERS "lesson.h LibWrapper.h nchord.h note.h voice.h part.h")
#message(src variable: ${CORESRC})
#message(headers vaiable: ${HEADERS})

#set_source_files_properties (${COREH} PROPERTIES HEADER_FILE_ONLY TRUE)
#foreach(folder ${SRCFOLDERS})
#	set(SRC ${SRC} "${LXMLSRC}/${folder}/*.cpp")			# add source files
#endforeach(folder)
file (GLOB CORESRC RELATIVE ${SRC} "*.cpp")


set(target GenLesson)

# Does nothing.
#include_directories (${SRC})
#link_directories (${SRC})


add_executable ( GenLesson ${CORESRC})

#Get limusicxml headers?
include_directories("/usr/local/include/libmusicxml")
link_directories("/usr/local/lib")
target_link_libraries(GenLesson "libmusicxml2.so")

