// Date.CPP - Date class implementation

#include "Date.h"

#include <string>
#include <iostream>

const std::string Date::months[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const int Date::dayLimit[12] = {
    31,29,31,30,31,30,31,31,30,31,30,31
};

Date::Date()
{
  day = 1;
  month = 1;
  year = 1970;
}

Date::Date( int days, int mont, int yea )
{
  SetYear(yea);
  SetMonth(mont);
  SetDay(days);
}

int Date::GetDay() const{
    return day;
}

void Date::SetDay( int days ){
    if(days<=0) days=1;
    if(days>=dayLimit[month]){
        days=dayLimit[month];
        if(days==29&&year%4!=0)
            days=28;
    }
    day = days;
}

int Date::GetMonth() const{
    return month;
}

void Date::SetMonth( int mont ){
    if (mont > 12)mont = 12;
    if (mont < 1)mont = 1;
    month = mont;
}

int Date::GetYear() const{
    return year;
}

void Date::SetYear( int yea ){
    if(yea<0)yea=0;
    year = yea;
}

Date& Date::operator=(const Date& other){
    day = other.day;
    month = other.month;
    year = other.year;
    return *this;
}

std::istream & operator >>( std::istream & input, Date & C )
{
    unsigned year, day, month;
    std::string ystring, dstring, mstring;
    std::getline(input, dstring, '/');
    std::getline(input, mstring, '/');
    std::getline(input, ystring, ' ');
    C.SetYear(std::stoi(ystring));
    C.SetMonth(std::stoi(mstring));
    C.SetDay(std::stoi(dstring));
    return input;
}

std::ostream & operator <<( std::ostream & os, const Date & C )
{
  os  << C.months[C.GetMonth()] << " " << C.GetYear();
  return os;
}
