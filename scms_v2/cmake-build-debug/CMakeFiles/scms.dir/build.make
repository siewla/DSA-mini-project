# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/siewla/Desktop/DSA-mini-project/scms_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scms.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/scms.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/scms.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scms.dir/flags.make

CMakeFiles/scms.dir/main.cpp.o: CMakeFiles/scms.dir/flags.make
CMakeFiles/scms.dir/main.cpp.o: /Users/siewla/Desktop/DSA-mini-project/scms_v2/main.cpp
CMakeFiles/scms.dir/main.cpp.o: CMakeFiles/scms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scms.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scms.dir/main.cpp.o -MF CMakeFiles/scms.dir/main.cpp.o.d -o CMakeFiles/scms.dir/main.cpp.o -c /Users/siewla/Desktop/DSA-mini-project/scms_v2/main.cpp

CMakeFiles/scms.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scms.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siewla/Desktop/DSA-mini-project/scms_v2/main.cpp > CMakeFiles/scms.dir/main.cpp.i

CMakeFiles/scms.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scms.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siewla/Desktop/DSA-mini-project/scms_v2/main.cpp -o CMakeFiles/scms.dir/main.cpp.s

CMakeFiles/scms.dir/src/student.cpp.o: CMakeFiles/scms.dir/flags.make
CMakeFiles/scms.dir/src/student.cpp.o: /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/student.cpp
CMakeFiles/scms.dir/src/student.cpp.o: CMakeFiles/scms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/scms.dir/src/student.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scms.dir/src/student.cpp.o -MF CMakeFiles/scms.dir/src/student.cpp.o.d -o CMakeFiles/scms.dir/src/student.cpp.o -c /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/student.cpp

CMakeFiles/scms.dir/src/student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scms.dir/src/student.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/student.cpp > CMakeFiles/scms.dir/src/student.cpp.i

CMakeFiles/scms.dir/src/student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scms.dir/src/student.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/student.cpp -o CMakeFiles/scms.dir/src/student.cpp.s

CMakeFiles/scms.dir/src/course.cpp.o: CMakeFiles/scms.dir/flags.make
CMakeFiles/scms.dir/src/course.cpp.o: /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/course.cpp
CMakeFiles/scms.dir/src/course.cpp.o: CMakeFiles/scms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/scms.dir/src/course.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scms.dir/src/course.cpp.o -MF CMakeFiles/scms.dir/src/course.cpp.o.d -o CMakeFiles/scms.dir/src/course.cpp.o -c /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/course.cpp

CMakeFiles/scms.dir/src/course.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scms.dir/src/course.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/course.cpp > CMakeFiles/scms.dir/src/course.cpp.i

CMakeFiles/scms.dir/src/course.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scms.dir/src/course.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/course.cpp -o CMakeFiles/scms.dir/src/course.cpp.s

CMakeFiles/scms.dir/src/studentList.cpp.o: CMakeFiles/scms.dir/flags.make
CMakeFiles/scms.dir/src/studentList.cpp.o: /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/studentList.cpp
CMakeFiles/scms.dir/src/studentList.cpp.o: CMakeFiles/scms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/scms.dir/src/studentList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scms.dir/src/studentList.cpp.o -MF CMakeFiles/scms.dir/src/studentList.cpp.o.d -o CMakeFiles/scms.dir/src/studentList.cpp.o -c /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/studentList.cpp

CMakeFiles/scms.dir/src/studentList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scms.dir/src/studentList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/studentList.cpp > CMakeFiles/scms.dir/src/studentList.cpp.i

CMakeFiles/scms.dir/src/studentList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scms.dir/src/studentList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/studentList.cpp -o CMakeFiles/scms.dir/src/studentList.cpp.s

CMakeFiles/scms.dir/src/courseList.cpp.o: CMakeFiles/scms.dir/flags.make
CMakeFiles/scms.dir/src/courseList.cpp.o: /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/courseList.cpp
CMakeFiles/scms.dir/src/courseList.cpp.o: CMakeFiles/scms.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/scms.dir/src/courseList.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/scms.dir/src/courseList.cpp.o -MF CMakeFiles/scms.dir/src/courseList.cpp.o.d -o CMakeFiles/scms.dir/src/courseList.cpp.o -c /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/courseList.cpp

CMakeFiles/scms.dir/src/courseList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/scms.dir/src/courseList.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/courseList.cpp > CMakeFiles/scms.dir/src/courseList.cpp.i

CMakeFiles/scms.dir/src/courseList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/scms.dir/src/courseList.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/siewla/Desktop/DSA-mini-project/scms_v2/src/courseList.cpp -o CMakeFiles/scms.dir/src/courseList.cpp.s

# Object files for target scms
scms_OBJECTS = \
"CMakeFiles/scms.dir/main.cpp.o" \
"CMakeFiles/scms.dir/src/student.cpp.o" \
"CMakeFiles/scms.dir/src/course.cpp.o" \
"CMakeFiles/scms.dir/src/studentList.cpp.o" \
"CMakeFiles/scms.dir/src/courseList.cpp.o"

# External object files for target scms
scms_EXTERNAL_OBJECTS =

scms: CMakeFiles/scms.dir/main.cpp.o
scms: CMakeFiles/scms.dir/src/student.cpp.o
scms: CMakeFiles/scms.dir/src/course.cpp.o
scms: CMakeFiles/scms.dir/src/studentList.cpp.o
scms: CMakeFiles/scms.dir/src/courseList.cpp.o
scms: CMakeFiles/scms.dir/build.make
scms: CMakeFiles/scms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable scms"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scms.dir/build: scms
.PHONY : CMakeFiles/scms.dir/build

CMakeFiles/scms.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scms.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scms.dir/clean

CMakeFiles/scms.dir/depend:
	cd /Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siewla/Desktop/DSA-mini-project/scms_v2 /Users/siewla/Desktop/DSA-mini-project/scms_v2 /Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug /Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug /Users/siewla/Desktop/DSA-mini-project/scms_v2/cmake-build-debug/CMakeFiles/scms.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/scms.dir/depend

