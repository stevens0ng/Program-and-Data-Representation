// NOTE: in order to compile this system on Linux (and most Unix
// systems) you will have to include the -lrt flag to your compiler.
//
// This timer typically has 1/1000000 second (1 micro-second) accuracy
// under most Linux distributions

/*Name: Steven Song 
  UVA ID: sqs5hrn 
  Date: April 21, 2021  
  CS2150 Lab 9 Post Lab timer.h  
*/

// NOTE: The timer.h file was downloaded from the PDR/source code for the Lab 9 Post Lab (didn't modify this file)

#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>

using namespace std;

class timer {
private:
    timeval startVar, stopVar;
    bool running;

public:
    timer() : running(0) {}
    ~timer() {}
    timer(timer & myTimer);
    int start();
    int stop();
    string toString();
    ostream & print(ostream &theStream);
    double getTime();
};

ostream & operator<<(ostream & theStream, timer & theTimer);

#endif
