/* Exercise : 26
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#ifndef DATES_H
#define DATES_H

#include <iostream>

namespace dates{
	class Date{
	private:
	  int day;
	  int month;
	  int year;
	  static inline const int daysPerMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30,
	      31, 30, 31 };
	  static const int stdYear{1970};
	  static bool isLeapYear(int year)
	  { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	  void checkDate();
	public:
	  explicit Date(int d = 1, int m = 1, int y = stdYear) : day{d}, month{m},
	                                                         year{y}
	  {
	    checkDate();
	  }
	  Date(const Date& d2) : day{d2.day}, month{d2.month}, year{d2.year} {}
	  int getDay() const { return day; }
	  int getMonth() const { return month; }
	  int getYear() const { return year; }
	  void setDate(int d, int m, int y)
	  {
	    day = d;
	    month = m;
	    year = y;
	    checkDate();
	  }
	  Date& incDay();
	  Date& operator++();
	  const Date operator++(int);
	  void print() const { std::cout << day << '.' << month << '.' << year << std::endl; }
	};
}
#endif