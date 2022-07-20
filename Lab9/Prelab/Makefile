# Name: Steven Song 
# UVA ID: sqs5hrn
# Date: April 18, 2021 
# CS2150 Lab 9 Pre Lab Makefile

# This Makefile shows you how to link assembly with C/C++

# Defines the C++ compiler we'll be using
CXX = clang++ -m64

# Defines the flags we'll be passing to the C++ compiler
CXXFLAGS = -Wall -g

# Defines the assembler
AS = nasm

# Defines the flags for the assembler
ASFLAGS	= -f elf64 -g

# All of the .o files for our program (THIS IS THE ONLY PART THAT WE HAVE TO MODIFY IN OUR MAKEFILE)
OBJECTFILES = threexplusone.o threexinput.o timer.o

# Creates a .o file from a .cpp file, using the defaults CXX and CXXFLAGS
.SUFFIXES: .o .cpp

# Creates a .o file from a .s file, using the defaults AS and ASFLAGS
.SUFFIXES: .o .s

# The main will compile all of our files in our Pre Lab into a.out 
main:	$(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)

# This will clean up (remove) all our object files.
# The -f option tells rm to remove the files (i.e. it removes the object files (*.o) and backup files (*~)
clean:
	/bin/rm -f *.o *~
