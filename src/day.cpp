#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

#include "day.hpp"

using namespace std;

Day::Day(int yearNum, int monthNum, int dayNum){
    yearNumber = yearNum;
    monthNumber = monthNum;
    dayNumber = dayNum;
    numOfThings = 0;
    todoRoot = NULL;
    readDayFile();
}

// this is a test must delete
// void Day::inorderTest(const Todo * const &todoNode) const{
//     if(todoNode == NULL){
//         return;
//     }
//     inorderTest(todoNode->leftTodo);
//     string tempString = todoNode->getTask();
//     char *stringPtr = &(tempString.at(0));
//     printf("[%d,%s @ %p]", todoNode->getImportance(), stringPtr, todoNode);
//     cout << endl;
//     printf("Parent: %p", todoNode->parent);
//     cout << endl;
//     printf("Left Todo: %p", todoNode->leftTodo);
//     cout << endl;
//     printf("Right Todo: %p", todoNode->rightTodo);
//     cout << endl << endl;
//     inorderTest(todoNode->rightTodo);
//     return;
// }

void Day::deleteAll(Todo *todoNode){
    if(todoNode == NULL){
        return;
    }
    todoNode->leftTodo;
    todoNode->rightTodo;
    delete todoNode;
    return;
}

void Day::inorder(const Todo * const &todoNode, int &i) const{
    if(todoNode == NULL){
        return;
    }
    inorder(todoNode->leftTodo, i);
    // cout << *todoNode << endl;
    printf("(%d) ", i);
    string tempString = todoNode->getTask();
    char *stringPtr = &(tempString.at(0));
    printf("TODO: %s \n \n", stringPtr);
    i++;
    inorder(todoNode->rightTodo, i);
    return;
}

/* PURPOSE: Read the file of this spcific day
 *          (1) If file doesn't exist - return
 *              **Meaning this specific day has nothing planned
 *          (2) If file exist, for each TODO create a corresponding
 *              TODO node and insert into the tree
 */
void Day::readDayFile(){
    string fileName = "../server/" + to_string(yearNumber) + "-" + to_string(monthNumber) + "-" + to_string(dayNumber) + ".txt";
    string imp;             // Temp for importance value before creating a TODO node
    string todo;            // Temp for TODO value vefore creating a TODO node
    // string separator;       // The separating '^' character after each TODO in formatted text file
    ifstream dayFile(fileName);
    if(!dayFile.is_open()){             // If file doesn't exist, do nothing
        return; 
    }
    else{
        // Reset Tree first
        deleteAll(todoRoot);
        // testing how many times it while looped
        int i = 1;
        while(!getline(dayFile, imp).eof()){
            getline(dayFile, todo);
            // getline(dayFile, separator);
            insertTodo(todo, stoi(imp));
            
            // //Printing Tree to see tree structure after each insert;
            // cout << "(*****" << i++ << "*****)" << endl;
            // inorderTest(todoRoot);
            // cout << endl;
        }
    }
    dayFile.close();
    return;
}

/* Helper function for setEvent function
 *
 *
 *
 */
void Day::addToFile(Todo *theTodo) const{
    string fileName = "../server/" + to_string(yearNumber) + "-" + to_string(monthNumber) + "-" + to_string(dayNumber) + ".txt";
    string imp = to_string(theTodo->getImportance());
    string todo = theTodo->getTask();
    ostringstream oss;
    ofstream dayFile;
    dayFile.open(fileName, ios::app);
    if(!dayFile.is_open()){
        cout << "TRYING TO ADD TO FILE - FILE WAS NOT FOUND" << endl;
        return;
    }
    else{
        oss << imp << endl;
        oss << todo << endl;
        // oss << "^" << endl;
    }
    dayFile << oss.str();
    dayFile.close();
    return;
}

bool Day::setEvent(const string &todoString, const int imp){
    if(todoString != "" && (imp >= 1 && imp <=5)){
        Todo tempTodo(todoString, imp);
        insertTodo(todoString, imp);
        addToFile(&tempTodo);
        return true;
    }
    else{
        cout << "Please enter an event or make sure Importance level is between 1 and 5" << endl;
        return false;
    }
    
}

// Edge case: If the successor is the immediate rightTodo Node of the nodeToDelete
//            If it is, don't set the rightTodo of Successor to the rightTodo 
//            of the nodeToDelete


