#ifndef WATCH_H
#define WATCH_H

#include"Date.h"
#include"Time.h"

class Watch
{
	Date watchDate;
	Time watchTime;
public:
	Watch();
	Watch(Date d, Time t);
	Watch(const Watch&);
	void setTime(Time t);
	void setDate(Date d);
	void setMinute(int m);
	void setHour(int h);
	void setSecond(int s);
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);
	void setTime(int h, int m, int s);
	Time getTime()const;
	Date getDate()const;
	int getMinute()const;
	int getHour()const;
	int getSecond()const;
	int getMonth()const;
	int getDay()const;
	int getYear()const;
	void printTwentyFourHourFormat()const;
	void printtwelveHourFormat()const;
	void printFormat1Date()const;
	void printFormat2Date()const;
	void printFormat3Date()const;
	void incSec(int =1);
	void incMin(int =1);
	void incHour(int =1);
	void decSec(int =1);
	void decMin(int =1);
	void decHour(int =1);
	void incDay(int =1);
	void incMonth(int =1);
	void incYear(int =1);
	void decDay(int =1);
	void decMonth(int =1);
	void decYear(int =1);
};

#endif // !WATCH_H
