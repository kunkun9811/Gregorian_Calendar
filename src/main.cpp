#include <iostream>
#include <vector>
#include <string>

//testing
#include <stack>

#define underline "\e[4m"                 //underline code
#define cyan "\e[96m"
#define reset "\e[0m"

#include "calendar.hpp"

using namespace std;


/* TASK:
 *  (1) I need to adjustHeight in cases in day.cpp where it's not nodeToDelete with two children
 *
 *
 */
void printCalendar(int year); 

int main() {
    
    cout << "Calendar" << endl;

    
    
    return 0;
}

void printCalendar(int year){
    
}

/* GAGDETS I CAN USE */
// system("cls") - clear screen

/* Things I changed temporarily */
// rotations in year.hpp need to be moved back to private AND YEAR NUMBER
// rotations in year.cpp: I cout a lot of I'm in *this rotation*
// day.hpp: I moved priority_queue to public, it should be private
// day.hpp: I moved todoRoot to public, it should be private

/* THING I NEED TO ADD */
// Time of when the thing is happening !!!!!!!!
// I NEED TO NOT USE getline WHEN READING THE FILES. **DELETE EVENT AND DAY FILE IN DAY.CPP*
    // NEED TO ALSO ADD DESCRIPTION, INSTEAD OF JUST TITLES
    
/* TESTING SETTING EVENT ON DAY.CPP */
//     Day a(1998, 1, 2);
//     a.readDayFile();
//     a.printByImportance();

//     // a.setEvent("new todo1", 4);
//     // a.setEvent("new todo2", 3);
//     // a.setEvent("new todo3", 5);
//     // a.setEvent("Sleep", 2);
//     // a.setEvent("finish calendar coding", 3);
//     // a.setEvent("Play games", 5);
//     // a.setEvent("hang out with hanna", 1);
//     // a.setEvent("hang out with joycelyn", 2);
//     // a.setEvent("drink", 3);
//     // a.setEvent("hang out with Jasmine", 1);
//     a.setEvent("1_", 4);
//     a.setEvent("2_", 3);
//     a.setEvent("3_", 5);
//     a.setEvent("4_", 2);
//     a.setEvent("5_", 3);
//     a.setEvent("6_", 5);
//     a.setEvent("7_", 1);
//     a.setEvent("8_", 2);
//     a.setEvent("9_", 3);
//     a.setEvent("10_", 1);
    
//     a.printByImportance();
    
//     // string response = "finish calendar coding";
//     // a.deleteEvent("new todo1");
//     // a.deleteEvent("hang out with hanna");
//     // a.deleteEvent("1_");
//     // a.deleteEvent("7_");
//     // a.deleteEvent("2_");
//     // a.deleteEvent("4_");
    
    
//     cout << "What would you like to delete" << endl;
//     string response;
//     getline(cin, response);
//     while(response != "n"){
//         a.deleteEvent(response);
//         a.printByImportance();
//         getline(cin, response);
//     }
    
    
//     a.printByImportance();
//     // 5 6 3 2

/* Testing code for inserting */
    // a.insertTodo("Wash Dishes", 3);
    // a.insertTodo("Do Homework", 1);
    // a.insertTodo("Play video game", 4);
    // a.insertTodo("study", 2);
    // a.insertTodo("sleep", 5);
    // a.insertTodo("2 number 1", 1);
    // a.insertTodo("3 number 1", 1);
    // a.insertTodo("4 number 1", 1);
    // a.insertTodo("5 number 1", 1);
    // a.insertTodo("6 number 1", 1);
    
/* temporary inorder print tree function */
    // void inorderPrint(Year *root);
    // void inorderPrint(Year *root){
    //     if(root == NULL){
    //         return;
    //     }
    //     inorderPrint(root->leftYear);
    //     cout << root->getYearNumber() << endl;
    //     inorderPrint(root->rightYear);
    //     return;
    // }
    
