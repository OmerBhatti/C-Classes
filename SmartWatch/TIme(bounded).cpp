#include<iostream>
#include"Time.h"
#include"BoundedInteger.h"
#include<iomanip>
using namespace std;

Time::Time(int h, int m, int s) :hour(0, 23), minute(0, 59), second(0, 59)
{
	if (h == 0 && m == 0 && s == 0)
	{
		hour.setValue(0);
		minute.setValue(0);
		second.setValue(0);
		return;
	}
	hour.setValue(h);
	minute.setValue(m);
	second.setValue(s);
}

void Time::setMinute(int m)
{
	minute.setValue(m);
}
void Time::setSecond(int s)
{
	second.setValue(s);
}
void Time::setHour(int h)
{
	hour.setValue(h);
}
void Time::setTime(int h, int m, int s)
{
	hour.setValue(h);
	minute.setValue(m);
	second.setValue(s);
}
int Time::getHour()const
{
	return hour.getValue();
}
int Time::getMinute()const
{
	return minute.getValue();
}
int Time::getSecond()const
{
	return second.getValue();
}
void Time::printTwelveHourFormat()const
{
	cout.fill('0');
	cout << ((hour.getValue() == 0 || hour.getValue() == 12) ? 12 : hour.getValue() % 12) << ":"
		<< setw(2) << minute.getValue() << ":" << setw(2)
		<< second.getValue();
	//printing AM or PM
	if ((hour.getValue() >= 12 && hour.getValue() != 0))
	{
		cout << " PM\n";
	}
	else
	{
		cout << " AM\n";
	}
}
void Time::printTwentyFourHourFormat()const
{
	cout.fill('0');
	cout << setfill('0') << setw(2) << hour.getValue() << ":"
		<< setw(2) << minute.getValue() << ":" << setw(2) << second.getValue() << endl;
}

void Time::incSec(int inc)
{
	int minuteIncrement = inc / 60;
	second.increment(inc);
	incMin(minuteIncrement);
}
void Time::incMin(int inc)
{
	int hourIncrement = inc / 60;
	minute.increment(inc);
	incHour(hourIncrement);
}
void Time::incHour(int inc)
{
	hour.increment(inc);
}

void Time::decSec(int dec)
{
	int minuteDecrement = dec / 60;
	second.decrement(dec);
	decMin(minuteDecrement);
}
void Time::decMin(int dec)
{
	int hourDecrement = dec / 60;
	minute.decrement(dec);
	decHour(hourDecrement);
}
void Time::decHour(int dec)
{
	hour.decrement(dec);
}