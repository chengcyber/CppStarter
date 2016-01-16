/*
 * File: calendar.h
 * ----------------------
 * calendar contains a Month type along with 
 * the  functions  daysInMonth  and  isLeapYear
 */

#ifndef _calendar_h
#define _calendar_h

#include <string>
#include <iostream>

/* Month type as a common month 
 * Usage: Month month;
 */
enum Month { 
   JANUARY = 1, 
   FEBRUARY, 
   MARCH, 
   APRIL, 
   MAY, 
   JUNE, 
   JULY, 
   AUGUST, 
   SEPTEMBER, 
   OCTOBER, 
   NOVEMBER, 
   DECEMBER
}; 

/* class Date */
class Date {
public:

/* Constructors: Date
 * Usage: 
 * 			Date date();
 * 			Date date(20, JULY, 1969)
 * 			Date date(JULY, 20, 1969)
 * ---------------------
 * Create a date type contains day,month,year seperately.
 * default constructor is JANUARY,20,1970
 */
	
	Date();
	Date(Month m, int d, int y);
	Date(int d, Month m, int y);

/*
 * Methods: getDay, getMonth, getYear
 * Usage: 
 * 			int d = date.getDay()
 * 			int m = date.getMonth()
 * 			int y = date.getYear()
 * -----------------------------------
 * Accessors or getters of the instance variables of the Date type.
 */

 	int getDay();
 	Month getMonth();
 	int getYear();

/*
 * Method: toString()
 * Usage: date.toString()
 * -----------------------
 * Returns the date in the form "dd-mmm-yyyy"
 * "20-Jul-1969"
 */

 	std::string toString();

   friend bool operator== (Date & d1, Date & d2);
   friend bool operator!= (Date & d1, Date & d2);

   friend bool operator<= (Date & d1, Date & d2);
   friend bool operator>= (Date & d1, Date & d2);
   friend bool operator< (Date & d1, Date & d2);
   friend bool operator> (Date & d1, Date & d2);

   void nextDay();
   void lastDay();


private:
	Month month;
	int day;
	int year;
};


/*
 * Function: daysInMonth
 * Usage: int day = dayInMonth(month)
 * ----------------------------------
 * Returns how many day in the month of the year.
 * especially, Feb 29 only in leapyear.
 */

int daysInMonth(Month month, int year);

/*
 * Function: isLeapYear
 * Usage: if (isLeapYear(year)) . . .
 * -----------------------------------
 * Return a boolean type if the parameter is a leapyear.
 */
bool isLeapYear(int year);

/*
 * Function: lastMonth
 * usage: Month last = lastMonth(month)
 * --------------------------------
 * Returns the last month of Month month.
 */
Month lastMonth(Month mo);

/*
 * Function: nextMonth
 * Usage: Month next = nextMonth(month)
 * -------------------------------------
 * Returns the next month of Month month.
 */
Month nextMonth(Month mo);

/*
 * Function monthToString
 * usage: string line = monthToString(month)
 * ---------------------------------------
 * Returns the string value of the Month month.
 */
std::string monthToString(Month month);


/* Operator Overloading section */

/*
 * Operator: <<
 * Usage: cout << date
 * -----------------------
 * Overloads << operator so that it is able to display date.
 */

std::ostream & operator<< (std::ostream & os, Date & date);

/*
 * Operator: ==,!=
 * Usage:
 * 		if(d1 == d2) . . .
 * 		if(d1 != d2) . . .
 * -------------------------
 * Returns true if d1 and d2 contains same value (==)
 * != in the other hand.
 */
bool operator== (Date & d1, Date & d2);
bool operator!= (Date & d1, Date & d2);

/*
 * Operator: <=, >=, <, >
 * -------------------------
 * Relation operators, Compare the values of d1 and d2.
 */
bool operator<= (Date & d1, Date & d2);
bool operator>= (Date & d1, Date & d2);
bool operator< (Date & d1, Date & d2);
bool operator> (Date & d1, Date & d2);

/*
 * Operator: +, -
 * -------------------------
 * Methematics operators.
 */
Date operator+ (Date d1, int n);
Date operator- (Date d1, int n);

/*
 * Operator: +=, -=
 * -------------------------
 * shorthand operators.
 * Returns the next n day of date. (+=)
 */
Date & operator+= (Date & d1, int n);
Date & operator-= (Date & d1, int n);

/*
 * Operator Overloading: ++
 * Usage: mon++, ++mon
 * ------------------------------
 * Return the next month while ++mon, the original month while mon++
 */
Month operator++(Month & mon);
Month operator++(Month & mon, int);
std::ostream & operator<<(std::ostream & os, Month & mon);
#endif

