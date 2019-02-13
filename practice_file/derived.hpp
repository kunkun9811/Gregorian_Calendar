#ifndef DERIVED_HPP
#define DERIVED_HPP

#include <iostream>
#include <string>

#include "base.hpp"

using namespace std;

class derived : public base{
    public:
        derived() : name("Derived"){}
        void print();
        string getName();
    private: 
        string name;
};

string derived::getName(){
    return name;
}

void derived::print(){
    cout << "I am " << getName() << endl;
}

#endif