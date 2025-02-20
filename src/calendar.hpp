/* Calendar Class
 * 
 * Input: A specific year in Gregorian Calendar
 * Output: Creates an object for a specific year (Gregorian Calendar)
 * 
 * 1/24/19  = First Started
 *
 */
 
#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <iostream>
#include <vector>
#include <string>

#include "year.hpp"

using namespace std;

/* Calendar:
 *	Function:
 *		(1) Print the whole year
 *			OPTION: Choose Print Specific Year
 *			FORMAT: 1998
 *			1. Find if year exist from the AVL Tree structure of Year
 *				a. if yes, create a normal format of the specific year's whole calendar ( W x L : 3 x 4 )
 * 				b. if not, create a new node of Year(that has months, days) and do step (a) 
 *
 *		(2) Print the whole month	// for now no
 *			OPTION: Choose Print Specific Month
 *			FORMAT: 1998/1
 *			1. Find if year exist from the AVL Tree structure of Year
 *				a. if yes, create a normal format of the specific year's whole calendar ( W x L : 3 x 4 )
 * 				b. if not, create a new node of Year(that has months, days)
 *			2. Print the specific month in the specific year in format ( Sun Mon Tue Wed Thurs Fri Sat) until it prints every single day
 *
 *		(3) Print the list of TODOs in a specific date ( In importance level 1 ~ 5, HIGH ~ LOW )
 *			OPTION: Choose print TODO
 *			FORMAT: 1998/1/1
 *		(3) Set Event on a specific date
 *			OPTION: Choose Set event
 *			FORMAT: 1998/1/1	
 *		(4) Remove a specific event
 *			OPTION: Choose remove event
 *			FORMAT: string1 = "1998/1/1"
 *				    string2 = "*Event title*"
 *
 *
 *
 *
 *	Extra Function:
 *		(1) Income for each day
 *
 *
 *
 *
 */
class Calendar {
	private:
        Year *yearRoot;
        
        void deleteAll(Year *yearNode);
    public:
        Calendar() : yearRoot(NULL) {}
   	    ~Calendar(){
   	        deleteAll(yearRoot);
   	    }
   	    Year* insertYear(int yearNum);
   	    Year* getYearRoot() const;
   	    void printYear();
   	    void printMonth();
   	    void printTodos() const;
   	    int monthNumDays(const int &yearNum, const int &monthNum);
   	    string monthName(const int &monthNum);
   	    int dayOfWeek(int y, int m, int d);
   	    void printCalendar(int year);
   	    bool setEvent(int y, int, int d, const string &todoString, const int imp);
   	    bool deleteEvent(int y, int m, int d, const string &todoString);
   	    void printByImportance(int y, int m, int d);
   	    
   	    // Just to test tree, PRINT TREE
   	    void inorder(Year *yearNode) const;
};

#endif
