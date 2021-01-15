//
// Created by Yusuf Pisan on 4/2/18.
//

#include "timespan.h"

ostream &operator<<(ostream &out, const TimeSpan &ts) {

  if(ts.minute <= 10) {
    out << ts.hour << ":0" << ts.minute << ":" << ts.second << endl;
    return out; 
  } else {
    out << ts.hour << ":" << ts.minute << ":" << ts.second << endl;
    return out;
  }
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  this->hour = (int)hour;
  this->minute = (hour - (int)hour) * 60 + minute;
  this->second = (minute - (int)minute) * 60 + second;

  if (this->second >= 60) {
    int tempMins = this->second / 60;
    this->second %= 60;
    this->minute += tempMins;
  }
  if (this->minute >= 60) {
    int tempHours = this->minute / 60;
    this->minute %= 60;
    this->hour += tempHours;
  }
  this->hour %= 24;
}

// hour component
int TimeSpan::getHour() const { 
  return this->hour; 
  }

// minute component
int TimeSpan::getMinute() const { 
  return this->minute; 
}

// second component
int TimeSpan::getSecond() const { 
  return this->second; 
}

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { return true; }

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  TimeSpan tsSum;
  return tsSum;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  TimeSpan tsSub;
  return tsSub;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  TimeSpan tsLarge;
  return tsLarge;
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const { return true; }

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const { return true; }
