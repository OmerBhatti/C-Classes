#include<iostream>
#include"CString.h"
#include"Date.h"
#include<iomanip>
using namespace std;

const int Date::daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const CString Date::monthsName[] = { " ","January","February","March","April","May","June","July",
										"August","September","October", "November","December" };

Date::Date()
{
	day = 1;
	month = 1;
	year = 1600;
}

bool Date::isLeapYear(int y) const
{
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		return true;
	else
		return false;
}
Date::Date(int d, int m, int y)
{
	month = (m >= 1 && m <= 12) ? m : 1;
	year = (y >= 1600 && y <= 2100) ? y : 1600;
	//handling february (leap or not) i.e 28-29 days
	if (month == 2 && isLeapYear(year))
		day = (d >= 1 && d <= 29) ? d : 1;
	else
		day = (d >= 1 && d <= daysInMonth[month]) ? d : 1;
}

void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
void Date::setDay(int d)
{
	if (month == 2 && isLeapYear(year))
		day = (d >= 1 && d <= 29) ? d : 1;
	else
		day = (d >= 1 && d <= daysInMonth[month]) ? d : 1;
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		month = 1;
	}
}
void Date::setYear(int y)
{
	if (y >= 1600 && y <= 2100)
	{
		year = y;
	}
	else
	{
		year = 1600;
	}
}

int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
int Date::getDaysInMonth()const
{
	if (month == 2 && isLeapYear(year))
	{
		return 29;
	}
	else
	{
		return daysInMonth[month];
	}
}
void Date::incDay(int inc)
{
	for (int i = 0; i < inc; i++)
	{
		if (day != getDaysInMonth())
		{
			day = day + 1;
		}
		else
		{
			if (month < 12)
			{
				month = month + 1;
				day = 1;
			}
			else
			{
				year = year + 1;
				month = 1;
				day = 1;
			}
		}
	}
}
void Date::incMonth(int inc)
{
	for (int i = 0; i < inc; i++)
	{
		if (month < 12)
		{
			month = month + 1;
		}
		else
		{
			year = year + 1;
			month = 1;
		}
	}
}
void Date::incYear(int inc)
{
	if (year + inc <= 2100)
	{
		year = year + inc;
	}
}

bool Date::compareDate(const Date& d)const
{
	if (day == d.day && month == d.month && year == d.year)
	{
		return true;
	}
	return false;
}
void Date::printFormat1()const
{
	cout.fill('0');
	cout << setw(2) << month << "/" << setw(2) << day << "/" << year << "\n";
}
void Date::printFormat2()const
{
	cout.fill('0');
	monthsName[month].display();
	cout << "," << setw(2) << day << " " << year << "\n";
}
void Date::printFormat3()const
{
	cout.fill('0');
	cout << setw(2) << day << "-";
	monthsName[month].display();
	cout << "-" << year << "\n";
}
void Date::decYear(int dec)
{
	if (year - dec >= 1600)
	{
		year = year - dec;
	}
}

void Date::decMonth(int dec)
{
	for (int i = 0; i < dec; i++)
	{
		if (month > 1)
		{
			month = month - 1;
		}
		else
		{
			year = year - 1;
			month = 12;
		}
	}
}

void Date::decDay(int dec)
{
	for (int i = 0; i < dec; i++)
	{
		if (day != 1)
		{
			day = day - 1;
		}
		else
		{
			if (month > 1)
			{
				month = month - 1;
				day = daysInMonth[month];
			}
			else
			{
				year = year - 1;
				month = 12;
				day = daysInMonth[month];
			}
		}
	}
}