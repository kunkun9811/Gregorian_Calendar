#include <iostream>
#include <algorithm>

#include "todo.hpp"

using namespace std;

// bool Todo::operator<(const Todo& other){
//     return importance >= other.importance;
// }

string Todo::getTask() const{
    return task;
}

void Todo::setTask(string theTask) {
	task = theTask;
	return;
}

int Todo::getImportance() const{
    return importance;
}

void Todo::setImportance(int theImportance){
	importance = theImportance;
	return;
}

int Todo::getHeight() const{
    return height;
}

void Todo::setHeight(int theHeight){
	this->height = theHeight;
	return;
}


// void Todo::adjustHeight(stack<string> &path){
// 	if(this == NULL){
// 		return;
// 	}
	
// 	// Check if Tree is unbalanced
// 	int LHeight = 0;
// 	int RHeight = 0;
	
	
// 	if(this->leftTodo == NULL) {
// 		LHeight = 0;
// 	}
// 	else {
// 		LHeight = this->leftTodo->getHeight();
// 	}
	
// 	if(this->rightTodo == NULL) {
// 		RHeight = 0;
// 	}
// 	else {
// 		RHeight = this->rightTodo->getHeight();
// 	}
	
// 	if(abs(LHeight - RHeight) > 1){
		
// 		// Checking the last two Node visited
// 		string thePath = "";
// 		thePath += path.top();
// 		path.pop();
// 		thePath += path.top();
// 		path.pop();

// 		if(thePath == "RR"){
// 			rotateLeft(this, path);
// 		}
// 		else if(thePath == "LL"){
// 			rotateRight(this, path);
// 		}
// 		else if(thePath == "RL"){
// 			rotateLeftKink(this, path);
// 		}
// 		else if(thePath == "LR"){
// 			rotateRightKink(this, path);
// 		}
// 	}
	
// 	// Post fixing tree, adjust the Height for the current node
// 	if(this->leftTodo == NULL) LHeight = 0;
// 	else LHeight = this->leftTodo->getHeight();
	
// 	if(this->rightTodo == NULL) RHeight = 0;
// 	else RHeight = this->rightTodo->getHeight();
	
// 	this->height = max(LHeight, RHeight) + 1;
	
// 	return;
// }

int Todo::adjustHeight() {
	int LHeight = 1;
	int RHeight = 1;
	int balance = 0;
	
	if(this->leftTodo != NULL) LHeight = this->leftTodo->getHeight() + 1;
	if(this->rightTodo != NULL) RHeight = this->rightTodo->getHeight() + 1;
	
	this->height = max(LHeight, RHeight);
	
	// Check if any rotation is needed
	balance = this->getBalance();
	if(balance > 1){
		int leftH = 1;
		int rightH = 1;
		
		if(LHeight > RHeight){	//LL or LR
			Todo* theLeftTodo = this->leftTodo;
			if(theLeftTodo->leftTodo != NULL) leftH = theLeftTodo->leftTodo->getHeight();
			if(theLeftTodo->rightTodo != NULL) rightH = theLeftTodo->rightTodo->getHeight();
			
			if(leftH >= rightH){ //LL
				// cout << "Rotating at " << this->getTask() << endl;
				rotateRight(this);
			}
			else{
				// cout << "Rotating at " << this->getTask() << endl;
				rotateRightKink(this);
			}
		}
		else if(LHeight < RHeight){ // RR or RL
		Todo* theRightTodo = this->rightTodo;
		if(theRightTodo->leftTodo != NULL) leftH = theRightTodo->leftTodo->getHeight();
		if(theRightTodo->rightTodo != NULL) rightH = theRightTodo->rightTodo->getHeight();
			if(rightH >= leftH){
				// cout << "Rotating at " << this->getTask() << endl;
				rotateLeft(this);
			}
			else{
				// cout << "Rotating at " << this->getTask() << endl;
				rotateLeftKink(this);
			}
		}
	}
	return this->height;
}

int Todo::getBalance() const { 
	int LHeight = 1;
	int RHeight = 1;
	
	if(this->leftTodo != NULL) LHeight = this->leftTodo->getHeight();
	if(this->rightTodo != NULL) RHeight = this->rightTodo->getHeight();
	
	int difference = abs(LHeight - RHeight);
	return difference;
}

void Todo::rotateLeft(Todo *top){
	// Prevent rotating NULL 
	// cout << "I'm in rotateLeft" << endl;
	if(top == NULL) return;
	
	Todo *oldTopParent = top->parent;
	Todo *newTop = top->rightTodo;
	Todo *rightLeftChild = top->rightTodo->leftTodo;
	
	// Edge case: if Top is root, don't set oldparent to newTop
	if(oldTopParent != NULL){
		if(oldTopParent->leftTodo == top){
			oldTopParent->leftTodo = newTop;
		}
		else if(oldTopParent->rightTodo == top){
			oldTopParent->rightTodo = newTop;				
		}
	}
	newTop->parent = oldTopParent;
	top->parent = newTop;
	top->rightTodo = rightLeftChild;
	if(rightLeftChild != NULL) rightLeftChild->parent = top;
	newTop->leftTodo = top;
	
	// Adjust Height after rotation
	top->adjustHeight();
	newTop->adjustHeight();
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight();
	}
	return;
}

