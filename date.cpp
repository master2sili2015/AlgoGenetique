#include "date.h"

bool Date::check_day(const int y, const int m, const int d)
{
  if (d > 31 || d < 1) return false;
  if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
  if (m == 2 && (y % 4) != 0 && d > 28) return false;
  if (m == 2 && (y % 4) == 0 && d > 29) return false;
  return true;
}

bool Date::check_date(string date)
{
  if (Date::trim_left(date) == "") return false;
  if (date[0] < '0' || date[0] > '9') return false;
  for(unsigned int i = 1; i < date.size(); ++i)
  {
    if ((date[i] < '0' || date[i] > '9') && date[i] != ' ' && date[i] != ':') return false;
  }
  date += ":";
  string::size_type found = date.find(':');
  int val = 0, nbr, l_month, l_year;
  while(found != string::npos)
  {
    nbr = std::stoi(date.substr(0, found));
    switch(val)
    {
      case 0:	  
	if (nbr > 9999 || nbr < 1900) return false;
	l_year = nbr;
      break;
      case 1:
	if (nbr > 12 || nbr < 1) return false;
	l_month = nbr;
      break;
      case 2:
	if (!Date::check_day(l_year, l_month, nbr)) return false;
      break;
      case 3:
	if (nbr > 23 || nbr < 0) return false;
      break;
      case 4:
	if (nbr > 59 || nbr < 0) return false;
      break;
      case 5:
	if (nbr > 59 || nbr < 0) return false;
      break;
    }
    date = date.substr(found + 1);
    date = trim_left(date);
    found = date.find(':');
    val++;
  }
  return true;
}

string Date::trim_left(const string str)
{
  string new_str = "";
  string::size_type found = str.find_first_not_of(" ");
  if (found != string::npos)
  {
      new_str = str.substr(found, str.size());
  }
  return new_str;
}

Date::Date(unsigned int y, unsigned int m, unsigned int d, unsigned int h, unsigned int min, unsigned int s):
year(y), month(m), day(d), hours(h), minute(min), second(s)
{
}

void Date::initDate()
{
  year = 2015;
  month = 1;
  day = 1;
  hours = 0;
  minute = 0;
  second = 0;
}

Date::Date(string date)
{
  this->initDate();
  if (Date::check_date(date))
  {
    date = Date::trim_left(date);
    date += ":";
    string::size_type found = date.find(':');
    int val = 0;
    while(found != string::npos)
    {
      switch(val)
      {
	case 0:
	  year = std::stoi(date.substr(0, found));
	break;
	case 1:
	  month = std::stoi(date.substr(0, found));
	break;
	case 2:
	  day = std::stoi(date.substr(0, found));
	break;
	case 3:
	  hours = std::stoi(date.substr(0, found));
	break;
	case 4:
	  minute = std::stoi(date.substr(0, found));
	break;
	case 5:
	  second = std::stoi(date.substr(0, found));
	break;
      }
      date = date.substr(found + 1);
      date = trim_left(date);
      found = date.find(':');
      val++;
    }
  }
}

Date::Date(const Date& other)
{
  year = other.year;
  month = other.month;
  day = other.day;
  hours = other.hours;
  minute = other.minute;
  second = other.second;
}

Date::~Date()
{

}

Date& Date::operator=(const Date& other)
{
  this->year = other.year;
  this->month = other.month;
  this->day = other.day;
  this->hours = other.hours;
  this->minute = other.minute;
  this->second = other.second;
  
  return *this;
}

bool Date::operator==(const Date& other)
{
  if (this->year == other.year && this->month == other.month && 
    this->day == other.day && this->hours == other.hours &&
    this->minute == other.minute && this->second == this->second)
    return true;
  return false;
}

bool Date::operator<(Date const &d2) 
{
  if (this->getYear() < d2.getYear()) return true;
  if (this->getYear() == d2.getYear() && this->getMonth() < d2.getMonth()) return true;
  if (this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() < d2.getDay()) return true;
  if (this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() == d2.getDay() &&
    this->getHours() < d2.getHours()) return true;
  if (this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() == d2.getDay() &&
    this->getHours() == d2.getHours() && this->getMinute() < d2.getMinute()) return true;
  if (this->getYear() == d2.getYear() && this->getMonth() == d2.getMonth() && this->getDay() == d2.getDay() &&
    this->getHours() == d2.getHours() && this->getMinute() == d2.getMinute() && this->getSecond() < d2.getSecond()) return true;
  return false;
}

