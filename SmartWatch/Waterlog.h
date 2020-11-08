#ifndef WATERLOG_H
#define WATERLOG_H
#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"
#include"Time.h"

class WaterLog
{
	float quantity;
	Date waterDate;
	Time waterTime;
public:
	WaterLog(float = 0.5);
	WaterLog(float, Date, Time);
	void setQuanitity(float q);
	void setWaterDate(Date d);
	void setwaterTime(Time t);
	float getQuantity()const;
	Date getWaterDate()const;
	Time getWaterTime()const;
};

#endif // !WATERLOG_H
