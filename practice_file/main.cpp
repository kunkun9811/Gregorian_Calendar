#include <iostream>

#include "base.hpp"
#include "derived.hpp"

using namespace std;

int main(){
    base b;
    derived d;
    
    b.print();
    d.print();
    
    return 0;
}