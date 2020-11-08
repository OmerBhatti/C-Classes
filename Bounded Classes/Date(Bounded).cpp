#include<iostream>
#include"CString.h"
#include"Date.h"
#include"BoundedInteger.h"
#include<iomanip>
using namespace std;


const int Date::daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const CString Date::monthsName[] = { " ","January","February","March","April","May","June","July",
										"August","September","October", "November","December" };

Date::Date() :day(0, 31), month(0, 12), year(1600, 2100)
{
	day.setValue(1);
	month.setValue(1);
	year.setValue(1600);
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
	month.setValue((m >= 1 && m <= 12) ? m : 1);
	year.setValue((y >= 1600 && y <= 2100) ? y : 1600);
	//handling february (leap or not) i.e 28-29 days
	if (month.getValue() == 2 && isLeapYear(year.getValue()))
		day.setValue((d >= 1 && d <= 29) ? d : 1);
	else
		day.setValue((d >= 1 && d <= daysInMonth[month.getValue()]) ? d : 1);
}

void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
void Date::setDay(int d)
{
	if (month.getValue() == 2 && isLeapYear(year.getValue()))
		day.setValue((d >= 1 && d <= 29) ? d : 1);
	else
		day.setValue((d >= 1 && d <= daysInMonth[month.getValue()]) ? d : 1);
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month.setValue(m);
	}
	else
	{
		month.setValue(1);
	}
}
void Date::setYear(int y)
{
	if (y >= 1600 && y <= 2100)
	{
		year.setValue(y);
	}
	else
	{
		year.setValue(1600);
	}
}

int Date::getDay()const
{
	return day.getValue();
}
int Date::getMonth()const
{
	return month.getValue();
}
int Date::getYear()const
{
	return year.getValue();
}
int Date::getDaysInMonth()const
{
	if (month.getValue() == 2 && isLeapYear(year.getValue()))
	{
		return 29;
	}
	else
	{
		return daysInMonth[month.getValue()];
	}
}
void Date::incDay(int inc)
{
	for (int i = 0; i < inc; i++)
	{
		if (day.getValue() != getDaysInMonth())
		{
			day.setValue(day.getValue() + 1);
		}
		else
		{
			if (month.getValue() < 12)
			{
				month.setValue(month.getValue() + 1);
				day.setValue(1);
			}
			else
			{
				year.setValue(year.getValue() + 1);
				month.setValue(1);
				day.setValue(1);
			}
		}
	}
}
void Date::incMonth(int inc)
{
	for (int i = 0; i < inc; i++)
	{
		if (month.getValue() < 12)
		{
			month.setValue(month.getValue() + 1);
		}
		else
		{
			year.setValue(year.getValue() + 1);
			month.setValue(1);
		}
	}
}
void Date::incYear(int inc)
{
	if (year.getValue() + inc <= 2100)
	{
		year.setValue(year.getValue() + inc);
	}
}

bool Date::compareDate(const Date& d)const
{
	if (day.getValue() == d.day.getValue() && month.getValue() == d.month.getValue() && year.getValue() == d.year.getValue())
	{
		return true;
	}
	return false;
}
void Date::printFormat1()const
{
	cout.fill('0');
	cout << setw(2) << month.getValue() << "/" << setw(2) << day.getValue() << "/" << year.getValue() << "\n";
}
void Date::printFormat2()const
{
	cout.fill('0');
	monthsName[month.getValue()].display();
	cout << "," << setw(2) << day.getValue() << " " << year.getValue() << "\n";
}
void Date::printFormat3()const
{
	cout.fill('0');
	cout << setw(2) << day.getValue() << " ";
	monthsName[month.getValue()].display();
	cout << " " << year.getValue() << "\n";
}
void Date::decYear(int dec)
{
	if (year.getValue() - dec >= 1600)
	{
		year.setValue(year.getValue() - dec);
	}
}

void Date::decMonth(int dec)
{
	for (int i = 0; i < dec; i++)
	{
		if (month.getValue() > 1)
		{
			month.setValue(month.getValue() - 1);
		}
		else
		{
			year.setValue(year.getValue() - 1);
			month.setValue(12);
		}
	}
}

void Date::decDay(int dec)
{
	for (int i = 0; i < dec; i++)
	{
		if (day.getValue() != 1)
		{
			day.setValue(day.getValue() - 1);
		}
		else
		{
			if (month.getValue() > 1)
			{
				month.setValue(month.getValue() - 1);
				day.setValue(daysInMonth[month.getValue()]);
			}
			else
			{
				year.setValue(year.getValue() - 1);
				month.setValue(12);
				day.setValue(daysInMonth[month.getValue()]);
			}
		}
	}
}