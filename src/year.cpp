#include <iostream>

#include "year.hpp"

Year::Year(){
	months.resize(12);
	for(int i = 0; i < months.size(); i++){				
		months.at(i) = new Month(i+1, yearNumber);
	}
}
