#ifndef TIME_H
#define TIME_H
#include"BoundedInteger.h"

class Time
{
	BoundedInteger hour;
	BoundedInteger minute;
	BoundedInteger second;
public:
	Time(int = 0, int = 0, int = 0);
	void setMinute(int m);
	void setSecond(int s);
	void setHour(int h);
	void setTime(int h, int m, int s);
	int getHour()const;
	int getMinute()const;
	int getSecond()const;
	void printTwelveHourFormat()const;
	void printTwentyFourHourFormat()const;
	void incSec(int inc=1);
	void incMin(int inc = 1);
	void incHour(int inc = 1);
	void decSec(int dec = 1);
	void decMin(int dec = 1);
	void decHour(int dec = 1);
};


#endif // !TIME_H
