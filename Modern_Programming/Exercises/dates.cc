/* Exercise : 26
 * ID 		: 1943290
 * Name 	: Shadly Salahuddin
 */

#include "dates.h"

void dates::Date::checkDate()
{
  if (year < 1 || month < 1 || month > 12 || day < 1
      || (day > daysPerMonth[month - 1]
          && !(day == 29 && month == 2 && isLeapYear(year))))
    {
      day = month = 1;
      year = stdYear;
    }
}

dates::Date& dates::Date::incDay()
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

dates::Date& dates::Date::operator++()
{
  incDay();
  return *this;
}

const dates::Date dates::Date::operator++(int)
{
  dates::Date temp{*this};
  incDay();
  return temp;
}

