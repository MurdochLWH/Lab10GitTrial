// Time.CPP - Time class implementation

#include "Time.h"

#include <string>
#include <iostream>

Time::Time()
{
  SetHour(0);
  SetMinute(0);
  SetSecond(0);
}

Time::Time( int hours, int mins, int secs )
{
  SetHour(hours);
  SetMinute(mins);
  SetSecond(secs);
}

int Time::GetHour() const{
    return hour;
}

void Time::SetHour( int hours ){
    if(hours>=24) hours=23;
    if(hours<0) hours=0;
    hour = hours;
}

int Time::GetMinute() const{
    return minute;
}

void Time::SetMinute( int mins ){
    if(mins>=60) mins=59;
    if(mins<0) mins=0;
    minute = mins;
}

int Time::GetSecond() const{
    return sec;
}

void Time::SetSecond( int secs ){
    if(secs>=60) secs=59;
    if(secs<0) secs=0;
    sec = secs;
}

std::istream & operator >>( std::istream & input, Time & C )
{
    std::string hstring, mstring, sstring;
    std::getline(input, hstring, ':');
    std::getline(input, mstring, ',');
    C.SetHour(std::stoi(hstring));
    C.SetMinute(std::stoi(mstring));
    C.SetSecond(0);
    return input;
}

std::ostream & operator <<( std::ostream & os, const Time & C )
{
  os << C.GetHour() << ":" << C.GetMinute() << ":" << C.GetSecond();
  return os;
}
