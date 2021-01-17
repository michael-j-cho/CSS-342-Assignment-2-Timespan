//
// Created by Yusuf Pisan on 4/2/18.
//

#include "timespan.h"
#include <cmath>
#include <iomanip>

#define errCheck1 1

ostream &operator<<(ostream &out, const TimeSpan &ts) {
  if (ts.isPositive()) {
    out << ts.getHour() << ":" << setw(2) << setfill('0') << ts.getMinute()
        << ":" << setw(2) << setfill('0') << ts.getSecond();
  } else {
    out << "-" << abs(ts.getHour()) << ":" << setw(2) << setfill('0')
        << abs(ts.getMinute()) << ":" << setw(2) << setfill('0')
        << abs(ts.getSecond());
  }
  return out;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  this->hour = 0;
  this->minute = 0;
  this->second = 0;

  double tempSec = convertToSeconds(hour, minute, second);
  double mins = tempSec / 60;
  this->second = (int)tempSec % 60;
  this->minute += (int)mins;
  this->hour = this->minute / 60;
  this->minute %= 60;
}

int TimeSpan::convertToSeconds(double hour, double minute,
                               double second) const {
  double allSeconds = ((hour * 60) + minute) * 60 + second;
  return (int)allSeconds;
}

TimeSpan TimeSpan::formatTime() {
  double tempSec = convertToSeconds(this->hour, this->minute, this->second);
  double mins = tempSec / 60;
  this->second = (int)tempSec % 60;
  this->minute += (int)mins;
  this->hour = this->minute / 60;
  this->minute %= 60;
  return *this;
}

// hour component
int TimeSpan::getHour() const { return this->hour; }

// minute component
int TimeSpan::getMinute() const { return this->minute; }

// second component
int TimeSpan::getSecond() const { return this->second; }

// true if timespan is 0 or larger
bool TimeSpan::isPositive() const {
  if (convertToSeconds(this->hour, this->minute, this->second) < 0) {
    return false;
  }
  return true;
}

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  int seconds = convertToSeconds(ts.hour, ts.minute, ts.second) +
                convertToSeconds(this->hour, this->minute, this->second);
  TimeSpan tsSum(0, 0, 0);
  tsSum.second = seconds;
  tsSum.formatTime();
  return tsSum;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  int seconds = convertToSeconds(this->hour, this->minute, this->second) -
                convertToSeconds(ts.hour, ts.minute, ts.second);
  TimeSpan tsSub(0, 0, 0);
  tsSub.second = seconds;
  tsSub.formatTime();
  return tsSub;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  int seconds =
      number * convertToSeconds(this->hour, this->minute, this->second);
  TimeSpan tsLarge(0, 0, 0);
  tsLarge.second = seconds;
  tsLarge.formatTime();
  return tsLarge;
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const {
  if (ts.getHour() == getHour() && ts.getMinute() == getMinute() &&
      ts.getSecond() == getSecond()) {
    return true;
  }
  return false;
}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  if (ts.getHour() != getHour() || ts.getMinute() != getMinute() ||
      ts.getSecond() != getSecond()) {
    return true;
  }
  return false;
}

TimeSpan TimeSpan::operator+=(const TimeSpan &ts) {
  int seconds = convertToSeconds(ts.hour, ts.minute, ts.second) +
                convertToSeconds(this->hour, this->minute, this->second);
  this->second = 0;
  this->minute = 0;
  this->hour = 0;
  this->second += seconds;
  this->formatTime();
  return *this;
}

TimeSpan TimeSpan::operator-=(const TimeSpan &ts) {
  int seconds = convertToSeconds(this->hour, this->minute, this->second) -
                convertToSeconds(ts.hour, ts.minute, ts.second);
  this->second = 0;
  this->minute = 0;
  this->hour = 0;
  this->second += seconds;
  this->formatTime();
  return *this;
}

bool TimeSpan::operator<(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) <
      convertToSeconds(ts.hour, ts.minute, ts.second)) {
    return true;
  }
  return false;
}

bool TimeSpan::operator>(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) >
      convertToSeconds(ts.hour, ts.minute, ts.second)) {
    return true;
  }
  return false;
}

bool TimeSpan::operator<=(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) <
          convertToSeconds(ts.hour, ts.minute, ts.second) ||
      (convertToSeconds(this->hour, this->minute, this->second) ==
       convertToSeconds(ts.hour, ts.minute, ts.second))) {
    return true;
  }
  return false;
}

bool TimeSpan::operator>=(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) >
          convertToSeconds(ts.hour, ts.minute, ts.second) ||
      (convertToSeconds(this->hour, this->minute, this->second) ==
       convertToSeconds(ts.hour, ts.minute, ts.second))) {
    return true;
  }
  return false;
}