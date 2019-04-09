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
		int yearNumber;							// This year's number
		int height;								// This year node's height in the AVL Tree
		vector<Month*> months;	
		void rotateLeft(Year *theNode);
		void rotateRight(Year *theNode);
		void rotateLeftKink(Year *theNode);
		void rotateRightKink(Year *theNode);
		
	public:
		Year *leftYear;
		Year *rightYear;
		Year *parent;
		
		Year(){
			leftYear = rightYear = parent = NULL;
			height = 1;
			yearNumber = 0;
		}
		Year(const int yearNum);
		unsigned int getYearNumber();
		void setYearNumber(int yearNum);
		unsigned int getHeight();
		void setHeight(int theHeight);
		int getBalance() const;
		int adjustHeight();
		Month* getMonth(int monthNum) const;
		
};


#endif
