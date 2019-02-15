#include <iostream>
#include <stack>

#include "calendar.hpp"

using namespace std;

bool Calendar::insertYear(int yearNum){
    stack<string> path;
    if(yearRoot == NULL){
        Year *tempYearNode = new Year(yearNum);
        yearRoot = tempYearNode;
        yearRoot->adjustHeight(path);
        return true;
    }
    
    Year *currYear = yearRoot;
    while(currYear){
        if(yearNum < currYear->getYearNumber()){
            if(currYear->leftYear == NULL){
                currYear->leftYear = new Year(yearNum);
                currYear->leftYear->parent = currYear;
                currYear = currYear->leftYear;
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                currYear->adjustHeight(path);
                while(currYear->parent != NULL){
                    
                    // Keep track of the path traversed from bottom to top
                    if(currYear->parent->leftYear == currYear){
                        path.push("L");
                    }
                    else if(currYear->parent->rightYear == currYear){
                        path.push("R");
                    }
                    currYear = currYear->parent;
                    currYear->adjustHeight(path);
                }
                
                
                return true;
            }
            currYear = currYear->leftYear;
        }
        else if(yearNum > currYear->getYearNumber()){
            if(currYear->rightYear == NULL){
                currYear->rightYear = new Year(yearNum);
                currYear->rightYear->parent = currYear;
                currYear = currYear->rightYear;
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                currYear->adjustHeight(path);
                while(currYear->parent != NULL){
                    
                    // Keep track of the path traversed from bottom to top
                    if(currYear->parent->leftYear == currYear){
                        path.push("L");
                    }
                    else if(currYear->parent->rightYear == currYear){
                        path.push("R");
                    }
                    currYear = currYear->pasrent;
                    currYear->adjustHeight(path);
                }
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
