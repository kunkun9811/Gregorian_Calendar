#ifndef MONTH_HPP
#define MONTH_HPP

#include <iostream>
#include <vector>

#include "day.hpp"

using namespace std;

class Month{
    private:
        int monthNumber;
        int yearNumber;
        vector<Day*> days;
    public:
        Month(const int &yearNum, const int &monthNum);
        bool isLeapYear() const;
};

#endif
