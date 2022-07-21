# Name: Steven Song 
# UVA ID: sqs5hrn
# Date: April 27, 2021
# CS2150 Lab 10 In Lab Makefile

# Defines the C++ compiler we'll be using in our files 
CXX = clang++ -m64

# Defines the flags we'll be passing to the C++ compile
CXXFLAGS = -Wall -g

# Defines the assembler                                                        
AS = nasm

# Defines the flags for the assembler                                          
ASFLAGS = -f elf64 -g

# All of the .o files for our program (This is the only part that we have to change in our Makefile for the In Lab in Lab 10)

# NOTE: We do NOT need to include heap.o for the In Lab because the heap class is not necessary for completing the In Lab, as the PDR describes it 

OBJECTFILES = HuffmanNode.o huffmandec.o 

# This tells make to create a .o file from a .cpp file, using the              
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# Compiles our files into the main
main:	$(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not). This removes object files (*.o) and Emacs
# backup files (*~)

clean:
	/bin/rm -f *.o *~
