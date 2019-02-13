#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

using namespace std;

class base{
    public:
        base() : name("Base"){}
        virtual void print();
        virtual string getName();
    private: 
        string name;
};

void base::print(){
    cout << "I am " << getName() << endl;
}

string base::getName(){
    return name;
}

#endif