void Todo::rotateRight(Todo *top){
	// cout << "I'm in rotateRight" << endl;
	// Prevent rotating NULL
	if(top == NULL) return;
	
	Todo *oldTopParent = top->parent;
	Todo *newTop = top->leftTodo;
	Todo *leftRightChild = top->leftTodo->rightTodo;
	
	// Edge case: if Top is root, don't set oldparent to newTop
	if(oldTopParent != NULL){
		if(oldTopParent->leftTodo == top){
			oldTopParent->leftTodo = newTop;
		}
		else if(oldTopParent->rightTodo == top){
			oldTopParent->rightTodo = newTop;
		}
	}
	newTop->parent = oldTopParent;
	top->parent = newTop;
	top->leftTodo = leftRightChild;
	if(leftRightChild != NULL) leftRightChild->parent = top;
	newTop->rightTodo = top;
	
	// Adjust Height after rotation
	top->adjustHeight();
	newTop->adjustHeight();
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight();
	}
	return;
}

void Todo::rotateLeftKink(Todo *top){
	// cout << "I'm in rotateLeftKink" << endl;
	// Prevent rotating NULL
	if(top == NULL) return;	
	
	Todo *oldRight = top->rightTodo;
	Todo *newRight = top->rightTodo->leftTodo;
	Todo *newRightRight = newRight->rightTodo;
	
	top->rightTodo = newRight;
	newRight->parent = top;
	newRight->rightTodo = oldRight;
	oldRight->leftTodo = newRightRight;
	oldRight->parent = newRight;
	if(newRightRight != NULL) newRightRight->parent = oldRight;
	
	// Adjust Height after first rotation
	top->adjustHeight();
	oldRight->adjustHeight();
	newRight->adjustHeight();
	
	rotateLeft(top);
	return;
}

void Todo::rotateRightKink(Todo *top){
	// cout << "I'm in rotateRightKink" << endl;
	// Prevent rotating NULL
	if(top == NULL) return;	
	
	Todo *oldLeft = top->leftTodo;
	Todo *newLeft = top->leftTodo->rightTodo;
	Todo *newLeftLeft = newLeft->leftTodo;
	
	top->leftTodo = newLeft;
	newLeft->parent = top;
	newLeft->leftTodo = oldLeft;
	oldLeft->rightTodo = newLeftLeft;
	oldLeft->parent = newLeft;
	if(newLeftLeft != NULL) newLeft->parent = oldLeft;
	
	// Adjust Height after first rotation
	top->adjustHeight();
	oldLeft->adjustHeight();
	newLeft->adjustHeight();
	
	rotateRight(top);
	return;
}

/* Get the successor(or the next node) in the Inorder sequence */
Todo* Todo::getSuccessor() {
	// Case (1): If current todo node has no parent and has no right child
	if(this->rightTodo == NULL && this->parent == NULL){
		return this->leftTodo;
	}
	// Case (2): If current todo node has no right child
	// ** NEED TO INCLUDE EDGE CASE WHERE THE NODE IS RIGHT MOST NODE **
	else if(this->rightTodo == NULL && this->parent != NULL){
		Todo* theSuc = successorAtAbove(this);
		if(theSuc == NULL) return this;				// Happens when we are finding the successor of rightmost todo node (a.k.a. the largest todo Node)
		else return theSuc;
	}
	// case (3): current todo node has right child
	else if(this->rightTodo != NULL){
		return successorAtRight(this->rightTodo);
	}
}

/* Helper function for searching upward to find successor */
Todo* Todo::successorAtAbove(Todo* currTodoNode){
	Todo* currNode = currTodoNode;
	Todo* currNodeParent = currNode->parent;
	
	while(currNodeParent != NULL){
		if(currNode == currNodeParent->leftTodo) return currNodeParent;
		else {
			currNode = currNodeParent;
			currNodeParent = currNodeParent->parent;
		}
	}
	return currNodeParent;				// Will reach here if currTodoNode passed in is the right most node of the tree
}

/* Helpfer function for searching the left-most node on the right subtree */
Todo* Todo::successorAtRight(Todo *currTodoNode) {
	if(currTodoNode->leftTodo == NULL) return currTodoNode;
	else if(currTodoNode->leftTodo != NULL) return successorAtRight(currTodoNode->leftTodo);
}



