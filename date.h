#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
  unsigned int year;
  unsigned int month;
  unsigned int day;
  unsigned int hours;
  unsigned int minute;
  unsigned int second;
  
  void initDate();
  Date add_hours(unsigned int h);
  Date add_day(unsigned int d);
  Date add_month(unsigned int m);
  Date add_year(unsigned int y);
public:
  Date(string date);
  Date(unsigned int y = 2015, unsigned int m = 1, unsigned int d = 1, unsigned int h = 0, unsigned int min = 0, unsigned int s = 0);
  Date(const Date& other);
  ~Date();
  Date& operator=(const Date& other);
  bool operator==(const Date& other);
  bool operator<(Date const &d2);
  bool operator<=(Date const &d2);
  
  Date add_minute(unsigned int m);
  
  
  //getter
  unsigned int getYear() const { return this->year; };
  unsigned int getMonth() const { return this->month; };
  unsigned int getDay() const { return this->day; };
  unsigned int getHours() const { return this->hours; };
  unsigned int getMinute() const { return this->minute; };
  unsigned int getSecond() const { return this->second; };
  
  static bool check_date(string date);
  static bool check_day(const int y, const int m, const int d);
  static string trim_left(const string str);
  
  void print();
};

#endif // DATE_H
