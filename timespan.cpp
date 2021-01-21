//
// Michael Cho 01/19/2021.
//
// TimeSpan Class
//
//  This TimeSpan class converts given parameters into a formatted time span.
//  This class can add or subtract two time spans together, or multiply a
//  timespan by a number. This class can also compare two time spans that are
//  equal, not equal, less than, greater than, less than or equal to, and
//  greater than or equal to each other. There are also functions that convert
//  the time span into seconds and checks if the time span is positive.
//

#include "timespan.h"
#include <cmath>
#include <iomanip>

// Overloaded << operator. Uses setw to set each integer with two digits.
// If the time is negative, the time displays a "-" in front.
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

// TimeSpan constructor sets hour, minute, and second data member to 0.
// Creates a temp seconds holder and passes in the parameters and converts
// them all to seconds. Then, the constructor distributes the seconds
// into hour, minute and second.
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

// Converts a time input of hours, minutes, and seconds into
// all seconds.
int TimeSpan::convertToSeconds(double hour, double minute,
                               double second) const {
  double allSeconds = ((hour * 60) + minute) * 60 + second;
  return (int)allSeconds;
}

// Similar to the time formatting in the constructor. Converts
// total seconds into hour, minute, and second format.
TimeSpan TimeSpan::formatTime() {
  double tempSec = convertToSeconds(this->hour, this->minute, this->second);
  double mins = tempSec / 60;
  this->second = (int)tempSec % 60;
  this->minute += (int)mins;
  this->hour = this->minute / 60;
  this->minute %= 60;
  return *this;
}

// Hour component, returns hour data member.
int TimeSpan::getHour() const { return this->hour; }

// Minute component, returns minute data member.
int TimeSpan::getMinute() const { return this->minute; }

// Second component, returns second data member.
int TimeSpan::getSecond() const { return this->second; }

// Converts time of TimeSpan object to seconds and determines if
// time is positive or negative.
bool TimeSpan::isPositive() const {
  if (convertToSeconds(this->hour, this->minute, this->second) < 0) {
    return false;
  }
  return true;
}

// Overloaded + operator. Converts this object and ts object into seconds.
// Puts total seconds into empty tsSum object and formats time.
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  int seconds = convertToSeconds(ts.hour, ts.minute, ts.second) +
                convertToSeconds(this->hour, this->minute, this->second);
  TimeSpan tsSum(0, 0, 0);
  tsSum.second = seconds;
  tsSum.formatTime();
  return tsSum;
}

// Overloaded - operator. Converts this object and ts object into seconds.
// Puts total seconds into empty tsSub object and formats time.
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  int seconds = convertToSeconds(this->hour, this->minute, this->second) -
                convertToSeconds(ts.hour, ts.minute, ts.second);
  TimeSpan tsSub(0, 0, 0);
  tsSub.second = seconds;
  tsSub.formatTime();
  return tsSub;
}

// Overloaded * operator. Multiplies total seconds of this object with
// desired number. Puts total seconds into tsLarge object and formats time.
TimeSpan TimeSpan::operator*(unsigned int number) const {
  int seconds =
      number * convertToSeconds(this->hour, this->minute, this->second);
  TimeSpan tsLarge(0, 0, 0);
  tsLarge.second = seconds;
  tsLarge.formatTime();
  return tsLarge;
}

// Overloaded == operator. Boolean that compares hour, minute, and second.
// Returns true if all are equal and false if any are not equal. All data
// members must be equal
bool TimeSpan::operator==(const TimeSpan &ts) const {
  if (ts.getHour() == getHour() && ts.getMinute() == getMinute() &&
      ts.getSecond() == getSecond()) {
    return true;
  }
  return false;
}

// Overloaded != operator. Boolean that compares hour, minute, and second.
// Returns true is any two comparing data members are not equal.
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  if (ts.getHour() != getHour() || ts.getMinute() != getMinute() ||
      ts.getSecond() != getSecond()) {
    return true;
  }
  return false;
}

// Overloaded += operator. Converts both to seconds and adds the seconds
// together. Assigns the seconds into this object (left of +=), formats time,
// then returns *this object.
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

// Overloaded -= operator. Converts both to seconds and subtracts right side of
// assignment from the left side of -=. Then, formats time and returns *this
// object.
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

// Overloaded < operator. Converts both objects into seconds. Returns true if
// this object is less than ts object. Otherwise, returns false.
bool TimeSpan::operator<(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) <
      convertToSeconds(ts.hour, ts.minute, ts.second)) {
    return true;
  }
  return false;
}

// Overloaded > operator. Converts both objects into seconds. Returns true if
// this object is greater than ts object. Otherwise, returns false.
bool TimeSpan::operator>(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) >
      convertToSeconds(ts.hour, ts.minute, ts.second)) {
    return true;
  }
  return false;
}

// Overloaded <= operator. Converts both objects into seconds. Returns true if
// this object is less than ts object OR objects are equal. Otherwise, returns
// false.
bool TimeSpan::operator<=(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) <
          convertToSeconds(ts.hour, ts.minute, ts.second) ||
      (convertToSeconds(this->hour, this->minute, this->second) ==
       convertToSeconds(ts.hour, ts.minute, ts.second))) {
    return true;
  }
  return false;
}

// Overloaded >= operator. Converts both objects into seconds. Returns true if
// this object is greater than ts object OR objects are equal. Otherwise,
// returns false.
bool TimeSpan::operator>=(const TimeSpan &ts) const {
  if (convertToSeconds(this->hour, this->minute, this->second) >
          convertToSeconds(ts.hour, ts.minute, ts.second) ||
      (convertToSeconds(this->hour, this->minute, this->second) ==
       convertToSeconds(ts.hour, ts.minute, ts.second))) {
    return true;
  }
  return false;
}