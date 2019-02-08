#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>

#include "todo.hpp"

using namespace std;


class Day {
    
    /* Data Structure:
     *      priority_queue(max heap): for level of importance
     * Variables:
     *      (1) numOfThings = # of things to do
     * FUNCTIONS:
     *      (1) Function to write to a file
     *      (2) Function to delete certain thing from a file
     *      (3) Function to find string in a file
     *      (4) Need to format files so easier to extract info
     *          back from file
     */
    private: 
        int numOfThings;
        Todo* task;
    public:
        /* Constructor */
        Day() : numOfThings(0), task(NULL){}
        
        /* Getter for numOfThings */
        int getNumOfThings() {
            return numOfThings;
        }
        
        
     
};


#endif