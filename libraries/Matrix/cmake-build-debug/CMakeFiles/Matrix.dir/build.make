# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Matrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matrix.dir/flags.make

CMakeFiles/Matrix.dir/library.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/library.cpp.obj: ../library.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Matrix.dir/library.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Matrix.dir\library.cpp.obj -c C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\library.cpp

CMakeFiles/Matrix.dir/library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/library.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\library.cpp > CMakeFiles\Matrix.dir\library.cpp.i

CMakeFiles/Matrix.dir/library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/library.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\library.cpp -o CMakeFiles\Matrix.dir\library.cpp.s

CMakeFiles/Matrix.dir/library.cpp.obj.requires:

.PHONY : CMakeFiles/Matrix.dir/library.cpp.obj.requires

CMakeFiles/Matrix.dir/library.cpp.obj.provides: CMakeFiles/Matrix.dir/library.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Matrix.dir\build.make CMakeFiles/Matrix.dir/library.cpp.obj.provides.build
.PHONY : CMakeFiles/Matrix.dir/library.cpp.obj.provides

CMakeFiles/Matrix.dir/library.cpp.obj.provides.build: CMakeFiles/Matrix.dir/library.cpp.obj


CMakeFiles/Matrix.dir/Matrix.cpp.obj: CMakeFiles/Matrix.dir/flags.make
CMakeFiles/Matrix.dir/Matrix.cpp.obj: ../Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Matrix.dir/Matrix.cpp.obj"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Matrix.dir\Matrix.cpp.obj -c C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\Matrix.cpp

CMakeFiles/Matrix.dir/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matrix.dir/Matrix.cpp.i"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\Matrix.cpp > CMakeFiles\Matrix.dir\Matrix.cpp.i

CMakeFiles/Matrix.dir/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matrix.dir/Matrix.cpp.s"
	C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\Matrix.cpp -o CMakeFiles\Matrix.dir\Matrix.cpp.s

CMakeFiles/Matrix.dir/Matrix.cpp.obj.requires:

.PHONY : CMakeFiles/Matrix.dir/Matrix.cpp.obj.requires

CMakeFiles/Matrix.dir/Matrix.cpp.obj.provides: CMakeFiles/Matrix.dir/Matrix.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Matrix.dir\build.make CMakeFiles/Matrix.dir/Matrix.cpp.obj.provides.build
.PHONY : CMakeFiles/Matrix.dir/Matrix.cpp.obj.provides

CMakeFiles/Matrix.dir/Matrix.cpp.obj.provides.build: CMakeFiles/Matrix.dir/Matrix.cpp.obj


# Object files for target Matrix
Matrix_OBJECTS = \
"CMakeFiles/Matrix.dir/library.cpp.obj" \
"CMakeFiles/Matrix.dir/Matrix.cpp.obj"

# External object files for target Matrix
Matrix_EXTERNAL_OBJECTS =

libMatrix.a: CMakeFiles/Matrix.dir/library.cpp.obj
libMatrix.a: CMakeFiles/Matrix.dir/Matrix.cpp.obj
libMatrix.a: CMakeFiles/Matrix.dir/build.make
libMatrix.a: CMakeFiles/Matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libMatrix.a"
	$(CMAKE_COMMAND) -P CMakeFiles\Matrix.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Matrix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matrix.dir/build: libMatrix.a

.PHONY : CMakeFiles/Matrix.dir/build

CMakeFiles/Matrix.dir/requires: CMakeFiles/Matrix.dir/library.cpp.obj.requires
CMakeFiles/Matrix.dir/requires: CMakeFiles/Matrix.dir/Matrix.cpp.obj.requires

.PHONY : CMakeFiles/Matrix.dir/requires

CMakeFiles/Matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Matrix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Matrix.dir/clean

CMakeFiles/Matrix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug C:\Users\nicot\OneDrive\Robotica\maze-bot\libraries\Matrix\cmake-build-debug\CMakeFiles\Matrix.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Matrix.dir/depend

