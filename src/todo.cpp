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

int Todo::getImportance() const{
    return importance;
}

int Todo::getHeight() const{
    return height;
}


void Todo::adjustHeight(stack<string> &path){
	if(this == NULL){
		return;
	}
	
	// Check if Tree is unbalanced
	int LHeight = 0;
	int RHeight = 0;
	
	
	if(this->leftTodo == NULL) {
		LHeight = 0;
	}
	else {
		LHeight = this->leftTodo->getHeight();
	}
	
	if(this->rightTodo == NULL) {
		RHeight = 0;
	}
	else {
		RHeight = this->rightTodo->getHeight();
	}
	
	if(abs(LHeight - RHeight) > 1){
		
		// Checking the last two Node visited
		string thePath = "";
		thePath += path.top();
		path.pop();
		thePath += path.top();
		path.pop();

		if(thePath == "RR"){
			rotateLeft(this, path);
		}
		else if(thePath == "LL"){
			rotateRight(this, path);
		}
		else if(thePath == "RL"){
			rotateLeftKink(this, path);
		}
		else if(thePath == "LR"){
			rotateRightKink(this, path);
		}
	}
	
	// Post fixing tree, adjust the Height for the current node
	if(this->leftTodo == NULL) LHeight = 0;
	else LHeight = this->leftTodo->getHeight();
	
	if(this->rightTodo == NULL) RHeight = 0;
	else RHeight = this->rightTodo->getHeight();
	
	this->height = max(LHeight, RHeight) + 1;
	
	return;
}

void Todo::rotateLeft(Todo *top, stack<string> &path){
	// Prevent rotating NULL 
	cout << "I'm in rotateLeft" << endl;
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
	top->adjustHeight(path);
	newTop->adjustHeight(path);
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight(path);
	}
	return;
}

void Todo::rotateRight(Todo *top, stack<string> &path){
	cout << "I'm in rotateRight" << endl;
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
	top->adjustHeight(path);
	newTop->adjustHeight(path);
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight(path);
	}
	return;
}

void Todo::rotateLeftKink(Todo *top, stack<string> &path){
	cout << "I'm in rotateLeftKink" << endl;
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
	top->adjustHeight(path);
	oldRight->adjustHeight(path);
	newRight->adjustHeight(path);
	
	rotateLeft(top, path);
	return;
}

void Todo::rotateRightKink(Todo *top, stack<string> &path){
	cout << "I'm in rotateRightKink" << endl;
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
	top->adjustHeight(path);
	oldLeft->adjustHeight(path);
	newLeft->adjustHeight(path);
	
	rotateRight(top, path);
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



