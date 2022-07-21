# Name: Steven Song 
# UVA ID: sqs5hrn
# Date: May 3, 2021 
# CS2150 Lab 11 In Lab Makefile

# Defines the C++ compiler we'll be using in our files 
CXX = clang++ -m64

# Defines the flags we'll be passing to the C++ compile
CXXFLAGS = -Wall -g

# Defines the assembler                                                        
AS = nasm

# Defines the flags for the assembler                                          
ASFLAGS = -f elf64 -g

# All of the .o files for our program (This is the only part that we have to change in our Makefile for the In Lab in Lab 11) 

# In addition to including traveling.o, we have to include middleearth.o in our OBJECTFILES this time around since the middleearth class provides a number of methods that helps us write our brute-force solution in traveling.cpp. In particular, the middleearth.h and middleearth.cpp files contain a class that will create a random 2-D world, meaning it can pick a given number of cities and place them randomly in the world. (so in essence, the middleearth class is actually related to the traveling class this time around) 

OBJECTFILES = traveling.o middleearth.o   

# This tells make to create a .o file from a .cpp file, using the              
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# Compiles our files into the main
main:	$(OBJECTFILES)
	$(CXX) $(CXXFLAGS) $(OBJECTFILES)
	doxygen 

# doxygen has to be on its own line since we want to run doxygen in addition to compiling our code

# Not only will the Makefile compile our code, it will also generate the doxygen documentation (This part is the same as it was in the Pre Lab) 

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not). This removes object files (*.o) and Emacs
# backup files (*~)

clean:
	/bin/rm -f *.o *~
