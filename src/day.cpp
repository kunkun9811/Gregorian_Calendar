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
        cout << "Please enter event or make sure Importance level is between 1 and 5" << endl;
        return false;
    }
    
}

// Edge case: If the successor is the immediate rightTodo Node of the nodeToDelete
//            If it is, don't set the rightTodo of Successor to the rightTodo 
//            of the nodeToDelete


/* Helper function for deleteEvent
 * Purpose: Delete the todo node in the AVL data structure of Todo class
 */
bool Day::removeNode(const Todo* theNode){
    cout << "I'm in remove Node" << endl;
    Todo* nodeToDelete = todoRoot;
    while(nodeToDelete != NULL){
        if(theNode->getTask() == nodeToDelete->getTask()){
            /* Node to delete has two children */
            if(nodeToDelete->leftTodo != NULL && nodeToDelete->rightTodo != NULL){
                Todo* theSuccessor = nodeToDelete->getSuccessor();
                Todo* theSucOldParent = theSuccessor->parent;              // Later we traverse from theSuccessor's parent to the top and adjustHeight() for each Node encountered
                if(theSuccessor != nodeToDelete->rightTodo){      
                    if(theSuccessor == theSuccessor->parent->leftTodo) theSuccessor->parent->leftTodo = NULL;
                    else theSuccessor->parent->rightTodo = NULL;
                }
                theSuccessor->rightTodo = nodeToDelete->rightTodo;      // Set theSuccessor's rightTodo to nodeToDelete's rightTodo
                nodeToDelete->rightTodo->parent = theSuccessor;         // set nodeToDelete's rightTodo's parent to theSuccessor
                theSuccessor->leftTodo = nodeToDelete->leftTodo;        // Set theSuccessor's leftTodo to nodeToDelete's leftTodo
                nodeToDelete->leftTodo->parent = theSuccessor;          // set nodeToDelete's leftTodo's parent to theSuccessor
                theSuccessor->parent = nodeToDelete->parent;            // Set theSuccessor's parent to nodeToDelete's parent
                
                // FIRST CHECK IF PARENT IS NULL, IF NOT, PRECEDE
                // Check if nodeToDelete is its parent's leftTodo or rightTodo. If is its leftTodo, set nodeToDelete's parent's leftTodo to theSuccessor
                // otherwise, set nodetToDelete's parent's rightTodo to theSuccessor
                if(nodeToDelete->parent != NULL){
                    if(nodeToDelete == nodeToDelete->parent->leftTodo) nodeToDelete->parent->leftTodo = theSuccessor;       
                    else nodeToDelete->parent->rightTodo = theSuccessor;
                }
                
                delete nodeToDelete;        // delete nodeToDelete
                
                // Adjust Height starting from the Successor's original parent - Because that's the bottom most node that had its subtrees modified. Anything lower than it has nothing changed.
                Todo* nodeToAdjust = theSucOldParent;
                stack<string> path;     // There's no need for path stack here. It is for function calling
                int LHeight = 0;
                int RHeight = 0;
                //int flag = 0;           // Flag to see if root is checked and going to the left subtree of root. when AFTER checking root(flag = 1), change from checking RR and RL to LL and LR
                while(nodeToAdjust != NULL){
                    /* Adjust Height for Remove */
                    
                    // Check if Tree is unbalanced
                    if(nodeToAdjust->leftTodo == NULL) LHeight = 0;
                    else LHeight = nodeToAdjust->leftTodo->getHeight();
                    
                    if(nodeToAdjust->rightTodo == NULL) RHeight = 0;
                    else RHeight = nodeToAdjust->rightTodo->getHeight();
                    
                    if(abs(LHeight - RHeight) > 1){
                        if(RHeight > LHeight){          // Have not reached root yet
                            if(nodeToAdjust->rightTodo != NULL){
                                if(nodeToAdjust->rightTodo->rightTodo != NULL){
                                    nodeToAdjust->rotateLeft(nodeToAdjust, path);
                                }
                                else if(nodeToAdjust->rightTodo->leftTodo != NULL){
                                    nodeToAdjust->rotateLeftKink(nodeToAdjust, path);
                                }
                            }
                        }
                        else{   // LHeight > RHeihgt
                            if(nodeToAdjust->leftTodo != NULL){
                                if(nodeToAdjust->leftTodo->leftTodo != NULL){
                                    nodeToAdjust->rotateRight(nodeToAdjust, path);
                                }
                                else if(nodeToAdjust->leftTodo->rightTodo != NULL){
                                    nodeToAdjust->rotateRightKink(nodeToAdjust, path);
                                }
                            }
                        }
                    }
                }
                return true;
            }
            
            /* Node to delete has one child */
            // Algorithm: only have to pull the only child up and point to nodeToDelete's old parent and 
            //            the old parent point to nodeToDelete's only child
            else if(nodeToDelete->leftTodo != NULL || nodeToDelete->rightTodo != NULL){
                if(nodeToDelete->leftTodo != NULL){
                    Todo* nodeToDeleteOldParent = nodeToDelete->parent;
                    Todo* nodeToDeleteLeftTodo = nodeToDelete->leftTodo;
                    if(nodeToDelete == nodeToDeleteOldParent->leftTodo){
                        nodeToDeleteOldParent->leftTodo = nodeToDeleteLeftTodo;
                        nodeToDeleteLeftTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        return true;
                    }
                    else{
                        nodeToDeleteOldParent->rightTodo = nodeToDeleteLeftTodo;
                        nodeToDeleteLeftTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        return true;
                    }
                }
                else if(nodeToDelete->rightTodo != NULL){
                    Todo* nodeToDeleteOldParent = nodeToDelete->parent;
                    Todo* nodeToDeleteRightTodo = nodeToDeleteRightTodo;
                    if(nodeToDelete == nodeToDeleteOldParent->leftTodo){
                        nodeToDeleteOldParent->leftTodo = nodeToDeleteRightTodo;
                        nodeToDeleteRightTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        return true;
                    }
                    else{
                        nodeToDeleteOldParent->rightTodo = nodeToDeleteRightTodo;
                        nodeToDeleteRightTodo->parent = nodeToDeleteOldParent;
                        delete nodeToDelete;
                        return true;
                    }
                }
            }
            
            /* Node To delete has no children */
            else if(nodeToDelete->leftTodo == NULL && nodeToDelete->rightTodo == NULL){
                if(nodeToDelete == nodeToDelete->parent->leftTodo) {
                    nodeToDelete->parent->leftTodo = NULL;
                    delete nodeToDelete;
                    return true;
                }
                else if(nodeToDelete == nodeToDelete->parent->rightTodo){
                    nodeToDelete->parent->rightTodo = NULL;
                    delete nodeToDelete;
                    return true;
                }
            }
        }
        else {
            // cout << "I'm here" << endl;
            if(nodeToDelete->getImportance() < theNode->getImportance()) nodeToDelete = nodeToDelete->rightTodo; 
            else if(nodeToDelete->getImportance() > theNode->getImportance()) nodeToDelete = nodeToDelete->leftTodo;
        }
        
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
        // Traverse the array to find and delete
        bool elementRemoved = false;                // Flag that shows if an element is removed, if not, it means the element was not in the file
        for(int i = 0; i < todoVector.size(); i++){
            if( todoString == todoVector.at(i)){
                todoVector.erase(todoVector.begin() + i);                // Only delete one
                impVector.erase(impVector.begin() + i);
                theImp = impVector.at(i);
                theTodo = todoVector.at(i);
                elementRemoved = true;
                break;
            }
        }
        if(elementRemoved){
            string tempString = todoString;                         // printf only takes non-const char pointer
            char *stringFirstCharPtr = &(tempString.at(0));         // char pointer that points to the first element(or character) of the string
            printf("Event '%s' removed.", stringFirstCharPtr);
            ostringstream oss;
            fstream outToFile;
            outToFile.open(fileName, ios_base::out | ios_base::trunc);           // To clear file
            if(!outToFile.is_open()){
                cout << "Could not write to the file. Error removing the event. Try Again." << endl;
                fileToRemoveFrom.close();               // close the input file
                return false;
            }
            else{
                outToFile.close();              // Cleared file
                outToFile.open(fileName);
                cout << endl;
                for(int i = 0; i < todoVector.size(); i++){
                    int impVal = impVector.at(i);
                    imp = to_string(impVal);
                    cout << "***IMP***" << imp << endl;
                    todo = todoVector.at(i);
                    oss << imp << endl;
                    oss << todo << endl;
                }
                outToFile << oss.str();
                outToFile.close();
            }
            fileToRemoveFrom.close();                   // close the input file
            outToFile.close();                          // close the output file
            
            // Create temporary Todo Node to traverse Tree
            Todo* tempTodo = new Todo(theTodo, theImp);
            removeNode(tempTodo);
            delete tempTodo;            // deallocate tempTodo
            cout << "I'm here 2" << endl;
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
        todoRoot->adjustHeight(path);
        numOfThings++;
        return true;
    }
    
    Todo *currTodo = todoRoot;
    while(currTodo){
        if(imp < currTodo->getImportance()){
            if(currTodo->leftTodo == NULL){
                currTodo->leftTodo = new Todo(todoString, imp);
                currTodo->leftTodo->parent = currTodo;
                currTodo = currTodo->leftTodo;
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                currTodo->adjustHeight(path);
                while(currTodo->parent != NULL){
                    
                    // Keep track of the path traversed from bottom to top
                    if(currTodo->parent->leftTodo == currTodo){
                        path.push("L");
                    }
                    else if(currTodo->parent->rightTodo == currTodo){
                        path.push("R");
                    }
                    currTodo = currTodo->parent;            
                    currTodo->adjustHeight(path);
                }
                todoRoot = currTodo;                        // currTodo has reached the most top node, set todoRoot to currYear
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
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                currTodo->adjustHeight(path);
                while(currTodo->parent != NULL){
                    
                    // Keep track of the path traversed from bottom to top
                    if(currTodo->parent->leftTodo == currTodo){
                        path.push("L");
                    }
                    else if(currTodo->parent->rightTodo == currTodo){
                        path.push("R");
                    }
                    currTodo = currTodo->parent;
                    currTodo->adjustHeight(path);
                }
                todoRoot = currTodo;                        // currTodo has reached the most top node, set todoRoot to currYear
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
    printf("NUMBER OF TASKS(%d/%d/%d) = %d \n\n", yearNumber, monthNumber, dayNumber, numOfThings);
    cout << "*Sorted by Importance*" << endl;
    int i = 1;
    inorder(todoRoot, i);
    return;
}