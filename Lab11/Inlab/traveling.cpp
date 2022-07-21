/*Name: Steven Song
  UVA ID: sqs5hrn 
  Date: May 3, 2021 
  CS2150 Lab 11 In Lab traveling.cpp 
*/

#include <stdio.h> // Header that defines three variable types, several macros, and various functions for performing input and output 
#include <stdlib.h> // Header for the standard library language for the C++ language, which includes functions like memory allocations and conversions among others (allows us to deallocate memory) 
#include <iostream> // You need to include <iostream> in order to print stuff out (i.e. cin/cout)
#include <cstdlib> // Header used for conversions (i.e. converting a string to an int (atoi) or a string to a float) 
#include <algorithm> // As the PDR states, there are a number of STL functions that will help you in writing this program (particularly the sort method for the vector which we use in our main method) 

using namespace std; // Like always, we need namespace std in order to define the scope of the class (the context of the file in which all of the names are declared) 

#include "middleearth.h" // We have to include "middleearth.h" since we're going to be accessing a lot of its methods, functions, and members in order for our traveling.cpp program to work (I called methods such as getDistance, getItinerary, as well as the middleearth constructor in my traveling.cpp program)  

// NOTE: You don't need to include consts in any of the parameters in computeDistance and printRoute like they do in the source code/traveling-skeleton.cpp in order for this file to work. I removed all of the consts in the parameters in these two methods and got my code to pass all of the tests on Gradescope. For some reason, when I kept the consts in the parameters in those two methods, it doesn't pass the City 10 test on Gradescope, so I had to remove them from the parameters in those two methods.  

// These two methods were given to us in the traveling-skeleton.cpp in the PDR 
float computeDistance(MiddleEarth &me, string start, vector<string> dests);
void printRoute(string start, vector<string> dests);

// The beginning part of the main method was also given to us in the traveling-skeleton.cpp file  
int main(int argc, char** argv) {
  // check the number of parameters                                             
  if (argc != 6) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
	 << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
  
  // we'll assume the parameters are all well-formed                            
  int width = stoi(argv[1]); // The x-size of the world. We'll use 20 throughout this lab. 
  int height = stoi(argv[2]); // The y-size of the world. We'll use 20 throughout this lab. 
  int num_cities = stoi(argv[3]); // The number of cities in the world. There are currently 40 names specified at the top of middleearth.cpp, so you can't specify more than 40 cities. 
  int rand_seed = stoi(argv[4]); // The random seed. If you specify a given number, the same world will be created each time. 
  int cities_to_visit = stoi(argv[5]); // The number of cities to visit, other than the "home city". This can be as low as 1.
  
  // create the world, and select your itinerary                                     
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);

  // TODO: YOUR CODE HERE 

  // Basically, the gist of traveling.cpp is that it wants us to implement a brute force-traveling salesperson solution, which basically tries every possible path combination in order to reach a solution to the traveling salesperson problem.

  // In brief, you start from a given city (your "home city") and you have to travel to a number of other cities before returning home. There is a fixed cost between any two cities (miles traveled, dollars spent, time taken, etc.) The goal of this algorithm is to find the least costly path that travels to each of the cities, in any order.

  // The world we have chosen is Middle Earth, which is the location of J.R.R. Tolkien's Hobbit and the Lord of the Rings books and movies. The middleearth.h and middleearth.cpp files contains a class that will create a random 2-dimensional world, meaning it can pick a given number of cities and place them randomly in the world. 
  
  sort(dests.begin()+1, dests.end()); // Takes in vector iterators and sorts the entire list of destinations from beginning to end. (the vector has to be sorted in order for the permutations to work) 
  string firstdestination = dests.at(0); // Declares a variable that sets the start/first destination in the destination vector to be the first element in dests (reminder: .at() is a built in function for vectors that returns a reference to the element at position i in the vector: so it essentially does the same thing as array[i] or arraylist.get(i) where it gets the element at index i in that data structure, only this time it's used for vectors) 
  float shortestdistance = computeDistance(me, firstdestination, dests); // Declares a variable that sets the shortest distance from one destination to another as the distance from the first destination to the dests vector at default (this variable will be updated as we loop through all of the permutations of the list of destinations since the shortest distance is what we want to print out at the end of the main method)
  vector<string> listofdestinations = dests; // Declares a new vector called the listofdestinations in which we're basically setting it equal to dests, which is the previous vector that has all of the destinations/list of cities from our middleearth class.
  float tempdistance = 0.0; // Declares a variable that keeps track of the distance from one city to another for each of the destinations in the vector (it compares all of the combinations one by one). This temp variable will be used to loop through all of the destinations in the vector and it will be used to find the shortest distance between two cities, in which it will be set to the shortest distance variable that we just created above. (anytime the temp distance from one city to another is less than the previous one, the temp gets updated each time and we set it to the shortestdistance once we've looped through all of the destinations in the vector)

  do { // The PDR instructions recommend students to use a do-while loop to find the permutations of the vectors as it is a good way to iterate through each possible combination of cities to travel to.
    tempdistance = computeDistance(me, firstdestination, dests); // Finds the distance between two destinations from the vector
    if(tempdistance < shortestdistance) { // If the temp distance from one city to another is shorter than that of the previous one, then we have to set that equal to the shortestdistance, as we want to keep updating the shortestdistance anytime the difference in distance between 2 destinations is shorter than the previous one
      shortestdistance = tempdistance; // Sets the shortestdistance equal to the updated temp distance 
      listofdestinations = dests; // We then want to set the dests vector to be equal to our new listofdestinations vector that we just created above
    }
  } while(next_permutation(dests.begin()+1, dests.end())); // Goes through all of the permutations in the dests vector from the first destination to the last destination
  
  firstdestination = listofdestinations.at(0); // Once we've finished looping through all of the destinations in the vector, we want to set the first destination to be equal to the first element in our own listofdestinations vector
  // In the exact same print output as the one in the PDR
  cout << "Minimum path has distance " << shortestdistance << ": "; // Prints out the shortest distance in our vector in the exact format as intended from the PDR 
  printRoute(firstdestination, listofdestinations); // Prints out the itinerary of all the destinations 
  // You want to make sure that you print out all the permutations of the list of destinations. Note for that n cities, there are n! permutations and the start city should not be permuted.
  
  return 0; // As always, we have to return 0 at the end of our main method for insurance (in case none of the above code works) 
}

