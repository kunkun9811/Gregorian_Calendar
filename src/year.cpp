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
	stack<string> tempStack = path;						// Stack that help push back to the "Path" stack
	int LHeight = this->leftYear->getHeight();
	int RHeight = this->rightYear->getHeight();
	
	if(abs(LHeight - RHeight) > 1){
		
		// Checking the last two Node visited
		string thePath = tempStack.top();
		tempStack.pop();
		thePath += tempStack.top();
		tempStack.pop();

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
	LHeight = this->leftYear->getHeight();
	RHeight = this->rightYear->getHeight();
	this->height = max(LHeight, RHeight) + 1;
	
	
}

void Year::rotateLeft(Year *theNode){
	
}

void Year::rotateRight(Year *theNode){
	
}

void Year::rotateLeftKink(Year *theNode){
	
}

void Year::rotateRightKink(Year *theNode){
	
}