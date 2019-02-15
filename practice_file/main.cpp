#include <iostream>
#include <array>
#include <string>

#include "base.hpp"
#include "derived.hpp"

using namespace std;

int main(){
    base b;
    derived d;
    
    b.print();
    d.print();
    
    string a = "hello";
    cout << a.size() << endl;
    return 0;
}



