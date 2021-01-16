//
// Created by Yusuf Pisan on 4/2/18.
//

#include "timespan.h"
#include <iomanip>

ostream &operator<<(ostream &out, const TimeSpan &ts) {
  out << ts.hour << ":" << 
  setw(2) << setfill('0') << ts.minute << ":" << 
  setw(2) << setfill('0') << ts.second;
  return out; 
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  this->hour = 0;
  this->minute = 0;
  this->second = 0;

  double tempSec = ((hour * 60) + minute) * 60 + second;
  double mins = tempSec / 60;
  this->second = (int)tempSec % 60;
  this->minute += (int)mins;
  this->hour = this->minute / 60;
  this->minute %= 60;
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
