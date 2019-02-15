#ifndef YEAR_HPP
#define YEAR_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <string>

#include "month.hpp"

using namespace std;

/* Year:
 *	DATA STRUCTUR: AVL Tree
 *
 *
 *
 *
 *
 */

class Year{
	private:
		int yearNumber;						// This year's number
		//int height;							// This year node's height in the AVL Tree
		vector<Month*> months;	
		void rotateLeft(Year *theNode, stack<string> &path);
		void rotateRight(Year *theNode, stack<string> &path);
		void rotateLeftKink(Year *theNode, stack<string> &path);
		void rotateRightKink(Year *theNode, stack<string> &path);
		
	public:
		Year *leftYear;
		Year *rightYear;
		Year *parent;
		int height;
		
		Year(){
			leftYear = rightYear = parent = NULL;
			height = 1;
			yearNumber = 0;
		}
		Year(const int yearNum);
		unsigned int getYearNumber();
		void setYearNumber(int yearNum);
		unsigned int getHeight();
		void adjustHeight(stack<string> &path);
		
};


#endif