/* Helper function for deleteEvent
 * Purpose: Delete the todo node in the AVL data structure of Todo class
 * 
 * Algorithm: (1) Check if the task is the same, if yes check the three cases
 *                  (a) nodeToDelete has two children
 *                  (b) nodeToDelete has one children
 *                  (c) nodeToDelete has no child
 * 
 *            (2) If the task is not the same, traverse tree **WITH THENODE'S IMPORTANCE**, not the node's task
 *                  (a) If theNode's importance is less than nodeToDelete's (or currNode's), traverse left subtree
 *                  (b) If theNode's importance is greater or equal to nodeToDelete's (or currNode's) importance, traverse right subtree
 */
bool Day::removeNode(const Todo* theNode){
    Todo* nodeToDelete = todoRoot;
    while(nodeToDelete != NULL){
        if(theNode->getTask() == nodeToDelete->getTask()){
            /* Node to delete has two children */
            if(nodeToDelete->leftTodo != NULL && nodeToDelete->rightTodo != NULL){
                Todo* theSuccessor = nodeToDelete->getSuccessor();
                Todo* theSucOldParent = theSuccessor->parent;              // Later we traverse from 
                
                /* I don't think I need to check if theSuccessor is the left or right child of its parent,
                 * Because we are finding the left-most node in the right subtree(aka the meaning of successor)
                 * If It is the immediate right node of the nodeToDelete, then still we don't have to check
                 * if it is left node or right node of the parent. Because, in this case and any other,
                 * if the successor has a right child (definitely not going to have a left child, or else we would've traversed left), 
                 * then connect that right child to the successor's old parent (which in this case would be the 'modified' nodeToDelete)
                 * Just like how you would do to the left most node of right subtree (aka any other successors)
                 */
                 
                 /* HERE , i think i deleted theSuccessor not the node to be deleted LOL */
                if(theSuccessor->rightTodo != NULL){
                    // Set right node of theSuccessor to theSucOldParent (no matter what)
                    theSuccessor->rightTodo->parent = theSucOldParent;                      
                    
                    // If successor is the imeediate right node of nodeToDelete
                    if(theSuccessor == nodeToDelete->rightTodo) {
                        theSucOldParent->rightTodo = theSuccessor->rightTodo;
                    }
                    // If not
                    else {
                        theSucOldParent->leftTodo = theSuccessor->rightTodo;
                    }
                } 
                else{   // theSuccessor->rightTodo == NULL
                    // If successor is the imeediate right node of nodeToDelete
                    if(theSuccessor == nodeToDelete->rightTodo) {
                        theSucOldParent->rightTodo = theSuccessor->rightTodo;
                    }
                    // If not
                    else {
                        theSucOldParent->leftTodo = NULL;
                    }
                }
                nodeToDelete->setTask(theSuccessor->getTask());
                nodeToDelete->setImportance(theSuccessor->getImportance());
                delete theSuccessor;
               
                Todo* nodeToAdjust = theSucOldParent;
                Todo* prevTodo = NULL;
                // stack<string> path;         // There's no need for path stack here. It is for function calling
                // int LHeight = 0;
                // int RHeight = 0;
                
                // while(nodeToAdjust != NULL){
                //     /* Adjust Height for Remove */
                    
                //     // Check if Tree is unbalanced
                //     if(nodeToAdjust->leftTodo == NULL) LHeight = 0;
                //     else LHeight = nodeToAdjust->leftTodo->getHeight();
                    
                //     if(nodeToAdjust->rightTodo == NULL) RHeight = 0;
                //     else RHeight = nodeToAdjust->rightTodo->getHeight();
                    
                //     if(abs(LHeight - RHeight) > 1){
                //         // cout << "********I'm here in checking**********" << endl;
                //         if(RHeight > LHeight){          // Have not reached root yet
                //             if(nodeToAdjust->rightTodo != NULL){                    // RR
                //             // cout << "I'm here in RR RL" << endl;
                //                 if(nodeToAdjust->rightTodo->rightTodo != NULL){
                //                     nodeToAdjust->rotateLeft(nodeToAdjust);
                //                 }
                //                 else if(nodeToAdjust->rightTodo->leftTodo != NULL){ // RL
                //                     nodeToAdjust->rotateLeftKink(nodeToAdjust);
                //                 }
                //             }
                //         }
                //         else{   // LHeight > RHeihgt
                //             if(nodeToAdjust->leftTodo != NULL){ 
                //                 // cout << "I'm in LL LR" << endl;
                //                 if(nodeToAdjust->leftTodo->leftTodo != NULL){           // LL 
                //                     // cout << "I'm here ahha" << endl;
                //                     nodeToAdjust->rotateRight(nodeToAdjust);
                //                 }
                //                 else if(nodeToAdjust->leftTodo->rightTodo != NULL){     // LR
                //                     // cout << "I'm hella here" << endl;
                //                     nodeToAdjust->rotateRightKink(nodeToAdjust);
                //                 }
                //             }
                //         }
                //     }
                //     /* After everything is adjusted, Fix the height of the current Node to above */
                //     // Again, the stack 'path' has nothing to do with function, it's just for the sake of function calling
                //     nodeToAdjust->adjustHeight();
                //     nodeToAdjust = nodeToAdjust->parent;
                // }
                while(nodeToAdjust){
                    nodeToAdjust->adjustHeight();
                    prevTodo = nodeToAdjust;
                    nodeToAdjust = nodeToAdjust->parent;
                }
                // if(prevTodo == NULL) cout << "prevTodo is NULL" << endl;
                todoRoot = prevTodo;
                numOfThings--;
                return true;
            }
            
            /* Node to delete has one child */
            // Algorithm: only have to pull the only child up and point to nodeToDelete's old parent and 
            //            the old parent point to nodeToDelete's only child
            else if(nodeToDelete->leftTodo != NULL || nodeToDelete->rightTodo != NULL){
                if(nodeToDelete->leftTodo != NULL){
                    Todo* nodeToDeleteOldParent = nodeToDelete->parent;
                    Todo* nodeToDeleteLeftTodo = nodeToDelete->leftTodo;
                    if(nodeToDeleteOldParent == NULL){   // nodeToDelete is root node
                        todoRoot = nodeToDeleteLeftTodo;
                        nodeToDeleteLeftTodo->parent = NULL;
                        delete nodeToDelete;
                        numOfThings--;
                    }
                    else if(nodeToDelete == nodeToDeleteOldParent->leftTodo){
                        nodeToDeleteOldParent->leftTodo = nodeToDeleteLeftTodo;
                        nodeToDeleteLeftTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        numOfThings--;
                        // return true; I didn't change height
                    }
                    else{
                        nodeToDeleteOldParent->rightTodo = nodeToDeleteLeftTodo;
                        nodeToDeleteLeftTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        numOfThings--;
                        // return true;
                    }
                    
                    Todo* currTodo = nodeToDeleteLeftTodo;
                    Todo* prevTodo = NULL;
                    while(currTodo){
                        currTodo->adjustHeight();
                        prevTodo = currTodo;
                        currTodo = currTodo->parent;
                    }
                    // if(prevTodo == NULL) cout << "prevTodo is NULL" << endl;
                    todoRoot = prevTodo;
                }
                else if(nodeToDelete->rightTodo != NULL){
                    Todo* nodeToDeleteOldParent = nodeToDelete->parent;
                    Todo* nodeToDeleteRightTodo = nodeToDelete->rightTodo;      // I did .... Todo* nodeToDeleteRightTodo = nodeToDeleteRightTodo;
                    if(nodeToDeleteOldParent == NULL){      // if nodeToDelete is root node
                        todoRoot = nodeToDeleteRightTodo;
                        nodeToDeleteRightTodo->parent = NULL;
                        delete nodeToDelete;
                        numOfThings--;
                    }
                    else if(nodeToDelete == nodeToDeleteOldParent->leftTodo){
                        nodeToDeleteOldParent->leftTodo = nodeToDeleteRightTodo;
                        nodeToDeleteRightTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        numOfThings--;
                        // return true;
                    }
                    else{
                        nodeToDeleteOldParent->rightTodo = nodeToDeleteRightTodo;
                        nodeToDeleteRightTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        numOfThings--;
                        // return true;
                    }
                    
                    Todo* currTodo = nodeToDeleteRightTodo;
                    Todo* prevTodo = NULL;
                    while(currTodo){
                        currTodo->adjustHeight();
                        prevTodo = currTodo;
                        currTodo = currTodo->parent;
                    }
                    // if(prevTodo == NULL) cout << "prevTodo is NULL" << endl;
                    todoRoot = prevTodo;
                }
                return true;
            }
            
            /* Node To delete has no children */
            else if(nodeToDelete->leftTodo == NULL && nodeToDelete->rightTodo == NULL){
                Todo* toDeleteParent = nodeToDelete->parent;
                if(toDeleteParent == NULL){     // If nodeToDelete is root node
                    todoRoot = NULL;
                    delete nodeToDelete;
                    numOfThings--;
                }
                else if(nodeToDelete == nodeToDelete->parent->leftTodo) {
                    toDeleteParent->leftTodo = NULL;
                    delete nodeToDelete;
                    numOfThings--;
                    // return true;
                }
                else if(nodeToDelete == nodeToDelete->parent->rightTodo){
                    toDeleteParent->rightTodo = NULL;
                    delete nodeToDelete;
                    numOfThings--;
                    // return true;
                }
                
                Todo* currTodo = toDeleteParent;
                Todo* prevTodo = NULL;
                while(currTodo){
                    currTodo->adjustHeight();
                    prevTodo = currTodo;
                    currTodo = currTodo->parent;
                }
                // if(prevTodo == NULL) cout << "prevTodo is NULL" << endl;
                todoRoot = prevTodo;
                return true;
            }
        }
        //
        else if(theNode->getImportance() < nodeToDelete->getImportance()) nodeToDelete = nodeToDelete->leftTodo;
        else if(theNode->getImportance() >= nodeToDelete->getImportance()) nodeToDelete = nodeToDelete->rightTodo;
    }
    return false;
}

