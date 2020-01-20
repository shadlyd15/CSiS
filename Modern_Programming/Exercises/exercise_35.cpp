/* Exercise : 35
 * ID       : 1943290
 * Name     : Shadly Salahuddin
 */

#include <iomanip>
#include <iostream>

using namespace std;

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
	Date(){}
  explicit Date(int d, int m, int y) : day{d}, month{m},
                                                         year{y}
  {
  	cout << "Checking constructor : " << endl;
    checkDate();
  }
  Date(const Date& d2) : day{d2.day}, month{d2.month}, year{d2.year} {
  	cout << "Checking constructor : " << endl;
    checkDate();
  }

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }
	void setDate(int d, int m, int y){
		day = d;
		month = m;
		year = y;
		cout << "Checking setDate : " << endl;
		checkDate();
	}

	Date& incDay();
	Date& operator++();
	const Date operator++(int);
	void print() const { cout << day << '.' << month << '.' << year << endl; }
};


Date& Date::incDay(){
	++day;
	if (day > daysPerMonth[month - 1] && !(day == 29 && month == 2 && isLeapYear(year))){
		day = 1;
		if (++month == 13){
			month = 1;
			++year;
		}
	}
	return *this;
}

Date& Date::operator++(){
	incDay();
	return *this;
}

const Date Date::operator++(int){
	Date temp{*this};
	incDay();
	return temp;
}

ostream& operator<<(ostream& os, const Date& d){
	os << setw(2) << setfill('0') << d.getDay() << '.'
	<< setw(2) << d.getMonth() << '.'
	<< d.getYear() << setfill(' ');
	return os;
}

istream& operator>>(istream& is, Date& d){
	int dd, mm, yy;
	is >> dd;
	is.ignore(1, '.');
	is >> mm;
	is.ignore(1, '.');
	is >> yy;
	d.setDate(dd, mm, yy);
	return is;
}

class DateException {
private:
  	std::ostringstream stream;

public:
	DateException(std::ostringstream &error_stream){
		stream << error_stream.str();
	}
	virtual std::string what() const throw (){
    	return stream.str();
    }
};

void Date::checkDate(){
	std::ostringstream stream;

	if((this->month == 2) && (this->day > 29)){
		stream << "Invalid day : " << this->day << endl;
	}

	if( (this->day < 1 || (this->day > this->daysPerMonth[this->month - 1])) && (this->month != 2) ){
		stream << "Invalid day : " << this->day << endl;
	}

	if( this->month < 1 || this->month > 12 ){
		stream << "Invalid month : " << this->month << endl;
	} 

	if((this->day == 29 && this->month == 2 && !isLeapYear(this->year))){
		stream << "No leap year : " << this->year << endl;
	}

	if( this->year < 1 ){
		stream << "Invalid year : " << this->year << endl;
	}

	if(stream.str().length()){
		throw DateException(stream);
	}

}


int main(){
	int dd, mm, yy;
	cout << "Enter day, month, and year: ";
	cin >> dd >> mm >> yy;
  	try{
		Date d(dd, mm, yy);
		cout << "No error in constructing date : " << d << endl;
	} catch (DateException& e){
		cout << "Error in creating/setting date" << endl;
		cout << e.what() << endl;
	}

	try{
		Date d;
		d.setDate(dd, mm, yy);
		cout << "No error in setting date : " << d << endl;
	} catch (DateException& e){
		cout << "Error in creating/setting date" << endl;
		cout << e.what() << endl;
	}
}
