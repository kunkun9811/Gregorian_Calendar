#ifndef MONTH_HPP
#define MONTH_HPP

#include <iostream>
#include <vector>

#include "day.hpp"
#include "year.hpp"

using namespace std;

class Month : public Year{
    private:
        int monthNumber;
        int yearNumber;
        vector<Day*> days;
    public:
        Month(int monthNum, int yearNum);
    
};

#endif