// This method will compute the full distance of the cycle that starts                 
// at the 'start' parameter, goes to each of the cities in the dests                   
// vector IN ORDER, and ends back at the 'start' parameter.                            
float computeDistance(MiddleEarth &me, string start, vector<string> dests) { // Finds/computes the total distance from the start city to all of the other cities and back
  // TODO: YOUR CODE HERE 

  // start is basically just the first destination in the vector 
  string lastcity = dests.back(); // Declares a variable called lastcity which is basically just the last destination in the vector, since it wants you to end back at the start parameter
  // .back() is a built in method for vectors that returns a reference to the last element in the vector (so essentially whatever is stored in the last index in the dests vector) 
  float totaldistancebetweencities = 0.0; // Declares a variable called totaldistancebetweencities that sets the distance between the two destinations equal to 0.0 at first, since you haven't traveled anywhere yet, so that we can update it as we loop through all of the destinations in the vector, and from there we compute the destination between each pair of destinations, and then lastly, we return the total distance at the end of this method
  int i = 0;
  while (i < dests.size()) { // Loops through all of the destinations in the vector
    totaldistancebetweencities += me.getDistance(start, dests.at(i)); // Adds the distance between the present destination we're on and the next destination after that to our totaldistance variable 
    start = dests.at(i); // As the instructions state, we want to end back at "start" so we have to set the start/beginning (start) to the new location
    i++; 
  }
  totaldistancebetweencities += me.getDistance(dests.at(0), lastcity); // Finds the distance from the first city to each of the cities in the dest vector (hence why we include last city as the last parameter when calling the getDistance method) and then it computes the full distance of the cycle (basically whenever you travel to a new location, you add the distance between the new location and the previous location to the total distance)
  
  // And then you set the beginning/start destination, which is essentially the location you're at right now, to the new destination (so for example, you would the set the second destination to be the first location after you found the distance between the first destination and the second destination, rinse and repeat for the third, fourth, etc. destination in the vector until you've gone through all of the destinations in the vector) 
  return totaldistancebetweencities; // returns the total distance of the whole cycle 
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:                               
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor            
void printRoute(string start, vector<string> dests) { // This method just prints out all of the cities beginning at start in the exact format as what they have in the PDR
  // TODO: YOUR CODE HERE
  int i = 0; 
  while (i < dests.size()) {
    cout << dests.at(i) << " -> "; // The reason why we have to print out an " -> " for each destination in the vector is so that we can find/simulate the direction of the itinerary for each destination from middleearth.cpp
    i++;
  }
  cout << start << endl; // You need to print 'start' in order to start at the first destination in the vector in order for the whole print procedure and print format to work 
}
