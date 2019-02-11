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
		int yearNumber;
		vector<Month*> months;	
	public:
		Year(int yearNum); 
};


#endif
