

#all:
#	g++ -I src/include -L src/lib -o gol main.cpp -lmingw32 -lSDL2main -lSDL2

# Configure compiler settings
CXX=clang++
CXXFLAGS=-g -Wall 
# The object files for the program.
OFILES = map.o cell.o
# The header files for the program
HFILES = $(shell ls -1 *.h)
# define any directories containing header files other than /usr/include
#
INCLUDES = -Isrc/include  -I../include

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:

#LFLAGS = -Lsrc/lib  -L../lib
#LFLAGS = -Lsrc/lib 

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:

#LIBS = -lmingw32 -lSDL2main -lSDL2
#LIBS = -lSDL2main -lSDL2

# UnitTest++ keeps its object files in this directory.
UNITTEST_LIB = -lUnitTest++

all: main

# This target builds your main program.
main: $(HFILES) $(OFILES) main.o
#	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LFLAGS) -o $@ main.o $(OFILES) $(LIBS)
	$(CXX) $(CXXFLAGS) $(INCLUDES)  -o $@ main.o $(OFILES) 
# This target describes how to compile a .o file from a .cpp file.
%.o: %.cpp $(HFILES)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# This target deletes the temporary files we have built.
.PHONY: clean all
clean:
	rm -f *.o
	rm -f gol
