// class date, constructor with initializer list
// author:  Holger Arndt
// version: 09.10.2019

#include <iostream>
#include <string.h>

using namespace std;

class Date
{
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

  int rata_die_day() const {
    Date date;
    memcpy(&date, this, sizeof(Date));
    if (date.month < 3){
      date.year--;
      date.month += 12;
    }
    return 365*date.year + date.year/4 - date.year/100 + date.year/400 + (153*date.month - 457)/5 + date.day - 306;
  }

public:
  explicit Date(int d = 1, int m = 1, int y = stdYear) : day{d}, month{m}, year{y}
  {
    checkDate();
  }
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
  void print() const { cout << day << '.' << month << '.' << year << endl; }

  int dayInYear() const {
    int day_in_year = 0;
    if((this->month - 1) > 0){
      for (int i = 0; i < this->month; i++){
        day_in_year = day_in_year + this->daysPerMonth[i - 1];
      }
    }
    day_in_year = day_in_year + this->day + ((this->isLeapYear(this->year) && (this->month > 2)) ? 1 : 0);
    return day_in_year;
  }

  int operator-(const Date& d2) const{
    return this->rata_die_day() - d2.rata_die_day();
  }
};



void Date::checkDate()
{
  if (year < 1 || month < 1 || month > 12 || day < 1
      || (day > daysPerMonth[month - 1]
          && !(day == 29 && month == 2 && isLeapYear(year))))
    {
      day = month = 1;
      year = stdYear;
    }
}

Date& Date::incDay()
{
  ++day;
  if (day > daysPerMonth[month - 1]
      && !(day == 29 && month == 2 && isLeapYear(year)))
    {
      day = 1;
      if (++month == 13)
        {
          month = 1;
          ++year;
        }
    }
  return *this;
}


int main()
{
  Date d1;
  d1.print();
  Date d2{13, 7};
  d2.print();
  Date d3{13, 7, 1999};
  d3.print();
  cout << "Day in Year : " << d3.dayInYear() << endl;
  cout << "Days Difference : " << d3 - d1 << endl;
}
