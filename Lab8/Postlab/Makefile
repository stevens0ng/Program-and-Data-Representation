# Name: Steven Song 
# UVA ID: sqs5hrn 
# Date: April 14, 2021 
# CS2150 Lab 8 Post Lab Makefile

# This Makefile shows us how to link the assembly with C/C++
# Defines the C++ compiler we'll be using
CXX = clang++

# Defines the flags that will be passed into the C++ compiler
CXXFLAGS = -Wall -g

# Defines the assembler (NOTE: AS and ASFLAGS must be declared exactly the way they are: meaning that you can't call assembly "ASSEMBLY" Or flags "ASSEMBLERFLAG": you have to call it exactly the way it is) 
AS = nasm

# Defines the flags for the assembler (flags for nasm)
ASFLAGS = -f elf64 -g

# OBJECTFILES contains all of the .o files for the Post Lab
OBJECTFILES = linearSearch.o testLinearSearch.o 

# The .SUFFIXES is the only part that you have to add to this Makefile 
#.SUFFIXES creates an .o file from a .cpp file
.SUFFIXES: .o .cpp

#.SUFFIXES creates an .o file from a .s file
.SUFFIXES: .o .s 

#This will compile all of the files into the main, which we call in testLinearSearch.cpp 
main: $(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~
