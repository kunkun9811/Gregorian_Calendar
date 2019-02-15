#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>
#include <queue>

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
        int yearNumber;
        int monthNumber;
	    int dayNumber;
        int numOfThings;
        priority_queue<*todo> todos;
    public:
        /* Constructor */
        Day(int yearNum, int monthNum, int dayNum) : numOfThings(0){}
        
        /* Getter for numOfThings */
        int getNumOfThings() {
            return numOfThings;
        }
        
        
     
};


#endif
