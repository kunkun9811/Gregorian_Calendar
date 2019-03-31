#include <iostream>

using namespace std;

int dayNum(int y, int m, int d){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int main() {
    int j = 16;
    int i = 5;
    
    int test = dayNum(2019, 1, 1);
    cout << test << endl;
    
    return 0;
}

// set event -> set event -> set event ->
// for each month and each day go check into year to month to day and see if getImportance return more than 0