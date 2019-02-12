#include <iostream>

#include "calendar.hpp"

using namespace std;

bool Calendar::insertYear(int yearNum){
    if(yearRoot == NULL){
        Year *tempYearNode = new Year(yearNum);
        yearRoot = tempYearNode;
        return true;
    }
    
    Year *currYear = yearRoot;
    while(currYear){
        if(yearNum < currYear->yearNumber){
            if(currYear->leftYear == NULL){
                currYear->leftYear = new Year(yearNum);
                currYear->leftYear->parent = currYear;
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                return true;
            }
            currYear = currYear->leftYear;
        }
        else if(yearNum > currYear->yearNumber){
            if(currYear->rightYear == NULL){
                currYear->rightYear = new Year(yearNum);
                currYear->rightYear->parent = currYear;
                return true;
            }
            currYear = currYear->rightYear;
        }
        else {
            cout << "Year already exist" << endl;
            return false;
        }
    }
    return false;
}