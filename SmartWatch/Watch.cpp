#include"Date.h"
#include"Time.h"
#include"Watch.h"

Watch::Watch() :watchDate(Date()), watchTime(Time())
{

}
Watch::Watch(Date d, Time t) : watchDate(d), watchTime(t)
{

}
Watch::Watch(const Watch& ref)
{
	watchDate = ref.watchDate;
	watchTime = ref.watchTime;
}

void Watch::setTime(Time t)
{
	watchTime = t;
}
void Watch::setDate(Date d)
{
	watchDate = d;
}
void Watch::setMinute(int m)
{
	watchTime.setMinute(m);
}
void Watch::setHour(int h)
{
	watchTime.setHour(h);
}
void Watch::setSecond(int s)
{
	watchTime.setSecond(s);
}
void Watch::setTime(int h, int m, int s)
{
	watchTime.setTime(h, m, s);
}

void Watch::setMonth(int m)
{
	watchDate.setMonth(m);
}
void Watch::setDay(int d)
{
	watchDate.setDate(d);
}
void Watch::setYear(int y)
{
	watchDate.setYear(y);
}

Time Watch::getTime()const
{
	return watchTime;
}
Date Watch::getDate()const
{
	return watchDate;
}
int Watch::getMinute()const
{
	return watchTime.getMinute();
}
int Watch::getHour()const
{
	return watchTime.getHour();
}
int Watch::getSecond()const
{
	return watchTime.getSecond();
}
int Watch::getMonth()const
{
	return watchDate.getMonth();
}
int Watch::getDay()const
{
	return watchDate.getDay;
}
int Watch::getYear()const
{
	return watchDate, getYear();
}

void Watch::printTwentyFourHourFormat()const
{
	watchTime.printTwentyFourHourFormat();
}
void Watch::printtwelveHourFormat()const
{
	watchTime.printTwelveHourFormat();
}
void Watch::printFormat1Date()const
{
	watchDate.printFormat1();
}
void Watch::printFormat2Date()const
{
	watchDate.printFormat2();
}
void Watch::printFormat3Date()const
{
	watchDate.printFormat3();
}
void Watch::incSec(int inc)
{
	watchTime.incSec(inc);
}
void Watch::incMin(int inc)
{
	watchTime.incMin(inc);
}
void Watch::incHour(int inc)
{
	watchTime.incHour(inc);
}
void Watch::decSec(int dec)
{
	watchTime.decSec(dec);
}
void Watch::decMin(int dec)
{
	watchTime.decMin(dec);
}
void Watch::decHour(int dec)
{
	watchTime.decHour(h);
}
void Watch::incDay(int inc)
{
	watchDate.incDay(inc);
}
void Watch::incMonth(int inc)
{
	watchDate.incMonth(inc);
}
void Watch::incYear(int inc)
{
	watchDate.incYear(inc);
}
void Watch::decDay(int dec)
{
	watchDate.decDay(dec);
}
void Watch::decMonth(int dec)
{
	watchDate.decMonth(dec);
}
void Watch::decYear(int dec)
{
	watchDate.decYear(dec);
}
