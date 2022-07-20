# Name: Steven Song 
# UVA ID: sqs5hrn 
# Date: April 21, 2021 
# CS2150 Lab 9 Post Lab Makefile 

CXX = clang++ -m64

# Defines the flags we'll be passing to the C++ compiler                       
CXXFLAGS = -Wall -g

# Defines the assembler                                                        
AS = nasm

# Defines the flags for the assembler                                          
ASFLAGS = -f elf64 -g

# All of the .o files for our program (This is the only part that we have to change in our Makefile for the Post Lab)                                         
OBJECTFILES = binarySearch.o testBinarySearch.o timer.o  

# Creates a .o file from a .cpp file, using the defaults CXX and CXXFLAGS
.SUFFIXES: .o .cpp

# Creates a .o file from a .s file, using the defaults AS and ASFLAGS
.SUFFIXES: .o .s

# The main will compile all of our files in our Post Lab into a.out

main:	$(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)

# This will clean up (remove) all our object files.  The -f option             
# tells rm to forcily remove the files (i.e. don't ask if they should          
# be removed or not).  This removes object files (*.o) and Emacs               
# backup files (*~)                                                            
clean:
	/bin/rm -f *.o *~
