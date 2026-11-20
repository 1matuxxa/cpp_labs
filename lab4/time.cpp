#include "time.h"

void Time::Normalize() {
    while (minutes_ < 0) {
        hours_ -= 1;
        minutes_ += 60;
    }
    hours_ += minutes_ / 60;
    minutes_ %= 60;

    while (hours_ < 0) {
        hours_ += 24;
    }
    hours_ %= 24;
}

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(short int hours, short int minutes) : hours_(hours), minutes_(minutes) {
    Normalize();
}
Time::Time(const Time& other) : hours_(other.hours_), minutes_(other.minutes_) {}

Time Time::operator-(const Time& other) const {
    Time result(hours_ - other.hours_, minutes_ - other.minutes_);
    result.Normalize();
    return result;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << (t.hours_ < 10 ? "0" : "") << t.hours_ << ":"
        << (t.minutes_ < 10 ? "0" : "") << t.minutes_;
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) {
    while (!(in >> t.hours_ >> t.minutes_)) {
        in.clear();
        in.ignore(10000, '\n');
        std::cout << "Error. Please provide a correct time numbers!\n";
    }
    t.Normalize();
    return in;
}

Time& Time::operator--() {
    minutes_ -= 1;
    Normalize();
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

Time::operator short int() const{
    return hours_;
}

Time::operator bool() const {
    return (hours_ != 0 || minutes_ != 0);
}

Time Time::operator+(unsigned int minutes) const {
    Time result(hours_, minutes_ + minutes);
    result.Normalize();
    return result;
}

Time Time::operator+(const Time& other) const {
    Time result(hours_ + other.hours_, minutes_ + other.minutes_);
    result.Normalize();
    return result;
}

