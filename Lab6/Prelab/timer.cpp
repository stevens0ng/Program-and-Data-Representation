/* Name: Steven Song 
   UVA ID: sqs5hrn 
   Date: March 28, 2021 
   CS2150 Lab 6 Pre Lab timer.cpp  
*/

// NOTE: The timer.cpp file was downloaded from the PDR/source code for the Lab 6 Pre Lab (didn't modify this file)

#include "timer.h"

timer::timer() {
    running = false;
}

timer::timer(timer& t) {
    running = t.running;
    start_time = t.start_time;
    stop_time = t.stop_time;
}

void timer::start() {
    if (!running) {
        running = true;
        start_time = steady_clock::now();
    }
}

void timer::stop() {
    if (running) {
        running = false;
        stop_time = steady_clock::now();
    }
}

// Returns the time elapsed, in seconds
double timer::getTime() {
    // Cast the intrinsic duration to seconds, but use a double so that we can
    // have fractional seconds to represent anything more precise (i.e. microseconds)
    return duration_cast<duration<double>>(stop_time - start_time).count();
}

ostream& operator<<(ostream& out, timer& t) {
    return out << to_string(t.getTime());
}
