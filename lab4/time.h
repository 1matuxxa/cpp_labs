#ifndef TIME_H
#include <iostream>
#define TIME_H

class Time {
 public:
  Time();
  Time(short int hours, short int minutes);
  Time(const Time& other);

  Time operator-(const Time& other) const;

  friend std::ostream& operator<<(std::ostream& out, const Time& t);
  friend std::istream& operator>>(std::istream& in, Time& t);

  Time& operator--();
  Time operator--(int);

  explicit operator short int() const;
  operator bool() const;

  Time operator+(unsigned int minutes) const;
  Time operator+(const Time& other) const;

 private:
  short int hours_;
  short int minutes_;

  void Normalize();
};
#endif // TIME_H