#ifndef MONTH_HPP
#define MONTH_HPP

#include <iostream>
#include <vector>

#include "year.hpp"

using namespace std;

class Month : public Year{
    private:
        int monthNumber;
        int yearNumber;
    public:
        Month(const int &monthNum, const int &yearNum);
};

#endif
