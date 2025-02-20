#include <iostream>
#include <stack>
#include <string>

#include "calendar.hpp"

#define underline "\e[4m"                 //underline code
#define cyan "\e[96m"
#define reset "\e[0m"

using namespace std;

void Calendar::inorder(Year *yearNode) const{
    if(yearNode == NULL){
        return;
    }
    inorder(yearNode->leftYear);
    cout << yearNode->getYearNumber() << endl;
    // cout << "height Number: " << yearNode->getHeight() << endl << endl;
    inorder(yearNode->rightYear);
    return;  
}

void Calendar::deleteAll(Year *yearNode){
    if(yearNode == NULL){
        return;
    }
    yearNode->leftYear;
    yearNode->rightYear;
    delete yearNode;
    return;
}

Year* Calendar::insertYear(int yearNum){
    stack<string> path;
    if(yearRoot == NULL){
        Year *tempYearNode = new Year(yearNum);
        yearRoot = tempYearNode;
        yearRoot->adjustHeight();
        return yearRoot;
    }
    
    Year *currYear = yearRoot;
    Year* prevYear = NULL;
    Year* returnYear = NULL;
    while(currYear){
        if(yearNum < currYear->getYearNumber()){
            if(currYear->leftYear == NULL){
                currYear->leftYear = new Year(yearNum);
                currYear->leftYear->parent = currYear;
                currYear = currYear->leftYear;
                currYear->setHeight(1);
                returnYear = currYear;
                
                // // Update Heights traverse to parents to NULL and DO necessary rotations
                // currYear->adjustHeight(path);
                // while(currYear->parent != NULL){
                    
                //     // Keep track of the path traversed from bottom to top
                //     if(currYear->parent->leftYear == currYear){
                //         path.push("L");
                //     }
                //     else if(currYear->parent->rightYear == currYear){
                //         path.push("R");
                //     }
                //     currYear = currYear->parent;
                //     currYear->adjustHeight(path);
                // }
                while(currYear != NULL){
                    currYear->adjustHeight();
                    prevYear = currYear;
                    currYear = currYear->parent;
                }
                yearRoot = prevYear;                // currYear has reached passed the most top node, set yearRoot to currYear
                return returnYear;
            }
            else currYear = currYear->leftYear;
        }
        else if(yearNum > currYear->getYearNumber()){
            if(currYear->rightYear == NULL){
                currYear->rightYear = new Year(yearNum);
                currYear->rightYear->parent = currYear;
                currYear = currYear->rightYear;
                currYear->setHeight(1);
                returnYear = currYear;
                
                // Update Heights traverse to parents to NULL and DO necessary rotations
                // currYear->adjustHeight(path);
                // while(currYear->parent != NULL){
                    
                //     // Keep track of the path traversed from bottom to top
                //     if(currYear->parent->leftYear == currYear){
                //         path.push("L");
                //     }
                //     else if(currYear->parent->rightYear == currYear){
                //         path.push("R");
                //     }
                //     currYear = currYear->parent;
                //     currYear->adjustHeight(path);
                // }
                while(currYear != NULL){
                    currYear->adjustHeight();
                    prevYear = currYear;
                    currYear = currYear->parent;
                }
                yearRoot = prevYear;            // currYear has reached the most top node, set yearRoot to currYear
                return returnYear;
            }
            else currYear = currYear->rightYear;
        }
        else {
            returnYear = currYear;
            return returnYear;
        }
    }
    return NULL;
}

Year* Calendar::getYearRoot() const{
    return yearRoot;
}

int Calendar::monthNumDays(const int &yearNum, const int &monthNum){
	if(monthNum == 1){
		return (31);	
	}
	else if(monthNum == 2){
	    Month currMonth(yearNum, monthNum);
		if(currMonth.isLeapYear()){
			return (29);	
		}
		else return (28);
	}
	else if(monthNum == 3){
		return (31);	
	}
	else if(monthNum == 4){
		return (30);	
	}
	else if(monthNum == 5){
		return (31);	
	}
	else if(monthNum == 6){
		return (30);	
	}
	else if(monthNum == 7){
		return (31);	
	}
	else if(monthNum == 8){
		return (31);	
	}
	else if(monthNum == 9){
		return (30);	
	}
	else if(monthNum == 10){
		return (31);	
	}
	else if(monthNum == 11){
		return (30);	
	}
	else if(monthNum == 12){
		return (31);	
	}
	else{
		cout << "Invalid Month Number" << endl;
	}
}

string Calendar::monthName(const int &monthNum){
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[monthNum - 1];
}

int Calendar::dayOfWeek(int y, int m, int d){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;     // because Jan and Feb are calculated from last year Dec 31st
                    // March to Dec are calculated from current year's Dec 31st
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void Calendar::printCalendar(int year){
    Year* currYear = insertYear(year);
    // int currMonth = monthNumDays(year, month);
    Month* currMonth = NULL;
    Day* currDay = NULL;
    int currDayNum = dayOfWeek(year, 1, 1);
    int monthDays = 0;

    for(int i = 0; i < 12; i++){
        currMonth = currYear->getMonth(i+1);
        monthDays = monthNumDays(year, i + 1);
        printf("\n  ------------%s-------------\n", monthName(i+1).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        
        int j = 0;
        for(j = 0; j < currDayNum; j++){       // print spaces
            printf("     ");
        }

        for(int k = 1; k <= monthDays; k++){
            currDay = currMonth->getDay(k);
            if(currDay) {
                // cout << "I'm here" << endl;
                if(currDay->getNumOfThings() > 0){
                    // cout << "I'm here 1" << endl;
                    printf(cyan "%5d" reset, k);
                }
                else printf("%5d", k);
            }
            else printf("%5d", k);
            
            if(++j > 6){ // meaning we just printed the day for Sat, need to go to next line
                j = 0;
                cout << endl;
            }
            
        }
        
        if(j) 
            cout << endl;     // will reach here if we finished printing all days in currentMonth but still need to print another newline for next month
                
        currDayNum = j;
    }
    return;
}

bool Calendar::setEvent(int y, int m, int d, const string &todoString, const int imp){
    Year* theYear = insertYear(y);
    Month* theMonth = theYear->getMonth(m);
    Day* theDay = theMonth->getDay(d);
    return theDay->setEvent(todoString, imp);
}

bool Calendar::deleteEvent(int y, int m, int d, const string &todoString){
    Year* theYear = insertYear(y);
    Month* theMonth = theYear->getMonth(m);
    Day* theDay = theMonth->getDay(d);
    return theDay->deleteEvent(todoString);
}

void Calendar::printByImportance(int y, int m, int d){
    Year* theYear = insertYear(y);
    Month* theMonth = theYear->getMonth(m);
    Day* theDay = theMonth->getDay(d);
    theDay->printByImportance();
    return;
}