#include <iostream>
#include <vector>
#include <string>

#include <stack>

#include "calendar.hpp"

using namespace std;

int main() {
    
    cout << "Calendar" << endl;

    Calendar a;
    a.printCalendar(1996);
    
    a.setEvent(1996, 1, 1, "Hi", 1);
    
    return 0;
}