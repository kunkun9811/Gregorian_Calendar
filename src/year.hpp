#ifndef YEAR_HPP
#define YEAR_HPP

#include <iostream>
#include <vector>
#include <stack>

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
		//int yearNumber;						// This year's number
		//int height;							// This year node's height in the AVL Tree
		vector<Month*> months;	
		
		
	public:
		Year *leftYear;
		Year *rightYear;
		Year *parent;
		int height;
		
		Year(const int yearNum);
		unsigned int getYearNumber();
		void setYearNumber(int yearNum);
		unsigned int getHeight();
		void adjustHeight(stack<string> &path);
		
		// NEED TO MOVE BACK TO PRIVATE
		void rotateLeft(Year *theNode);
		void rotateRight(Year *theNode);
		void rotateLeftKink(Year *theNode);
		void rotateRightKink(Year *theNode);
		
		int yearNumber;
		// NEED TO MOVE BACK TO PRIVATE
};


#endif
