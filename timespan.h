//
// Michael Cho 01/06/2021.
//
// TimeSpan Class
//


#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // TimeSpan constructor. Default double values are 0.
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  // Convert hour, minute, and second into total seconds function. 
  int convertToSeconds(double hour = 0, double minute = 0, double second = 0) const;

  // Time formatting function.
  TimeSpan formatTime();

  // Overloaded addition operator.
  TimeSpan operator+(const TimeSpan &ts) const;

  // Overloaded subtraction operator.
  TimeSpan operator-(const TimeSpan &ts) const;

  // Overloaded equality operator.
  bool operator==(const TimeSpan &ts) const;

  // Overloaded not equal operator.
  bool operator!=(const TimeSpan &ts) const;

  // Overloaded multiplication operator.
  TimeSpan operator*(unsigned int number) const;

  // Overloaded addition assignment operator.
  TimeSpan operator+=(const TimeSpan &ts);

  // Overloaded subtraction assignment operator.
  TimeSpan operator-=(const TimeSpan &ts);

  // Overloaded less than boolean operator.
  bool operator<(const TimeSpan &ts) const;

  // Overloaded greater than boolean operator.
  bool operator>(const TimeSpan &ts) const;

  // Overloaded less than OR equal to operator.
  bool operator<=(const TimeSpan &ts) const;

  // Overloaded greater than OR equal to operator.
  bool operator>=(const TimeSpan &ts) const;

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // true if timespan is 0 or larger
  bool isPositive() const;

private:
  // Data members for hour, minute, and second for TimeSpan object.
  int hour;
  int minute;
  int second;
};

#endif // ASS2_TIMESPAN_H