bool Date::operator<=(Date const &d2) 
{
  if (*this == d2) return true;
  else return *this < d2;
}

Date Date::add_year(unsigned int y)
{
  Date d = *this;
  unsigned int l_year = this->year + y;
  if (l_year <= 9999) d.year = l_year;
  else d.year = 9999;
  
  return d;
}

Date Date::add_month(unsigned int m)
{
  unsigned int l_month = m;
  unsigned int tmp_month = this->month;
  unsigned int l_year = 0;
  while (l_month > 0)
  {
    if ((12 - tmp_month) < l_month)
    {
      l_month -= (12 - tmp_month) + 1;
      l_year++;
      tmp_month = 1;
    }else {
      tmp_month += l_month;
      l_month = 0;      
    }
  }
  
  Date d = *this;
  if (l_year > 0) d = this->add_year(l_year);
  d.month = tmp_month;
  return d;
}

Date Date::add_day(unsigned int d)
{
  unsigned int l_month = this->month;
  unsigned int l_year = this->year;
  unsigned int tmp_day = this->day;
  unsigned int l_nbMonth = 0;
  unsigned int l_day = d;
  while(l_day > 0)
  {
    int soustract = 0;
    if (l_month == 4 || l_month == 6 || l_month == 9 || l_month == 11) soustract = 1;
    if (l_month == 2 && (l_year % 4) != 0) soustract = 2;
    if (l_month == 2 && (l_year % 4) == 0) soustract = 3;
    switch(soustract)
    {
      case 0:
	if ((31 - tmp_day) < l_day)
	{
	  l_day -= (31 - tmp_day) + 1;
	  l_month++;
	  tmp_day = 1;
	  l_nbMonth++;
	}else
	{
	  tmp_day += l_day;
	  l_day = 0;
	}
      break;
      case 1:
	if ((30 - tmp_day) < l_day)
	{
	  l_day -= (30 - tmp_day) + 1;
	  l_month++;
	  tmp_day = 1;
	  l_nbMonth++;
	}else
	{
	  tmp_day += l_day;
	  l_day = 0;
	}
      break;
      case 2:
	if ((28 - tmp_day) < l_day)
	{
	  l_day -= (28 - tmp_day) + 1;
	  l_month++;
	  tmp_day = 1;
	  l_nbMonth++;
	}else
	{
	  tmp_day += l_day;
	  l_day = 0;
	}
      break;
      case 3:
	if ((29 - tmp_day) < l_day)
	{
	  l_day -= (29 - tmp_day) + 1;
	  l_month++;
	  tmp_day = 1;
	  l_nbMonth++;
	}else
	{
	  tmp_day += l_day;
	  l_day = 0;
	}
      break;
    }
    
    if (l_month > 12)
    {
      l_month = 1;
      l_year++;
    }
  }
  Date date = *this;  
  if (l_nbMonth > 0) date = this->add_month(l_nbMonth);
  date.day = tmp_day; 
  return date;
}

Date Date::add_hours(unsigned int h)
{  
  unsigned int l_hours = (this->hours + h) % 24;
  Date d = *this;
  if (((this->hours + h) / 24) > 0) d = this->add_day((this->hours + h) / 24);
  d.hours = l_hours;
  return d;
}

Date Date::add_minute(unsigned int m)
{
  Date d = *this;
  unsigned int l_minute = (this->minute + m) % 60;  
  if (((this->minute + m) / 60) > 0) d = this->add_hours((this->minute + m) / 60);
  d.minute = l_minute;
  return d;
}

string Date::toString()
{
  string str;
  str = date();
  if (hours != 0 || minute != 0 || second != 0)
    str += ":" + std::to_string(hours) + ":" + std::to_string(minute) + ":" + std::to_string(second);
  return str;
}

string Date::date()
{
  string str;
  str = std::to_string(year) + ":" + std::to_string(month) + ":" + std::to_string(day);
  return str;
}