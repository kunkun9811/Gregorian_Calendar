#include <iostream>

#include "day.hpp"

using namespace std;

Day::Day(int yearNum, int monthNum, int dayNum){
    yearNumber = yearNum;
    monthNumber = monthNum;
    dayNumber = dayNum;
    numOfThings = 0;
    todoRoot = NULL;
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

void Day::inorder(Todo *todoNode) const{
    if(todoNode == NULL){
        return;
    }
    inorder(todoNode->leftTodo);
    cout << *todoNode << endl;
    inorder(todoNode->rightTodo);
    return;
}

bool Day::insertTodo(const string &todoString, const int imp){
    stack<string> path;
    if(todoRoot == NULL){
        Todo *tempTodoRoot = new Todo(todoString, imp);
        todoRoot = tempTodoRoot;
        todoRoot->adjustHeight(path);
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
                
                
                return true;
            }
            else currTodo = currTodo->leftTodo;
        }
        else if(imp > currTodo->getImportance()){
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