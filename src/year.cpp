#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

#include "year.hpp"
#include "month.hpp"

using namespace std;

Year::Year(const int yearNum){
	setYearNumber(yearNum);
	height = 1;
	leftYear = rightYear = parent = NULL;
	months.resize(12);
	for(int i = 0; i < months.size(); i++){				
		months.at(i) = new Month(yearNumber, i+1);
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

void Year::setHeight(int theHeight){
	this->height = theHeight;
	return;
}

int Year::getBalance() const { 
	int LHeight = 1;
	int RHeight = 1;
	
	if(this->leftYear != NULL) LHeight = this->leftYear->getHeight();
	if(this->rightYear != NULL) RHeight = this->rightYear->getHeight();
	
	int difference = abs(LHeight - RHeight);
	return difference;
}

// void Year::adjustHeight(stack<string> &path){
// 	if(this == NULL){
// 		return;
// 	}
	
// 	// Check if Tree is unbalanced
// 	int LHeight = 0;
// 	int RHeight = 0;
	
	
// 	if(this->leftYear == NULL) {
// 		LHeight = 0;
// 	}
// 	else {
// 		LHeight = this->leftYear->getHeight();
// 	}
	
// 	if(this->rightYear == NULL) {
// 		RHeight = 0;
// 	}
// 	else {
// 		RHeight = this->rightYear->getHeight();
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
// 	if(this->leftYear == NULL) LHeight = 0;
// 	else LHeight = this->leftYear->getHeight();
	
// 	if(this->rightYear == NULL) RHeight = 0;
// 	else RHeight = this->rightYear->getHeight();
	
// 	this->height = max(LHeight, RHeight) + 1;
	
// 	return;
// }

int Year::adjustHeight() {
	int LHeight = 1;
	int RHeight = 1;
	int balance = 0;
	
	if(this->leftYear != NULL) LHeight = this->leftYear->getHeight() + 1;
	if(this->rightYear != NULL) RHeight = this->rightYear->getHeight() + 1;
	
	this->height = max(LHeight, RHeight);
	
	// Check if any rotation is needed
	balance = this->getBalance();
	if(balance > 1){
		int leftH = 1;
		int rightH = 1;
		
		if(LHeight > RHeight){	//LL or LR
			Year* theLeftYear = this->leftYear;
			if(theLeftYear->leftYear != NULL) leftH = theLeftYear->leftYear->getHeight();
			if(theLeftYear->rightYear != NULL) rightH = theLeftYear->rightYear->getHeight();
			
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
		Year* theRightYear = this->rightYear;
		if(theRightYear->leftYear != NULL) leftH = theRightYear->leftYear->getHeight();
		if(theRightYear->rightYear != NULL) rightH = theRightYear->rightYear->getHeight();
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

Month* Year::getMonth(int monthNum) const{
	return months.at(monthNum - 1);
}

void Year::rotateLeft(Year *top){
	// Prevent rotating NULL 
	// cout << "I'm in rotateLeft" << endl;
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
	if(rightLeftChild != NULL) rightLeftChild->parent = top;
	newTop->leftYear = top;
	
	// Adjust Height after rotation
	top->adjustHeight();
	newTop->adjustHeight();
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight();
	}
	return;
}

void Year::rotateRight(Year *top){
	// cout << "I'm in rotateRight" << endl;
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
	if(leftRightChild != NULL) leftRightChild->parent = top;
	newTop->rightYear = top;
	
	// Adjust Height after rotation
	top->adjustHeight();
	newTop->adjustHeight();
	if(oldTopParent != NULL){
		oldTopParent->adjustHeight();
	}
	return;
}

void Year::rotateLeftKink(Year *top){
	// cout << "I'm in rotateLeftKink" << endl;
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
	
	// Adjust Height after first rotation
	top->adjustHeight();
	oldRight->adjustHeight();
	newRight->adjustHeight();
	
	rotateLeft(top);
	return;
}

void Year::rotateRightKink(Year *top){
	// cout << "I'm in rotateRightKink" << endl;
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
	
	// Adjust Height after first rotation
	top->adjustHeight();
	oldLeft->adjustHeight();
	newLeft->adjustHeight();
	
	rotateRight(top);
	return;
}