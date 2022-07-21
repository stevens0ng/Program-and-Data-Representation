/*Name: Steven Song
  UVA ID: sqs5hrn
  Date: May 3, 2021
  CS2150 Lab 11 In Lab middleearth.h
*/

// NOTE: Everything in middleearth.h was copied over from the Pre Lab (didn't modify this file for the In Lab) 

// Everything here was downloaded from the source code in the PDR/instructions for Lab 11. The only thing I did here was make comments for each of the methods listed under private: and public:

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:
    MiddleEarth(int xsize, int ysize, int num_cities, int seed); // This is the constructor of MiddleEarth that builds the world with the first parameter being the size of the world from x, the second parameter being the size of the world from y, the third parameter being the number of cities in the world, and the fourth parameter being the random seed of type int  
    void print(); // This method will print out the entire world  
    void printTable(); // This method will print out the separated distances
    float getDistance(const string& city1, const string& city2); // This method will return the distance where the first parameter is city1 (name of first city) and the second parameter is city2(name of the second city) 
    vector<string> getItinerary(unsigned int length); // This method will return the vector of the strings of the roadmaps with parameters city1 and city2  

    // There's no deconstructor in middlearth.h since it doesn't return anything
  
private:
    int num_city_names, xsize, ysize; // These are the private variables in the middleearth class in order to declare the number of cities and the size of the world for both x and y 
    unordered_map<string, float> xpos, ypos; // This is the map within a map position 
    vector<string> cities; // This is the vector that stores all of the cities 
    unordered_map<string, unordered_map<string, float>> distances; // This is the variable for the pointer to all of the cities of type unordered_map  

    mt19937 gen; // Mersenne-Twister random number engine
};

#endif

