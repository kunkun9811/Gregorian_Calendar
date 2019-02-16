#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>

#include "day.hpp"

using namespace std;

Day::Day(int yearNum, int monthNum, int dayNum){
    yearNumber = yearNum;
    monthNumber = monthNum;
    dayNumber = dayNum;
    numOfThings = 0;
    todoRoot = NULL;
}

/* PURPOSE: Read the file of this spcific day
 *          (1) If file doesn't exist - return
 *              **Meaning this specific day has nothing planned
 *          (2) If file exist, for each TODO create a corresponding
 *              TODO node and insert into the tree
 */
void Day::readDayFile(){
    string fileName = "../server/" + to_string(yearNumber) + "-" + to_string(monthNumber) + "-" + to_string(dayNumber) + ".txt";
    ifstream dayFile;
    dayFile.open(fileName); 
    if(!dayFile.is_open()){             // If file doesn't exist, do nothing
        return; 
    }
    else{
        
    }
    return;
}

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
    printf("(%d) \n", i);
    string tempString = todoNode->getTask();
    char *stringPtr = &(tempString.at(0));
    printf("TODO: %s \n \n", stringPtr);
    i++;
    inorder(todoNode->rightTodo, i);
    return;
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

void Day::printByImpotyance() const{
    printf("Number of Tasks(%d/%d/%d) = %d \n", yearNumber, monthNumber, dayNumber, numOfThings);
    int i = 1;
    inorder(todoRoot, i);
    return;
}