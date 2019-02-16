#include <iostream>

#include "test1.hpp"

using namespace std;

bool Todo::operator<(const Todo& other){
    return importance >= other.importance;
}

string Todo::getTask() const{
    return task;
}

unsigned int Todo:: getImportance() const{
    return importance;
}