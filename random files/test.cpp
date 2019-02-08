#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void randomFunction(const int &a);

int main() {
    // streampos size;
    // char *memblock;
    
    // ifstream file("file.bin", ios::in | ios::ate | ios::binary);
    // if(!file.is_open()){
    //     cout << "Unable to open the file." << endl;
    //     return -1;
    // }
    // else {
    //     size = file.tellg();
    //     memblock = new char[size];
    //     file.seekg(0, ios::beg);
    //     file.read(memblock, size);
    //     file.close();
        
    //     cout << "The entire file content is in memory" << endl;
    //     cout << "Would you like to print out the file in text format? (y/n)" << endl;
        
    //     char response = ' ';
    //     cin >> response;
    //     if(response == 'y') {
    //         for(int i = 0; i < size; ++i){
    //             cout << *(memblock + i) << endl;
    //         }
    //     }
    //     else if(response == 'n') {
    //         cout << "OK! Bye :)" << endl;
    //     }
    //     else cout << "Invalid response" << endl;
    // }
    
     /*
    // We can change where the pointer points to, but not the actual data pointed to
    const int *ptr1 = &a;
    int const *ptr2 = &a;
    
    // We can change the actual data pointed to, but not where the pointer points to
    int * const ptr3 = &b;
    
    // We can't change the actual data pointed to, nor the address the pointer points to
    const int * const ptr4 = &c;
    int const * const ptr5 = &c;
    
    // VALID
    ptr1 = &b;
    cout << "Pointer 1: " << *ptr1 << endl;
    cout << "a: " << a << endl;
    
    ptr2 = &c;
    cout << "Pointer 2: " << *ptr2 << endl;
    cout << "a: " << a << endl;
    
    *ptr3 = 111;
    cout << "Pointer 3: " << *ptr3 << endl;
    cout << "b: " << b << endl;
    */
    
    /* reference
    int a = 5;
    const int b = 7;
    int c = 9;
    
    int & ref1 = a;
    cout << "a: " << a << endl;
    ref1 = 213123;
    cout << "ref1: " << ref1 << endl;
    cout << "a after: " << a << endl;
    
    const int & ref2 = c;
    cout << "c: " << c << endl;
    cout << "ref2: " << ref2 << endl;
    
    int const & ref3 = b;
    cout << "ref3: " << ref3 << endl;
    cout << "b: " << b << endl;
    
    int & ref4 = b;
    */
    /*
    char a = 'a';
    const char *c = "Hello";
    for(int i = 0; i <= 5; i++){
        cout << *(c+i) << endl;
    }
    char const **cp = &c;
    for(int i = 0; i <= 5; i++){
        cout << *(*cp+i) << endl;
    }
    */
    
    int *a = new int (10);
    cout << a << endl;
    delete a;
    
    cout << a << endl;
    
    return 0;
}
