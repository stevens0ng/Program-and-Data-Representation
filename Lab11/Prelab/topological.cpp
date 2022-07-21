/*Name: Steven Song
  UVA ID: sqs5hrn 
  Date: May 2, 2021 
  CS2150 Lab 11 Pre Lab topological.cpp
*/

// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

// Everything that we have to include in our topological.cpp program

#include <stdlib.h> // Header for the standard library for the C++ language, which includes functions like memory allocations and conversions among others (allows us to deallocate memory)
#include <cstdlib> // Header used for dynamic memory management, integer arithmetics, searching, sorting, and converting
#include <queue> // Necessary for pop() and push()
#include <vector> // Used to store the adjacency list  
#include <fstream> // You need to include fstream in order to open up a file in order to read and write from/to files 
#include <iostream> // You need to include iostream in order to print stuff out (i.e. cin/cout) 
#include <unordered_map> // Necessary for the hashtable to store indegree map and the adjacency list graph

using namespace std; // Like always, we need namespace std in order to define the scope of the class (the context of the file in which all of the names are declared) 

// The idea behind topological sort is that you want to take in a graph that has directed edges and you want to spit out an order of these letters such that if you think of these arrows as prerequisites, you always handled prerequisites before you handled anything after that. So basically, you have to think of these as classes in your college degree that you have to take/complete and an arrow means that you have to complete this class before you complete that class.

// And the way it works is that topological sort will print out a valid order to take the courses such that you don't break any of the prerequisites. (And there might be multiple valid orderings that work because a graph could have multiple possible orderings and the topological sort algorithm is only guaranteed to return one of the valid orderings, doesn't matter which one.  

// Use the provided fileio2.cpp from the PDR by Bloomfield
// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.
  
// we want to use parameters

// topological sort algorithm from the Graphs Slideset Slides 5.8, and also from the Live Lecture 35 that goes over the algorithm for Topological sort 
void topsort(unordered_map<string, int> indegree_map, unordered_map<string, vector<string>> g) {
  queue<string> q;
  unordered_map<string, int>::iterator indItr = indegree_map.begin(); // iterator for the indegree hashtable
  while (indItr != indegree_map.end()) { // As long as the indegree map is not empty
    if (indItr->second == 0) {
      q.push(indItr->first); // First, push all the indegree=0 into the queue
      // cout << indItr->first << " " << indItr->second << endl; // Code that is used for debugging the indegree map
    }
    indItr++;
  }

  while (q.size() > 0) { // As long as the queue is not empty, pop the nodes from the queue and then visit the neighbors. Then decrement the n degree by 1
    string currentNode = q.front();
    q.pop();
    cout << currentNode; // Prints out the node that has indegree=0, which is one path of the topological sort. This sort does not guarantee alphabetical ordering of the topological sort.
    // for each adjacent node of the current node
    unordered_map<string, vector<string>>::iterator gItr = g.find(currentNode); // iterator for the adjacency graph hashtable
    if (gItr != g.end()) {
      vector<string> adjList = gItr->second;
      for (int i=0; i < adjList.size(); i++) { // Loop through the neighbors and find their indegrees and decrement by 1
	indItr = indegree_map.find(adjList[i]);
	if (indItr != indegree_map.end()) {
	  if (--indItr->second == 0) { // If the indegree is 0, push back to the queue
	    q.push(adjList[i]);
	  }
	}
      }
    }
    if (q.size() > 0) { // No space is added at the very end of the print out of the topological sort
      cout << " ";
    }
  }
  cout << endl; // Prints out a new line after the topological sort
  
  /* Code used for printing out the adjacency list
     unordered_map<string, vector<string> >::iterator gItr = g.begin();
     while(gItr != g.end()) {
       cout << gItr-> first;
       vector<string> adjList = gItr->second;
       for (int i=0; i < adjList.size(); i++) {
         cout << " " << adjList[i];
       }
       cout << endl;
       gItr++;
     }
  */
}

// we want to use parameters
int main(int argc, char** argv) { // These parameters are the exact same as they were in Lab 10 when reading in the file
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  ifstream file(argv[1], ifstream::binary); // This will open the file that we want to read in for this Pre Lab
  // report any problems opening the file and then exit
  if (!file.is_open()) { // If the file is unable to be read/opened up, then exit the file
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
    
  unordered_map<string, int> indegree_map; // the indegree for each node using hashtable
  unordered_map<string, vector<string>> g; // adjacency list representation of the graph using hashtable

  while (true) {
    // read in two strings
    string s1, s2;
    file >> s1;
    file >> s2;

    // output those strings
    // cout << s1 << endl;
    // cout << s2 << endl;
    if (s1 == "0" && s2 == "0") {
      break;
    }
    
    unordered_map<string, int>::iterator mapItr = indegree_map.find(s1); // find is used to find the pair for the indegree
    unordered_map<string, vector<string>>::iterator gItr = g.find(s1); // gItr is the iterator for the adjacency list
    vector<string> adjList;
	
    if (mapItr == indegree_map.end()) { // didn't find it
      indegree_map.insert(make_pair(s1, 0)); // insert s1 into the hash table for the indegree
    }

    if (gItr == g.end()) {
      adjList.push_back(s2);
      g.insert(make_pair(s1, adjList)); // didn't find it in the adjacency hashtable, add a new pair 
    }

    else {
      gItr->second.push_back(s2); // find it, append s2 to the adjacent list
    }

    mapItr = indegree_map.find(s2); // increase the indegree of s2 node by 1

    if (mapItr == indegree_map.end()) {
      indegree_map.insert(make_pair(s2, 1));
    }

    else {
      mapItr->second++; // increment the indegree for s2
    }
  }
  // Close the file before exiting
  file.close();
  topsort(indegree_map, g);
  return 0; // As always, we must return 0 at the end of each main method for insurance
}
