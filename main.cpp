#include <cassert>
#include <iostream>
#include <sstream>

#include "timespan.h"

using namespace std;

// Testing constructor.
void test1() {
  TimeSpan ts(1, 20, 30);
  stringstream ss;
  ss << ts;
  assert(ss.str() == "1:20:30");

  TimeSpan ts2(4, -20, -90);
  ss.str("");
  ss << ts2;
  assert(ss.str() == "3:38:30");

  TimeSpan ts3(1.5, 30.5, -90);
  ss.str("");
  ss << ts3;
  assert(ss.str() == "1:59:00");

  TimeSpan ts4(0, 0.07, 0);
  ss.str("");
  ss << ts4;
  assert(ss.str() == "0:00:04");
  cout << "test1 complete" << endl;
}

// Testing equality, addition, subtraction, multiplication.
void test2() {
  TimeSpan ts(1, 20, 30);
  TimeSpan ts2(1, 20, 30);
  TimeSpan ts3(0, 0, 0);
  assert(ts == ts2);
  assert(!(ts != ts2));
  assert(ts != ts3);
  assert((ts + ts + ts) == (ts2 * 3));
  assert((ts * 5) == (ts2 * 4) + ts2);
  assert((ts * 5) == (ts2 * 6) - ts2);
  assert((ts + ts - ts) == ((ts2 * 2) - ts));
  assert((ts - ts2) == ts3);
  assert((ts3 * 5) == ts3);
  cout << "test2 complete" << endl;
}

// Testing isPositive method and negative cout display.
void test3() {
  TimeSpan ts0(0, 0, 0);
  TimeSpan ts1(0, 0, 10);
  TimeSpan ts2 = ts0 - ts1;
  assert(ts1.isPositive() && !ts2.isPositive());
  stringstream ss;
  ss << ts2;
  assert(ss.str() == "-0:00:10");
  cout << "test3 complete" << endl;
}

// Testing += and -= overloaded assignment operators.
void test4() {
  TimeSpan ts1(1, 20, 30);
  TimeSpan ts2(1, 20, 30);
  TimeSpan ts3(0, 0, 0);
  ts3 += ts2;
  assert(ts3 == ts1);
  ts3 -= ts2;
  assert(ts3 != ts1);
  cout << "test4 complete" << endl;
}

// Testing <, >, <=, and >= overloaded operators.
void test5() {
  TimeSpan ts1(1, 20, 30);
  TimeSpan ts2(1, 10, 20);
  TimeSpan ts3(1, 19, 90); // When formatted, ts3 == 01:20:30
  assert(ts2 < ts1);
  assert(ts1 > ts2);
  assert(ts2 <= ts1);
  assert(ts1 >= ts2);
  assert(ts1 <= ts3);
  assert(ts1 >= ts3);
  cout << "test5 complete" << endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  cout << "Done." << std::endl;
  return 0;
}