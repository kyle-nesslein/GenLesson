# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phobos/Musigen/GenLesson/trunk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phobos/Musigen/GenLesson/build

# Include any dependencies generated for this target.
include src/CMakeFiles/GenLesson.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/GenLesson.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/GenLesson.dir/flags.make

src/CMakeFiles/GenLesson.dir/GenLesson.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/GenLesson.o: /home/phobos/Musigen/GenLesson/trunk/src/GenLesson.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/GenLesson.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/GenLesson.o -c /home/phobos/Musigen/GenLesson/trunk/src/GenLesson.cpp

src/CMakeFiles/GenLesson.dir/GenLesson.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/GenLesson.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/GenLesson.cpp > CMakeFiles/GenLesson.dir/GenLesson.i

src/CMakeFiles/GenLesson.dir/GenLesson.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/GenLesson.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/GenLesson.cpp -o CMakeFiles/GenLesson.dir/GenLesson.s

src/CMakeFiles/GenLesson.dir/GenLesson.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/GenLesson.o.requires

src/CMakeFiles/GenLesson.dir/GenLesson.o.provides: src/CMakeFiles/GenLesson.dir/GenLesson.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/GenLesson.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/GenLesson.o.provides

src/CMakeFiles/GenLesson.dir/GenLesson.o.provides.build: src/CMakeFiles/GenLesson.dir/GenLesson.o
.PHONY : src/CMakeFiles/GenLesson.dir/GenLesson.o.provides.build

src/CMakeFiles/GenLesson.dir/voice.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/voice.o: /home/phobos/Musigen/GenLesson/trunk/src/voice.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/voice.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/voice.o -c /home/phobos/Musigen/GenLesson/trunk/src/voice.cpp

src/CMakeFiles/GenLesson.dir/voice.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/voice.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/voice.cpp > CMakeFiles/GenLesson.dir/voice.i

src/CMakeFiles/GenLesson.dir/voice.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/voice.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/voice.cpp -o CMakeFiles/GenLesson.dir/voice.s

src/CMakeFiles/GenLesson.dir/voice.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/voice.o.requires

src/CMakeFiles/GenLesson.dir/voice.o.provides: src/CMakeFiles/GenLesson.dir/voice.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/voice.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/voice.o.provides

src/CMakeFiles/GenLesson.dir/voice.o.provides.build: src/CMakeFiles/GenLesson.dir/voice.o
.PHONY : src/CMakeFiles/GenLesson.dir/voice.o.provides.build

src/CMakeFiles/GenLesson.dir/note.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/note.o: /home/phobos/Musigen/GenLesson/trunk/src/note.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/note.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/note.o -c /home/phobos/Musigen/GenLesson/trunk/src/note.cpp

src/CMakeFiles/GenLesson.dir/note.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/note.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/note.cpp > CMakeFiles/GenLesson.dir/note.i

src/CMakeFiles/GenLesson.dir/note.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/note.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/note.cpp -o CMakeFiles/GenLesson.dir/note.s

src/CMakeFiles/GenLesson.dir/note.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/note.o.requires

src/CMakeFiles/GenLesson.dir/note.o.provides: src/CMakeFiles/GenLesson.dir/note.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/note.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/note.o.provides

src/CMakeFiles/GenLesson.dir/note.o.provides.build: src/CMakeFiles/GenLesson.dir/note.o
.PHONY : src/CMakeFiles/GenLesson.dir/note.o.provides.build

src/CMakeFiles/GenLesson.dir/part.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/part.o: /home/phobos/Musigen/GenLesson/trunk/src/part.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/part.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/part.o -c /home/phobos/Musigen/GenLesson/trunk/src/part.cpp

src/CMakeFiles/GenLesson.dir/part.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/part.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/part.cpp > CMakeFiles/GenLesson.dir/part.i

src/CMakeFiles/GenLesson.dir/part.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/part.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/part.cpp -o CMakeFiles/GenLesson.dir/part.s