/* deleteE event of the passed in string of todo */
// Purpose: Find and remove the string(or the todo) passed in and the importance value associated to it
bool Day::deleteEvent(const string &todoString){
    string fileName = "../server/" + to_string(yearNumber) + "-" + to_string(monthNumber) + "-" + to_string(dayNumber) + ".txt";
    
    string imp;         // variable to temporary store the importance value in the file
    string todo;        // varaible to temporary store the todo value in the file
    int theImp;      // variable used to create temporary Todo Node to traverse tree later in removeNode
    string theTodo;     // variable used to create temporary Todo Node to traverse tree later in removeNode
    vector<int> impVector;          // vector to store all the importance level
    vector<string> todoVector;      // vector to store all the todos
    
    ifstream fileToRemoveFrom;
    fileToRemoveFrom.open(fileName);
    if(!fileToRemoveFrom.is_open()){
        printf("'%d/%d/%d' has no event!", yearNumber, monthNumber, dayNumber);
        return false;
    }
    else{
        // Populating the vector of all the events in the file
        while(!getline(fileToRemoveFrom, imp).eof()){
            getline(fileToRemoveFrom, todo);
            impVector.push_back(stoi(imp));
            todoVector.push_back(todo);
        }
        fileToRemoveFrom.close();
        // Traverse the array to find and delete
        bool elementRemoved = false;                // Flag that shows if an element is removed, if not, it means the element was not in the file
        for(int i = 0; i < todoVector.size(); i++){
            if( todoString == todoVector.at(i)){
                theImp = impVector.at(i);
                theTodo = todoVector.at(i);
                todoVector.erase(todoVector.begin() + i);                // Only delete one
                impVector.erase(impVector.begin() + i);
                elementRemoved = true;
                break;
            }
        }
        if(elementRemoved){
            string tempString = todoString;                         // printf only takes non-const char pointer
            char *stringFirstCharPtr = &(tempString.at(0));         // char pointer that points to the first element(or character) of the string
            // printf("Event '%s' removed.", stringFirstCharPtr);
            ostringstream oss;
            fstream outToFile;
            outToFile.open(fileName, ios_base::out | ios_base::trunc);           // To clear file
            if(!outToFile.is_open()){
                cout << "Could not write to the file. Error removing the event. Try Again." << endl;
                return false;
            }
            else{
                outToFile.close();              // Cleared file
                outToFile.open(fileName);
                cout << endl;
                for(int i = 0; i < todoVector.size(); i++){
                    int impVal = impVector.at(i);
                    imp = to_string(impVal);
                    todo = todoVector.at(i);
                    oss << imp << endl;
                    oss << todo << endl;
                }
                outToFile << oss.str();
                outToFile.close();
            }
            outToFile.close();                          // close the output file
            
            // Create temporary Todo Node to traverse Tree
            Todo* tempTodo = new Todo(theTodo, theImp);
            // if(tempTodo->parent == NULL) cout << "parent is null" << endl;
            // if(tempTodo->rightTodo == NULL) cout << "rightTodo is null" << endl;
            // if(tempTodo->leftTodo == NULL) cout << "leftTodo is null" << endl;
            // cout << "I'm here" << endl;
            removeNode(tempTodo);
            // cout << "I'm here1" << endl;
            delete tempTodo;            // deallocate tempTodo
            return true;
        }
        else{
            printf("**Attempted to Delete event. Event was not found on '%d/%d/%d'**\n\n", yearNumber, monthNumber, dayNumber);
            return false;
        }
    }   
    return false;
}

