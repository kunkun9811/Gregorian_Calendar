#include <iostream>

#include "month.hpp"
#include "year.hpp"

Month::Month(const int &yearNum, const int &monthNum){
	yearNumber = yearNum;
	monthNumber = monthNum;
	
	if(monthNum == 1){
		days.resize(31);	
	}
	else if(monthNum == 2){
		if(isLeapYear()){
			days.resize(29);	
		}
		else days.resize(28);
	}
	else if(monthNum == 3){
		days.resize(31);	
	}
	else if(monthNum == 4){
		days.resize(30);	
	}
	else if(monthNum == 5){
		days.resize(31);	
	}
	else if(monthNum == 6){
		days.resize(30);	
	}
	else if(monthNum == 7){
		days.resize(31);	
	}
	else if(monthNum == 8){
		days.resize(31);	
	}
	else if(monthNum == 9){
		days.resize(30);	
	}
	else if(monthNum == 10){
		days.resize(31);	
	}
	else if(monthNum == 11){
		days.resize(30);	
	}
	else if(monthNum == 12){
		days.resize(31);	
	}
	else{
		cout << "Invalid Month Number" << endl;
	}

	for(int i = 0; i < days.size(); i++){
		days.at(i) = new Day(yearNumber, monthNumber, i + 1);
	}
}

Day* Month::getDay(const int &dayNum) const{
	Day* theDay = days.at(dayNum - 1);
	return theDay;
}

bool Month::isLeapYear() const {
	if(((yearNumber % 4 == 0) && (yearNumber % 100 != 0)) || (yearNumber % 400 == 0)) return true;
	else return false;
}