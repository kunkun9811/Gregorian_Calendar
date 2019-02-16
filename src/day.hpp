#ifndef DAY_HPP
#define DAY_HPP

#include <iostream>

#include "todo.hpp"

using namespace std;

// class taskPtrCmpr{
//     public: 
//         bool operator()(Todo *&lhs, Todo *&rhs){
//             return *lhs < *rhs;
//         }
// };

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
        //Todo *todoRoot;
        
        void deleteAll(Todo *todoNode);
    public:
        /* Constructor */
        Day(int yearNum, int monthNum, int dayNum);
        ~Day(){
            deleteAll(todoRoot);
        }
        
        /* Getter for numOfThings */
        int getNumOfThings() {
            return numOfThings;
        }
        bool insertTodo(const string &todoString, const int imp);
        
        // Just to test tree, PRINT TREE
        void inorder(Todo *todoNode) const;
        
        // priority_queue<Todo*, vector<Todo*>, taskPtrCmpr> todos;
        Todo *todoRoot;
        
        
     
};


#endif
