# Name: Steven Song 
# UVA ID: sqs5hrn 
# Date: March 21, 2021 
# CS2150 Lab 5 Pre Lab Makefile  

CXX = clang++ $(CXXFLAGS) 
CXXFLAGS = -Wall -o2 # Enable all warnings
DEBUG = -g
OBJECTS = TreeNode.o TreeCalc.o TreeCalcTest.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

TreeNode.o: TreeNode.cpp TreeNode.h

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeCalcTest.o: TreeCalcTest.cpp 

.PHONY: clean

clean:
	-rm -f *.o *~a.out

TreeNode.o: TreeNode.cpp TreeNode.h

TreeCalc.o: TreeCalc.cpp TreeCalc.h

TreeCalcTest.o: TreeCalcTest.cpp
