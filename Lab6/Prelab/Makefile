# Name: Steven Song  
# UVA ID: sqs5hrn 
# Date: March 28, 2021   
# CS2150 Lab 6 Makefile  

CXX = clang++
CXXFLAGS = -Wall -O2
# DEBUG = -g
OBJECTS = hashTable.o timer.o wordPuzzle.o

.SUFFIXES: .o .cpp

lab6: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~ 