src/CMakeFiles/GenLesson.dir/part.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/part.o.requires

src/CMakeFiles/GenLesson.dir/part.o.provides: src/CMakeFiles/GenLesson.dir/part.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/part.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/part.o.provides

src/CMakeFiles/GenLesson.dir/part.o.provides.build: src/CMakeFiles/GenLesson.dir/part.o
.PHONY : src/CMakeFiles/GenLesson.dir/part.o.provides.build

src/CMakeFiles/GenLesson.dir/lesson.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/lesson.o: /home/phobos/Musigen/GenLesson/trunk/src/lesson.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/lesson.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/lesson.o -c /home/phobos/Musigen/GenLesson/trunk/src/lesson.cpp

src/CMakeFiles/GenLesson.dir/lesson.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/lesson.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/lesson.cpp > CMakeFiles/GenLesson.dir/lesson.i

src/CMakeFiles/GenLesson.dir/lesson.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/lesson.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/lesson.cpp -o CMakeFiles/GenLesson.dir/lesson.s

src/CMakeFiles/GenLesson.dir/lesson.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/lesson.o.requires

src/CMakeFiles/GenLesson.dir/lesson.o.provides: src/CMakeFiles/GenLesson.dir/lesson.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/lesson.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/lesson.o.provides

src/CMakeFiles/GenLesson.dir/lesson.o.provides.build: src/CMakeFiles/GenLesson.dir/lesson.o
.PHONY : src/CMakeFiles/GenLesson.dir/lesson.o.provides.build

src/CMakeFiles/GenLesson.dir/pitchset.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/pitchset.o: /home/phobos/Musigen/GenLesson/trunk/src/pitchset.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/pitchset.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/pitchset.o -c /home/phobos/Musigen/GenLesson/trunk/src/pitchset.cpp

src/CMakeFiles/GenLesson.dir/pitchset.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/pitchset.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/pitchset.cpp > CMakeFiles/GenLesson.dir/pitchset.i

src/CMakeFiles/GenLesson.dir/pitchset.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/pitchset.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/pitchset.cpp -o CMakeFiles/GenLesson.dir/pitchset.s

src/CMakeFiles/GenLesson.dir/pitchset.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/pitchset.o.requires

src/CMakeFiles/GenLesson.dir/pitchset.o.provides: src/CMakeFiles/GenLesson.dir/pitchset.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/pitchset.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/pitchset.o.provides

src/CMakeFiles/GenLesson.dir/pitchset.o.provides.build: src/CMakeFiles/GenLesson.dir/pitchset.o
.PHONY : src/CMakeFiles/GenLesson.dir/pitchset.o.provides.build

src/CMakeFiles/GenLesson.dir/nchord.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/nchord.o: /home/phobos/Musigen/GenLesson/trunk/src/nchord.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/nchord.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/nchord.o -c /home/phobos/Musigen/GenLesson/trunk/src/nchord.cpp

src/CMakeFiles/GenLesson.dir/nchord.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/nchord.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/nchord.cpp > CMakeFiles/GenLesson.dir/nchord.i

src/CMakeFiles/GenLesson.dir/nchord.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/nchord.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/nchord.cpp -o CMakeFiles/GenLesson.dir/nchord.s

src/CMakeFiles/GenLesson.dir/nchord.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/nchord.o.requires

src/CMakeFiles/GenLesson.dir/nchord.o.provides: src/CMakeFiles/GenLesson.dir/nchord.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/nchord.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/nchord.o.provides

src/CMakeFiles/GenLesson.dir/nchord.o.provides.build: src/CMakeFiles/GenLesson.dir/nchord.o
.PHONY : src/CMakeFiles/GenLesson.dir/nchord.o.provides.build

