#include <iostream>

#include "year.hpp"
#include "month.hpp"

using namespace std;

Year::Year(const int yearNum){
	yearNumber = yearNum;
	leftYear = rightYear = parent = NULL;
	months.resize(12);
	for(int i = 0; i < months.size(); i++){				
		months.at(i) = new Month(i+1, yearNumber);
	}
}

bool Year::isLeapYear() const {
	if(((yearNumber % 4 == 0) && (yearNumber % 100 != 0)) || (yearNumber % 400 == 0)) return true;
	else return false;
}