/* Calendar insert and inorder print tree testing code */
    // Calendar a;
    // a.insertYear(1998);
    // a.insertYear(1900);
    // a.insertYear(2100);
    // a.insertYear(1800);
    // a.insertYear(1920);
    // a.insertYear(2050);
    // a.insertYear(2200);
    // a.insertYear(2300);
    // a.insertYear(2190);
    // a.insertYear(2180);
    // a.insertYear(1700);
    // a.insertYear(1850);
    // a.insertYear(1860);
    
    
    // a.inorder(a.getYearRoot());

/* rotateLeftKink testing code */
    // Year *year1 = new Year(1998);
    // Year *year2 = new Year(1900);
    // Year *year3 = new Year(2100);
    // Year *year4 = new Year(1800);
    // Year *year5 = new Year(1920);
    // Year *year6 = new Year(2050);
    // Year *year7 = new Year(2200);
    
    // Year *year8 = new Year(2190);
    // Year *year9 = new Year(2300);
    // Year *year10 = new Year(2195);
    
    // year1->leftYear = year2;
    // year1->rightYear = year3;
    // year1->parent = NULL;
    // year2->leftYear = year4;
    // year2->rightYear = year5;
    // year2->parent = year1;
    // year3->leftYear = year6;
    // year3->rightYear = year7;
    // year3->parent = year1;
    // year4->parent = year2;
    // year5->parent = year2;
    // year6->parent = year3;
    // year7->parent = year3;
    
    // year7->leftYear = year8;
    // year7->rightYear = year9;
    // year8->parent = year7;
    // year9->parent = year7;
    // year8->rightYear = year10;
    // year10->parent = year8;
    
    
    // cout << "Before leftRotation: " << endl;
    // // cout << "year3 right child: " << year3->rightYear->yearNumber << endl;
    // // cout << "year3 right left child: " << year3->rightYear->leftYear->yearNumber << endl;
    // // cout << "year7 right child: " << year7->rightYear->yearNumber << endl;
    // // cout << "year7 left child: " << year7->leftYear->yearNumber << endl;
    // inorderPrint(year1);
    // cout << endl << endl;
    
    
    // year3->rotateLeftKink(year3);

    
    // cout << "After leftRotation: " << endl;
    // cout << "Year 2100 leftchild: ";
    // if(year3->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year3->leftYear->yearNumber << endl;
    // cout << "Year 2100 rightchild: ";
    // if(year3->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year3->rightYear->yearNumber << endl;
    // cout << "Year 2100 parent: ";
    // if(year3->parent == NULL) cout << "NULL" << endl << endl << endl;
    // else cout << year3->parent->yearNumber << endl << endl << endl;
    
    // cout << "Year 2200 leftchild: ";
    // if(year7->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year7->leftYear->yearNumber << endl;
    // cout << "Year 2200 rightchild: ";
    // if(year7->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year7->rightYear->yearNumber << endl;
    // cout << "Year 2200 parent: ";
    // if(year7->parent == NULL) cout << "NULL" << endl << endl << endl;
    // else cout << year7->parent->yearNumber << endl << endl << endl;
    
    // cout << "Year 2190 leftchild: ";
    // if(year8->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year8->leftYear->yearNumber << endl;
    // cout << "Year 2190 rightchild: ";
    // if(year8->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year8->rightYear->yearNumber << endl;
    // cout << "Year 2190 parent: ";
    // if(year8->parent == NULL) cout << "NULL" << endl << endl << endl;
    // else cout << year8->parent->yearNumber << endl << endl << endl;
    
    // cout << "Year 2195 leftchild: ";
    // if(year10->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year10->leftYear->yearNumber << endl;
    // cout << "Year 2195 rightchild: ";
    // if(year10->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year10->rightYear->yearNumber << endl;
    // cout << "Year 2195 parent: ";
    // if(year10->parent == NULL) cout << "NULL" << endl << endl << endl;
    // else cout << year10->parent->yearNumber << endl << endl << endl;
    
    // cout << "Year 1998 leftchild: ";
    // if(year1->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year1->leftYear->yearNumber << endl;
    // cout << "Year 1998 rightchild: ";
    // if(year1->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year1->rightYear->yearNumber << endl;
    // cout << "Year 1998 parent: ";
    // if(year1->parent == NULL) cout << "NULL" << endl << endl << endl;
    // else cout << year1->parent->yearNumber << endl << endl << endl;
    
    
    // inorderPrint(year1);
    // cout << endl << endl;