src/CMakeFiles/GenLesson.dir/LibWrapper.o: src/CMakeFiles/GenLesson.dir/flags.make
src/CMakeFiles/GenLesson.dir/LibWrapper.o: /home/phobos/Musigen/GenLesson/trunk/src/LibWrapper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/phobos/Musigen/GenLesson/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/GenLesson.dir/LibWrapper.o"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/GenLesson.dir/LibWrapper.o -c /home/phobos/Musigen/GenLesson/trunk/src/LibWrapper.cpp

src/CMakeFiles/GenLesson.dir/LibWrapper.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenLesson.dir/LibWrapper.i"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/phobos/Musigen/GenLesson/trunk/src/LibWrapper.cpp > CMakeFiles/GenLesson.dir/LibWrapper.i

src/CMakeFiles/GenLesson.dir/LibWrapper.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenLesson.dir/LibWrapper.s"
	cd /home/phobos/Musigen/GenLesson/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/phobos/Musigen/GenLesson/trunk/src/LibWrapper.cpp -o CMakeFiles/GenLesson.dir/LibWrapper.s

src/CMakeFiles/GenLesson.dir/LibWrapper.o.requires:
.PHONY : src/CMakeFiles/GenLesson.dir/LibWrapper.o.requires

src/CMakeFiles/GenLesson.dir/LibWrapper.o.provides: src/CMakeFiles/GenLesson.dir/LibWrapper.o.requires
	$(MAKE) -f src/CMakeFiles/GenLesson.dir/build.make src/CMakeFiles/GenLesson.dir/LibWrapper.o.provides.build
.PHONY : src/CMakeFiles/GenLesson.dir/LibWrapper.o.provides

src/CMakeFiles/GenLesson.dir/LibWrapper.o.provides.build: src/CMakeFiles/GenLesson.dir/LibWrapper.o
.PHONY : src/CMakeFiles/GenLesson.dir/LibWrapper.o.provides.build

# Object files for target GenLesson
GenLesson_OBJECTS = \
"CMakeFiles/GenLesson.dir/GenLesson.o" \
"CMakeFiles/GenLesson.dir/voice.o" \
"CMakeFiles/GenLesson.dir/note.o" \
"CMakeFiles/GenLesson.dir/part.o" \
"CMakeFiles/GenLesson.dir/lesson.o" \
"CMakeFiles/GenLesson.dir/pitchset.o" \
"CMakeFiles/GenLesson.dir/nchord.o" \
"CMakeFiles/GenLesson.dir/LibWrapper.o"

# External object files for target GenLesson
GenLesson_EXTERNAL_OBJECTS =

src/GenLesson: src/CMakeFiles/GenLesson.dir/GenLesson.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/voice.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/note.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/part.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/lesson.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/pitchset.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/nchord.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/LibWrapper.o
src/GenLesson: src/CMakeFiles/GenLesson.dir/build.make
src/GenLesson: src/CMakeFiles/GenLesson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable GenLesson"
	cd /home/phobos/Musigen/GenLesson/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GenLesson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/GenLesson.dir/build: src/GenLesson
.PHONY : src/CMakeFiles/GenLesson.dir/build

src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/GenLesson.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/voice.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/note.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/part.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/lesson.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/pitchset.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/nchord.o.requires
src/CMakeFiles/GenLesson.dir/requires: src/CMakeFiles/GenLesson.dir/LibWrapper.o.requires
.PHONY : src/CMakeFiles/GenLesson.dir/requires

src/CMakeFiles/GenLesson.dir/clean:
	cd /home/phobos/Musigen/GenLesson/build/src && $(CMAKE_COMMAND) -P CMakeFiles/GenLesson.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/GenLesson.dir/clean

src/CMakeFiles/GenLesson.dir/depend:
	cd /home/phobos/Musigen/GenLesson/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phobos/Musigen/GenLesson/trunk /home/phobos/Musigen/GenLesson/trunk/src /home/phobos/Musigen/GenLesson/build /home/phobos/Musigen/GenLesson/build/src /home/phobos/Musigen/GenLesson/build/src/CMakeFiles/GenLesson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/GenLesson.dir/depend

