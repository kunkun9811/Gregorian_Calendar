#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <sstream>

// #include "base.hpp"
// #include "derived.hpp"

using namespace std;

int main(){
    // base b;
    // derived d;
    
    // b.print();
    // d.print();
    
    // string a = "hello";
    // cout << a.size() << endl;
    int importance = 0;
    string TODO = "";

    istream iss1;       //for importance
    istream iss2;       //for TODO
    ifstream dayFile;
    dayFile.open("../server/1998-1-1.txt"); 
    if(!dayFile.is_open()){             // If file doesn't exist, do nothing
        return; 
    }
    else{
        dayFile >> iss1;
        
    }
    return 0;
}



