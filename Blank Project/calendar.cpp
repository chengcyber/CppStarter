/*
 * File: calendar.cpp
 * ---------------------
 * implementation of calendar.h
 */

#include <string>
#include "strlib.h"
#include <iostream>
#include "calendar.h"
#include "error.h"
#include <cmath>
using namespace std;

/* Function prototypes */

/*
 * Implementation note: dayInMonth
 * -------------------------------
 * This function returns the day in the month of the year.
 * normally 30 or 31, Feb 28 or 29 in leapyear.
 */

int daysInMonth(Month month, int year) { 
   switch (month) { 
    case APRIL: 
    case JUNE: 
    case SEPTEMBER: 
    case NOVEMBER: 
      return 30; 
    case FEBRUARY: 
      return (isLeapYear(year)) ? 29 : 28; 
    default: 
      return 31; 
   } 
} 

/*
 * Implementation note: isLeapYear
 * -----------------------------
 * This function check whether the year is leapyear.
 */

 bool isLeapYear(int year) { 
   return ((year % 4 == 0) && (year % 100 != 0)) 
        || (year % 400 == 0); 
} 

/*
 * Implementation notes: lastMonth,nextMonth
 * ------------------------------------------
 * These functions use the remainder operator to cycle through the
 * internal values of the enumeration type.
 */
Month lastMonth(Month mo) {
	if (mo == JANUARY) {
		mo = DECEMBER;
	} else {
		mo = Month(mo - 1);
	}
	return mo;
}

Month nextMonth(Month mo) {
	if (mo == DECEMBER) {
		mo = JANUARY;
	} else {
		mo = Month(mo + 1);
	}
	return mo;
}


/*
 * Implementation note: monthToString
 * ---------------------------------
 * This function returns the name of the month.
 */
std::string monthToString(Month month) {
	switch(month) {
		case JANUARY : return "JANUARY"; break;
		case FEBRUARY : return "FEBRUARY"; break;
		case MARCH : return "MARCH"; break;
		case APRIL : return "APRIL"; break;
		case MAY : return "MAY"; break;
		case JUNE : return "JUNE"; break;
		case JULY : return "JULY"; break;
		case AUGUST : return "AUGUST"; break;
		case SEPTEMBER : return "SEPTEMBER"; break;
		case OCTOBER : return "OCTOBER"; break;
		case NOVEMBER : return "NOVEMBER"; break;
		case DECEMBER : return "DECEMBER"; break;
		default: return "???"; break;
	}
}


/*
 * Implementation note: OperatorOverloading <<
 * Usage: cout << mon
 * -------------------------
 * Overloads the insertion operator to display month.
 */

ostream & operator<<(ostream & os, Month & mon) {
	return os << monthToString(mon);
}

/*
 * Impmentation notes: OperaterOverloading ++
 * ------------------------------------------
 * Prefix ++ give the nextMonth but returns it,
 * Suffix ++ give the nextMonth and returns the original month.
 */
Month operator++(Month & mon) {
	return nextMonth(mon);
}

Month operator++(Month & mon, int) {
	Month org = mon;
	mon = nextMonth(mon);
	return org;
}


/* Implemente class date */

/* Implementation note: constructors. */

Date::Date() {
	month = JANUARY;
	day = 1;
	year = 1970;
}

Date::Date(Month m, int d, int y) {
	month = m;
	if (d >= 1 && d <= daysInMonth(m, y)) 
		day = d;
	else
		error("Invaild day value!");
	if ( y >= 1900 && y<= 9999)
		year = y;
	else
		error("Invaild year value!");

}

Date::Date(int d, Month m, int y) {
	this->Date::Date(m, d, y);
}

int Date::getDay() {
	return day;
}

Month Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

string Date::toString() {
	return integerToString(day) + "-"
	 + monthToString(month).substr(0,3) + "-"
	 + integerToString(year);
}



ostream & operator<< (ostream & os, Date & date) {
	return os << date.toString();
}

bool operator== (Date & d1, Date & d2) {
	return (d1.day == d2.day &&
		d1.month == d2.month &&
		d1.year == d2.year);
}

bool operator!= (Date & d1, Date & d2) {
	return !(d1 == d2);
}


bool operator<= (Date & d1, Date & d2) {
	return ((d1 < d2) || (d1 == d2));
}

bool operator>= (Date & d1, Date & d2) {
	return ((d1 > d2) || (d1 == d2));
}

bool operator< (Date & d1, Date & d2) {
	if (d1.year < d2.year) 
		return true;
	else if (d1.year == d2.year)
		if (d1.month < d2.month)
			return true;
		else if (d1.month == d2.month)
			if (d1.day < d2.day)
				return true;
	return false;
}

bool operator> (Date & d1, Date & d2) {
	if (d1.year > d2.year) 
		return true;
	else if (d1.year == d2.year)
		if (d1.month > d2.month)
			return true;
		else if (d1.month == d2.month)
			if (d1.day > d2.day)
				return true;
	return false;
}


Date operator+ (Date d1, int n) {
	for(int i = 0; i < n; i++)
		d1.nextDay();
	return d1;
}

Date operator- (Date d1, int n) {
	for(int i = 0; i < n; i++)
		d1.lastDay();
	return d1;
}


Date & operator+= (Date & d1, int n) {
	d1 = d1 + n;
	return d1;
}

Date & operator-= (Date & d1, int n) {
	d1 = d1 - n;
	return d1;
}

void Date::nextDay() {
	// int day = date.getDay();
	// Month month = date.getMonth();
	// int year = date.getYear();

	if (day == daysInMonth(month, year)) {
		if (month == DECEMBER) {
			year++;
		}
		month = nextMonth(month);
		day = 1;
	} else {
		day++;
	}

}

void Date::lastDay() {

	// int day = date.getDay();
	// Month month = date.getMonth();
	// int year = date.getYear();

	if (day == 1) {
		if (month == JANUARY) {
			year--;
		}
		month = lastMonth(month);
		day = daysInMonth(month, year);
	} else {
		day--;
	}

}