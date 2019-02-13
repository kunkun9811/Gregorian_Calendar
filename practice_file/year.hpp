#ifndef YEAR_HPP
#define YEAR_HPP

#include <iostream>
#include <vector>

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
		int height;
		vector<Month*> months;	
		
		void rotateLeft(Year *theNode);
		void rotateRight(Year *theNode);
		void rotateLeftKink(Year *theNode);
		void rotateRightKink(Year *theNode);
	public:
		Year *leftYear;
		Year *rightYear;
		Year *parent;
		int yearNumber;						// This year's number
	
		Year(const int yearNum);
		void adjustHeight();
		bool isLeapYear() const;
};


#endif
