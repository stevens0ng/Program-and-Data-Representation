# Name: Steven Song
# UVA ID: sqs5hrn 
# Date: March 22, 2021   
# CS2150 Lab 5 In Lab Makefile 

CXX = clang++
CXXFLAGS = -Wall -g
DEBUG= -g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp

.PHONY: clean

clean:
	rm -f *.o *~a.out

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp 
