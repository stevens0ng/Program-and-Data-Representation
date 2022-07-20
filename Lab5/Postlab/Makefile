# Name: Steven Song                                                                                
# UVA ID: sqs5hrn                                                                        
# Date: March 24, 2021                                                                             
# CS2150 Lab 5 Post Lab Makefile                                                                                 

CXX = clang++
CXXFLAGS = -Wall -g
DEBUG= -g
OBJECTS = AVLNode.o AVLTree.o AVLPathTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h

AVLPathTest.o: AVLPathTest.cpp

.PHONY: clean
	-rm -f *.o *~a.out

AVLNode.o: AVLNode.cpp AVLNode.h

AVLTree.o: AVLTree.cpp AVLTree.h

AVLPathTest.o: AVLPathTest.cpp
