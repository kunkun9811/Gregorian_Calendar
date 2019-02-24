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
     // priority_queue<Todo*, vector<Todo*>, taskPtrCmpr> todos;
     //         // this is a test must delete
     // void inorderTest(const Todo * const &todoNode) const;
    private: 
        int yearNumber;
        int monthNumber;
	    int dayNumber;
        int numOfThings;
        Todo *todoRoot;
        
        void deleteAll(Todo *todoNode);
        bool removeNode(const Todo* theNode);
        void addToFile(Todo *theTodo) const;                        // Helper function for set Event
    public:
        /* Constructor */
        Day(int yearNum, int monthNum, int dayNum);
        ~Day(){
            deleteAll(todoRoot);
        }

        int getNumOfThings() const{                                 // Get number of things in current day
            return numOfThings;
        }
        Todo* getTodoRoot() const{
            return todoRoot;
        }
        bool setEvent(const string &todoString, const int imp);         // Set event 
        bool deleteEvent(const string &todoString);                     // Delete event
        bool insertTodo(const string &todoString, const int imp);       // Insert a newly created Todo Node to tree
        void printByImportance() const;                                 // Print By level of importance
        void inorder(const Todo * const &todoNode, int &i) const;       // Print the tree in Inorder
        void readDayFile();                                             // Add to file (or write to file)
     
};


#endif

// I need CreateFile function and ReadFile Function