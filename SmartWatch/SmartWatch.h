#ifndef SMARTWATCH_H
#define SMARTWATCH_H

#include"WaterLogList.h"
#include"Watch.h"

class SmartWatch
{
	Watch wch;
	WaterLogList wLogList;
public:
	SmartWatch();
	SmartWatch(Date, Time);
	void setWatch(Watch);
	Watch& getWatch();
	WaterLogList& getWaterLogList();
};

#endif // !SMARTWATCH_H
