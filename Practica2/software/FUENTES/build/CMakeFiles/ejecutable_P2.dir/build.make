# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build

# Include any dependencies generated for this target.
include CMakeFiles/ejecutable_P2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ejecutable_P2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ejecutable_P2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ejecutable_P2.dir/flags.make

CMakeFiles/ejecutable_P2.dir/src/main.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/ejecutable_P2.dir/src/main.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/main.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/main.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/main.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/main.cpp

CMakeFiles/ejecutable_P2.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/main.cpp > CMakeFiles/ejecutable_P2.dir/src/main.cpp.i

CMakeFiles/ejecutable_P2.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/main.cpp -o CMakeFiles/ejecutable_P2.dir/src/main.cpp.s

CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o: ../src/LecturaFicheros.cpp
CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/LecturaFicheros.cpp

CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/LecturaFicheros.cpp > CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.i

CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/LecturaFicheros.cpp -o CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.s

CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o: ../src/AM.cpp
CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AM.cpp

CMakeFiles/ejecutable_P2.dir/src/AM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/AM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AM.cpp > CMakeFiles/ejecutable_P2.dir/src/AM.cpp.i

CMakeFiles/ejecutable_P2.dir/src/AM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/AM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AM.cpp -o CMakeFiles/ejecutable_P2.dir/src/AM.cpp.s

CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o: ../src/AGG.cpp
CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGG.cpp

CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGG.cpp > CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.i

CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGG.cpp -o CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.s

CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o: ../src/AGE.cpp
CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGE.cpp

CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGE.cpp > CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.i

CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/AGE.cpp -o CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.s

CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o: CMakeFiles/ejecutable_P2.dir/flags.make
CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o: ../src/BL.cpp
CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o: CMakeFiles/ejecutable_P2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o -MF CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o.d -o CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o -c /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/BL.cpp

CMakeFiles/ejecutable_P2.dir/src/BL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejecutable_P2.dir/src/BL.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/BL.cpp > CMakeFiles/ejecutable_P2.dir/src/BL.cpp.i

CMakeFiles/ejecutable_P2.dir/src/BL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejecutable_P2.dir/src/BL.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/src/BL.cpp -o CMakeFiles/ejecutable_P2.dir/src/BL.cpp.s

# Object files for target ejecutable_P2
ejecutable_P2_OBJECTS = \
"CMakeFiles/ejecutable_P2.dir/src/main.cpp.o" \
"CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o" \
"CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o" \
"CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o" \
"CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o" \
"CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o"

# External object files for target ejecutable_P2
ejecutable_P2_EXTERNAL_OBJECTS =

/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/main.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/LecturaFicheros.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/AM.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/AGG.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/AGE.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/src/BL.cpp.o
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/build.make
/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2: CMakeFiles/ejecutable_P2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ejecutable_P2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ejecutable_P2.dir/build: /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/BIN/ejecutable_P2
.PHONY : CMakeFiles/ejecutable_P2.dir/build

CMakeFiles/ejecutable_P2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ejecutable_P2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ejecutable_P2.dir/clean

CMakeFiles/ejecutable_P2.dir/depend:
	cd /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build /home/jose/Asignaturas3_2Cuatri/MH/Practicas/practica2/software/FUENTES/build/CMakeFiles/ejecutable_P2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ejecutable_P2.dir/depend

