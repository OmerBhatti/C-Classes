#include"Date.h"
#include"Time.h"
#include"Waterlog.h"
#include<ctime>

WaterLog::WaterLog(float q):quantity(q)
{
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	waterDate = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);
	waterTime = Time(cur.tm_hour, cur.tm_min, cur.tm_sec);
}
WaterLog::WaterLog(float q, Date d, Time t):quantity(q),waterDate(d),waterTime(t)
{ 

}
void WaterLog::setQuanitity(float q)
{
	if (q > 0)
	{
		quantity = q;
	}
}
void WaterLog::setWaterDate(Date d)
{
	waterDate = d;
}
void WaterLog::setwaterTime(Time t)
{
	waterTime = t;
}
float WaterLog::getQuantity()const
{
	return quantity;
}
Date WaterLog::getWaterDate()const
{
	return waterDate;
}
Time WaterLog::getWaterTime()const
{
	return waterTime;
}