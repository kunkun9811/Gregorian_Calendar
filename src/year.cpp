#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

#include "year.hpp"
#include "month.hpp"

using namespace std;

Year::Year(const int yearNum){
	setYearNumber(yearNum);
	leftYear = rightYear = parent = NULL;
	months.resize(12);
	for(int i = 0; i < months.size(); i++){				
		months.at(i) = new Month(i+1, yearNumber);
	}
}

unsigned int Year::getYearNumber() {
	return yearNumber;
}

void Year::setYearNumber(int yearNum) {
	yearNumber = yearNum;
	return;
}

unsigned int Year::getHeight(){
	return this->height;
}

void Year::adjustHeight(stack<string> &path){
	if(this == NULL){
		return;
	}
	
	// Check if Tree is unbalanced
	int LHeight = 0;
	int RHeight = 0;
	
	
	if(this->leftYear == NULL) {
		LHeight = 0;
	}
	else {
		LHeight = this->leftYear->getHeight();
	}
	
	if(this->rightYear == NULL) {
		RHeight = 0;
	}
	else {
		RHeight = this->rightYear->getHeight();
	}
	
	if(abs(LHeight - RHeight) > 1){
		
		// Checking the last two Node visited
		string thePath = "";
		thePath += path.top();
		path.pop();
		thePath += path.top();
		path.pop();

		if(thePath == "RR"){
			rotateLeft(this);
		}
		else if(thePath == "LL"){
			rotateRight(this);
		}
		else if(thePath == "RL"){
			rotateLeftKink(this);
		}
		else if(thePath == "LR"){
			rotateRightKink(this);
		}
	}
	
	// Post fixing tree, adjust the Height for the current node
	if(this->leftYear == NULL) LHeight = 0;
	else LHeight = this->leftYear->getHeight();
	
	if(this->rightYear == NULL) RHeight = 0;
	else RHeight = this->rightYear->getHeight();
	
	this->height = max(LHeight, RHeight) + 1;
	
	
}

void Year::rotateLeft(Year *top){
	// Prevent rotating NULL 
	if(top == NULL) return;
	
	Year *oldTopParent = top->parent;
	Year *newTop = top->rightYear;
	Year *rightLeftChild = top->rightYear->leftYear;
	
	// Edge case: if Top is root, don't set oldparent to newTop
	if(oldTopParent != NULL){
		if(oldTopParent->leftYear == top){
			oldTopParent->leftYear = newTop;
		}
		else if(oldTopParent->rightYear == top){
			oldTopParent->rightYear = newTop;				
		}
	}
	newTop->parent = oldTopParent;
	top->parent = newTop;
	top->rightYear = rightLeftChild;
	rightLeftChild->parent = top;
	newTop->leftYear = top;
	return;
}

void Year::rotateRight(Year *top){
	// Prevent rotating NULL
	if(top == NULL) return;
	
	Year *oldTopParent = top->parent;
	Year *newTop = top->leftYear;
	Year *leftRightChild = top->leftYear->rightYear;
	
	// Edge case: if Top is root, don't set oldparent to newTop
	if(oldTopParent != NULL){
		if(oldTopParent->leftYear == top){
			oldTopParent->leftYear = newTop;
		}
		else if(oldTopParent->rightYear == top){
			oldTopParent->rightYear = newTop;
		}
	}
	newTop->parent = oldTopParent;
	top->parent = newTop;
	top->leftYear = leftRightChild;
	leftRightChild->parent = top;
	newTop->rightYear = top;
	return;
}

void Year::rotateLeftKink(Year *top){
	// Prevent rotating NULL
	if(top == NULL) return;	
	
	Year *oldRight = top->rightYear;
	Year *newRight = top->rightYear->leftYear;
	Year *newRightRight = newRight->rightYear;
	
	top->rightYear = newRight;
	newRight->parent = top;
	newRight->rightYear = oldRight;
	oldRight->leftYear = newRightRight;
	oldRight->parent = newRight;
	if(newRightRight != NULL) newRightRight->parent = oldRight;
	rotateLeft(top);
	return;
}

void Year::rotateRightKink(Year *top){
	// Prevent rotating NULL
	if(top == NULL) return;	
	
	Year *oldLeft = top->leftYear;
	Year *newLeft = top->leftYear->rightYear;
	Year *newLeftLeft = newLeft->leftYear;
	
	top->leftYear = newLeft;
	newLeft->parent = top;
	newLeft->leftYear = oldLeft;
	oldLeft->rightYear = newLeftLeft;
	oldLeft->parent = newLeft;
	if(newLeftLeft != NULL) newLeft->parent = oldLeft;
	rotateRight(top);
	return;
}