#ifndef WATERLOGLIST_H
#define WATERLOGLIST_H
#define _CRT_SECURE_NO_WARNINGS
enum WaterUnits { MILLI_LITRE, LITRE };
#include"Waterlog.h"
class WaterLogList
{
	WaterLog** watLogActivity;
	WaterUnits defaultWaterUnit = MILLI_LITRE;
	int waterLogCount;
	int waterLogCapacity;
	void reSize();
public:
	WaterLogList();
	~WaterLogList();
	void logWater(float);
	void logWater(float, Date, Time);
	WaterUnits getDefaultWaterUnit()const;
	void changeDefaultWaterUnit(WaterUnits);
	float totalWaterIntakeToday()const;
	float totalWaterCurrentMonth()const;
	float totalWaterIntakeInLastNMonth(int)const;
	void printMonthWiseHistogram(int)const;
	void printDayWiseHistogramLastNDays(int)const;
};

#endif // !WATERLOGLIST_H
