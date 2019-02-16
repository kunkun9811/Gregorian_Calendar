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
    
    string a = "hello";
    cout << a.size() << endl;
    int importance = 0;
    string TODO = "";

    string imp;         //for importance
    string todo;        //for TODO
    string separator;   //for the character '^' between each todo in text file
    ifstream dayFile;
    dayFile.open("../server/1998-1-1.txt"); 
    
    if(!dayFile.is_open()){             // If file doesn't exist, do nothing
        cout << "ERROR: FILE NOT FOUND" << endl; 
    }
    else{
        while(!getline(dayFile, imp).eof()){          //eof returns true when it is in the end of file, otherwise false
            //cout << "Imp: " << imp << endl;
            //cin.ignore(100, '\n');           // Ignore the next character, which is '\n'
            getline(dayFile, todo); // Get the string of TODO on the next line
            //cout << "TODO: " << todo << endl;
            // cin.ignore(100, '\n');
            getline(dayFile, separator);
            //cout << "separator: " << separator << endl;
            // cin.ignore(100, '\n');
            importance = stoi(imp);
            TODO = todo;
            //cout << "Done" << endl << endl;
        }
    }
    cout << "Importance: " << importance << endl;
    cout << "TODO: " << todo << endl;
    
    return 0;
}



