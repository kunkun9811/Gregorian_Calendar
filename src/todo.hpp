#ifndef TODO_HPP
#define TODO_HPP

#include <iostream>
#include <string>
#include <stack>

using namespace std;

/* Variables:
 *      (1) task = string of the work you need
 *      (2) importance = levesl of importance
 *              1 = IMPORTANT AF
 *              2 = IMPORTANT
 *              3 = MODERATELY IMPORTANT
 *              4 = NOT THAT IMPORTANT
 *              5 = LEISURELY IMPORTANT
 */
 
    // void printTask(priority_queue<Todo*, vector<Todo*>, taskPtrCmpr> tempQueue){
    //     while(!tempQueue.empty()){
    //         cout << *(tempQueue.top()) << endl;
    //         tempQueue.pop();
    //     }
    // }


class Todo{
    private:
        string task;
        int importance;
        int height;
		
		/* Helper function for getSuccessor() */
		Todo* successorAtAbove(Todo* currTodoNode);
		Todo* successorAtRight(Todo *currTodoNode);
		
    public: 
        Todo *leftTodo;
        Todo *rightTodo;
        Todo *parent;
    
        Todo() : task(""), importance(0) {}     // Constructor
        Todo(const string todoString, const int &imp){
            leftTodo = rightTodo = parent = NULL;
            height = 1;
            importance = imp;
            task = todoString;
        }
        
        
        void setTask(string theTask);           // Set the task for current Todo Node
        string getTask() const;                 // Get the task string for current Todo Node
        void setImportance(int theImportance);  // Set the importance of this current Todo Node
        int getImportance() const;              // Set the importance of this current Todo Node 
        int getHeight() const;                  // Get the Height of the current Node(self included)
        void adjustHeight(stack<string> &path); // Set Height of the current Node *Do any Necessary rotations*
        
        /* Rotations to balanace the Todo tree */
		void rotateLeft(Todo *theNode, stack<string> &path);
		void rotateRight(Todo *theNode, stack<string> &path);
		void rotateLeftKink(Todo *theNode, stack<string> &path);
		void rotateRightKink(Todo *theNode, stack<string> &path);
                
        Todo* getSuccessor();                   // Get the successor of current Node (Used when a todo is deleted)
        //bool operator<(const Todo& other);    // Overriding less than operator for the purpose of min-heap data structure
        


};

/* Overriding Outputting operator for Printing Information of the Todo Node*/
// ostream& operator<<(ostream&, const Todo&) __attribute__((weak));
// ostream& operator<<(ostream &out, const Todo &a){
//     // out << a.getTask() << "\n";
//     // out << a.getImportance() << "\n";
//     // printf("TODO: %s \n \n", a.getTask());
//     // return out;
// }



#endif