# Name: Steven Song 
# UVA ID: sqs5hrn
# Date: May 2, 2021  
# CS2150 Lab 11 Pre Lab Makefile

# Defines the C++ compiler we'll be using in our files 
CXX = clang++ -m64

# Defines the flags we'll be passing to the C++ compile
CXXFLAGS = -Wall -g

# Defines the assembler                                                        
AS = nasm

# Defines the flags for the assembler                                          
ASFLAGS = -f elf64 -g

# All of the .o files for our program (This is the only part that we have to change in our Makefile for the Pre Lab in Lab 11) 

# Apparently, topological.cpp is separate from middleearth.h and middleearth.cpp (middleearth.h and middleearth.cpp are just there to help you understand the documentation for doxygen) so we only have to include topological.o under OBJECTFILES since it's the only file that we're actually using to perform the topological sort and to run/print its output  

OBJECTFILES = topological.o  

# This tells make to create a .o file from a .cpp file, using the              
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# Compiles our files into the main
main:	$(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)
	doxygen 

# doxygen has to be on its own line since we want to run doxygen in addition to compiling our code

# Not only will the Makefile compile our code, it will also generate the doxygen documentation 

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not). This removes object files (*.o) and Emacs
# backup files (*~)

clean:
	/bin/rm -f *.o *~
