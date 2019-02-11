#ifndef MONTH_HPP
#define MONTH_HPP

#include <iostream>
#include <vector>

#include "day.hpp"

using namespace std;

class Month {
    private:
	int monthNumber;
        vector<Day*> days;
    public:
        Month(int monthNum, int yearNum);
    
};

#endif
