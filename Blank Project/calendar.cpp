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
void nextDay(Date & date);
void lastDay(Date & date);


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
Month lastMonth(Month month) {
	return Month((month + 11) % 12);
}

Month nextMonth(Month month) {
	return Month((month + 1) % 12);
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
	return mon = Month((mon + 1));
}

Month operator++(Month & mon, int) {
	Month org = mon;
	mon = Month((mon + 1));
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



ostream & operator<< (ostream & os, Date::Date & date) {
	return os << date.toString();
}

bool operator== (Date & d1, Date & d2) {
	return (d1.getDay() == d2.getDay() &&
		d1.getMonth() == d2.getMonth() &&
		d1.getYear() == d2.getYear());
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
	if (d1.getDay() < d2.getDay()) 
		return true;
	else if (d1.getMonth() < d2.getMonth())
		return true;
	else if (d1.getYear() < d2.getYear())
		return true;
	else
		return false;
}

bool operator> (Date & d1, Date & d2) {
	if (d1.getDay() > d2.getDay()) 
		return true;
	else if (d1.getMonth() > d2.getMonth())
		return true;
	else if (d1.getYear() > d2.getYear())
		return true;
	else
		return false;
}


Date operator+ (Date d1, int n) {
	for(int i = 0; i < n; i++)
		nextDay(d1);
	return d1;
}

Date operator- (Date d1, int n) {
	for(int i = 0; i < n; i++)
		lastDay(d1);
	return d1;
}


Date & operator+= (int n) {
	this = this + n;
	return this;
}

Date & operator-= (int n) {
	this = this - n;
	return this;
}

void nextDay(Date & date) {

}

void lastDay(Date & date) {

}