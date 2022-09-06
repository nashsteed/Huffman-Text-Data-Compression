# Nash Steed _ ucq8hz _ Apr 17 2022 _ Makefile
# This Makefile shows how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX = clang++
CXXFLAGS=-Wall 
DEBUG=-g

OBJECTS = huffmandec.o huffnode.o 

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

huffmanenc.o: huffmandec.cpp
huffnode.o: huffnode.cpp huffnode.h

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~