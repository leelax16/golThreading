# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\ndlee\Dev\golThread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\ndlee\Dev\golThread\build

# Include any dependencies generated for this target.
include program_files/CMakeFiles/program_files.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include program_files/CMakeFiles/program_files.dir/compiler_depend.make

# Include the progress variables for this target.
include program_files/CMakeFiles/program_files.dir/progress.make

# Include the compile flags for this target's objects.
include program_files/CMakeFiles/program_files.dir/flags.make

program_files/CMakeFiles/program_files.dir/world.cpp.obj: program_files/CMakeFiles/program_files.dir/flags.make
program_files/CMakeFiles/program_files.dir/world.cpp.obj: program_files/CMakeFiles/program_files.dir/includes_CXX.rsp
program_files/CMakeFiles/program_files.dir/world.cpp.obj: C:/Users/ndlee/Dev/golThread/program_files/world.cpp
program_files/CMakeFiles/program_files.dir/world.cpp.obj: program_files/CMakeFiles/program_files.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\ndlee\Dev\golThread\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object program_files/CMakeFiles/program_files.dir/world.cpp.obj"
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT program_files/CMakeFiles/program_files.dir/world.cpp.obj -MF CMakeFiles\program_files.dir\world.cpp.obj.d -o CMakeFiles\program_files.dir\world.cpp.obj -c C:\Users\ndlee\Dev\golThread\program_files\world.cpp

program_files/CMakeFiles/program_files.dir/world.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/program_files.dir/world.cpp.i"
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\ndlee\Dev\golThread\program_files\world.cpp > CMakeFiles\program_files.dir\world.cpp.i

program_files/CMakeFiles/program_files.dir/world.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/program_files.dir/world.cpp.s"
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\ndlee\Dev\golThread\program_files\world.cpp -o CMakeFiles\program_files.dir\world.cpp.s

# Object files for target program_files
program_files_OBJECTS = \
"CMakeFiles/program_files.dir/world.cpp.obj"

# External object files for target program_files
program_files_EXTERNAL_OBJECTS =

program_files/libprogram_files.a: program_files/CMakeFiles/program_files.dir/world.cpp.obj
program_files/libprogram_files.a: program_files/CMakeFiles/program_files.dir/build.make
program_files/libprogram_files.a: program_files/CMakeFiles/program_files.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\ndlee\Dev\golThread\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libprogram_files.a"
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && $(CMAKE_COMMAND) -P CMakeFiles\program_files.dir\cmake_clean_target.cmake
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\program_files.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
program_files/CMakeFiles/program_files.dir/build: program_files/libprogram_files.a
.PHONY : program_files/CMakeFiles/program_files.dir/build

program_files/CMakeFiles/program_files.dir/clean:
	cd /d C:\Users\ndlee\Dev\golThread\build\program_files && $(CMAKE_COMMAND) -P CMakeFiles\program_files.dir\cmake_clean.cmake
.PHONY : program_files/CMakeFiles/program_files.dir/clean

program_files/CMakeFiles/program_files.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\ndlee\Dev\golThread C:\Users\ndlee\Dev\golThread\program_files C:\Users\ndlee\Dev\golThread\build C:\Users\ndlee\Dev\golThread\build\program_files C:\Users\ndlee\Dev\golThread\build\program_files\CMakeFiles\program_files.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : program_files/CMakeFiles/program_files.dir/depend