bool Day::insertTodo(const string &todoString, const int imp){
    stack<string> path;
    if(todoRoot == NULL){
        Todo *tempTodoRoot = new Todo(todoString, imp);
        todoRoot = tempTodoRoot;
        todoRoot->adjustHeight();
        numOfThings++;
        return true;
    }
    
    Todo* currTodo = todoRoot;
    Todo* prevTodo = NULL;
    int balance = 0;
    while(currTodo){
        if(imp < currTodo->getImportance()){
            if(currTodo->leftTodo == NULL){
                currTodo->leftTodo = new Todo(todoString, imp);
                currTodo->leftTodo->parent = currTodo;
                currTodo = currTodo->leftTodo;
                currTodo->setHeight(1);
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                // currTodo->adjustHeight();
                // while(currTodo->parent != NULL){
                    
                //     // Keep track of the path traversed from bottom to top
                //     if(currTodo->parent->leftTodo == currTodo){
                //         path.push("L");
                //     }
                //     else if(currTodo->parent->rightTodo == currTodo){
                //         path.push("R");
                //     }
                //     currTodo = currTodo->parent;            
                //     currTodo->adjustHeight(path);
                // }
                while(currTodo != NULL){
                    currTodo->adjustHeight();
                    prevTodo = currTodo;
                    currTodo = currTodo->parent;
                }
                todoRoot = prevTodo;                        // currTodo has reached the most top node, set todoRoot to prevTodo
                numOfThings++;
                return true;
            }
            else currTodo = currTodo->leftTodo;
        }
        else if(imp >= currTodo->getImportance()){
            if(currTodo->rightTodo == NULL){
                currTodo->rightTodo = new Todo(todoString, imp);
                currTodo->rightTodo->parent = currTodo;
                currTodo = currTodo->rightTodo;
                currTodo->setHeight(1);
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                // currTodo->adjustHeight();
                // while(currTodo->parent != NULL){
                    
                //     // Keep track of the path traversed from bottom to top
                //     if(currTodo->parent->leftTodo == currTodo){
                //         path.push("L");
                //     }
                //     else if(currTodo->parent->rightTodo == currTodo){
                //         path.push("R");
                //     }
                //     currTodo = currTodo->parent;
                //     currTodo->adjustHeight(path);
                // }
                while(currTodo != NULL){
                    currTodo->adjustHeight();
                    prevTodo = currTodo;
                    currTodo = currTodo->parent;
                }
                todoRoot = prevTodo;                        // currTodo has reached the most top node, set todoRoot to currYear
                numOfThings++;
                return true;
            }
            else currTodo = currTodo->rightTodo;
        }
        else {
            cout << "Todo already exist" << endl;
            return false;
        }
    }
    return false;
}

void Day::printByImportance() const{
    cout << "______________________________________________________" << endl;
    if(numOfThings == 0) printf("There is nothing on %d/%d/%d\n", yearNumber, monthNumber, dayNumber);
    printf("NUMBER OF TASKS(%d/%d/%d) = %d \n", yearNumber, monthNumber, dayNumber, numOfThings);
    cout << "*Sorted by Importance*" << endl;
    int i = 1;
    // if(todoRoot != NULL) cout << "****** TODO ROOT ********" << todoRoot->getTask() << endl;
    // else cout << "TODOROOT IS NULL" << endl;
    inorder(todoRoot, i);
    return;
}