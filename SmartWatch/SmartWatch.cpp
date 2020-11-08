#include"SmartWatch.h"
#include"WaterLogList.h"
#include"Watch.h"

SmartWatch::SmartWatch() :wch(Date(), Time())
{
}
SmartWatch::SmartWatch(Date d, Time t) :wch(d, t)
{
}
void SmartWatch::setWatch(Watch s)
{
	wch = s;
}
Watch& SmartWatch::getWatch()
{
	return wch;
}
WaterLogList& SmartWatch::getWaterLogList()
{
	return wLogList;
}