/* rotateLeft testing code */
    // Year *year1 = new Year(1998);
    // Year *year2 = new Year(1900);
    // Year *year3 = new Year(2100);
    // Year *year4 = new Year(1800);
    // Year *year5 = new Year(1920);
    // Year *year6 = new Year(2050);
    // Year *year7 = new Year(2200);
    
    // Year *year8 = new Year(2150);
    // Year *year9 = new Year(2300);
    // Year *year10 = new Year(2400);
    
    // year1->leftYear = year2;
    // year1->rightYear = year3;
    // year1->parent = NULL;
    // year2->leftYear = year4;
    // year2->rightYear = year5;
    // year2->parent = year1;
    // year3->leftYear = year6;
    // year3->rightYear = year7;
    // year3->parent = year1;
    // year4->parent = year2;
    // year5->parent = year2;
    // year6->parent = year3;
    // year7->parent = year3;
    // year7->leftYear = year8;
    // year7->rightYear = year9;
    
    // year8->parent = year7;
    // year9->parent = year7;
    // year9->rightYear = year10;
    // year10->parent = year9;
    
    // cout << "Before leftRotation: " << endl;
    // inorderPrint(year1);
    // cout << endl << endl;
    
    // year6->rotateLeft(year3);
    
    // cout << "After leftRotation: " << endl;
    // cout << "Year 2200 leftchild: ";
    // if(year7->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year7->leftYear->yearNumber << endl;
    // cout << "Year 2200 rightchild: ";
    // if(year7->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year7->rightYear->yearNumber << endl;
    // cout << "Year 2200 parent: " << year7->parent->yearNumber << endl;
    
    // cout << "Year 2150 leftchild: ";
    // if(year8->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year8->leftYear->yearNumber << endl;
    // cout << "Year 2150 rightchild: ";
    // if(year8->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year8->rightYear->yearNumber << endl;
    // cout << "Year 2150 parent: ";
    // if(year8->parent == NULL) cout << "NULL" << endl;
    // else cout << year8->parent->yearNumber << endl;
    
    // cout << "Year 1998 leftchild: ";
    // if(year1->leftYear == NULL) cout << "NULL" << endl;
    // else cout << year1->leftYear->yearNumber << endl;
    // cout << "Year 1998 rightchild: ";
    // if(year1->rightYear == NULL) cout << "NULL" << endl;
    // else cout << year1->rightYear->yearNumber << endl;
    // cout << "Year 1998 parent: ";
    // if(year1->parent == NULL) cout << "NULL" << endl;
    // else cout << year1->parent->yearNumber << endl;
    
    // cout << "Year 2100 leftchild: " << year3->leftYear->yearNumber << endl;
    // cout << "Year 2100 rightchild: " << year3->rightYear->yearNumber << endl;
    // cout << "Year 2100 parent: " << year3->parent->yearNumber << endl;
    
    // inorderPrint(year1);
    // cout << endl << endl;

/* adjustHeight Testing code */
    // stack<string> a;
    
    // a.push("R");
    // a.push("L");
    
    
    // Year *year1 = new Year(1998);
    // Year *year2 = new Year(2000);
    // Year *year3 = new Year(2018);
    
    // year2->height = 2;
    // year3->height = 1;
    // year1->rightYear = year2;
    // year2->rightYear = year3;
    // year1->adjustHeight(a);
    
    