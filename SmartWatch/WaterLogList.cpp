#include"Waterlog.h"
#include"WaterLogList.h"
#include<ctime>
#include<iostream>
#include<iomanip>

using namespace std;

WaterLogList::WaterLogList()
{
	watLogActivity = new WaterLog * [10];
	for (int i = 0; i < 10; i++)
	{
		watLogActivity[i] = new WaterLog;
	}
	waterLogCapacity = 10;
	waterLogCount = 0;
}
WaterLogList::~WaterLogList()
{
	if (watLogActivity == nullptr)
	{
		waterLogCapacity = 0;
		waterLogCount = 0;
		return;
	}
	for (int i = 0; i < waterLogCapacity; i++)
	{
		delete watLogActivity[i];
	}
	delete[] watLogActivity;
	waterLogCapacity = 0;
	waterLogCount = 0;
}
void WaterLogList::reSize()
{
	//doubling capacity
	waterLogCapacity = waterLogCapacity * 2;
	//new array of double capacity
	WaterLog** WaterLogCopy = new WaterLog * [waterLogCapacity];
	for (int i = 0; i < waterLogCapacity; i++)
	{
		WaterLogCopy[i] = new WaterLog;
	}
	//copying int waterLogCopy
	for (int i = 0; i < waterLogCount; i++)
	{
		WaterLogCopy[i] = watLogActivity[i];
	}
	watLogActivity = WaterLogCopy;
}
void WaterLogList::logWater(float q)
{
	if (waterLogCount == waterLogCapacity)
	{
		reSize();
	}
	watLogActivity[waterLogCount]->setQuanitity(q);
	//current date & Time
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	watLogActivity[waterLogCount]->setWaterDate(Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900));
	watLogActivity[waterLogCount]->setwaterTime(Time(cur.tm_hour, cur.tm_min, cur.tm_sec));
	waterLogCount++;
}
void WaterLogList::logWater(float q, Date d, Time t)
{
	if (waterLogCount == waterLogCapacity)
	{
		reSize();
	}
	watLogActivity[waterLogCount]->setQuanitity(q);
	watLogActivity[waterLogCount]->setWaterDate(d);
	watLogActivity[waterLogCount]->setwaterTime(t);
	waterLogCount++;
}
WaterUnits WaterLogList::getDefaultWaterUnit()const
{
	return defaultWaterUnit;
}
void WaterLogList::changeDefaultWaterUnit(WaterUnits unit)
{
	if (unit == MILLI_LITRE && defaultWaterUnit==LITRE)
	{
		defaultWaterUnit = MILLI_LITRE;
		for (int i = 0; i < waterLogCount; i++)
		{
			float converted = watLogActivity[i]->getQuantity() * 1000;
			watLogActivity[i]->setQuanitity(converted);
		}
	}
	else if (unit == LITRE && defaultWaterUnit == MILLI_LITRE)
	{
		defaultWaterUnit = LITRE;
		for (int i = 0; i < waterLogCount; i++)
		{
			float converted = watLogActivity[i]->getQuantity() / 1000;
			watLogActivity[i]->setQuanitity(converted);
		}
	}
	else
	{
		return;
	}
}
float WaterLogList::totalWaterIntakeToday()const
{
	float total = 0;
	//todaysDate
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date today = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);
	for (int i = 0; i < waterLogCount; i++)
	{
		if (watLogActivity[i]->getWaterDate().isEqual(today))
		{
			total = total + watLogActivity[i]->getQuantity();
		}
	}
	return total;
}
float WaterLogList::totalWaterCurrentMonth()const
{
	float total = 0;
	//todaysDate
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date current = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);
	for (int i = 0; i < waterLogCount; i++)
	{
		if (watLogActivity[i]->getWaterDate().getMonth() == current.getMonth() &&
			watLogActivity[i]->getWaterDate().getYear() == current.getYear())
		{
			total = total + watLogActivity[i]->getQuantity();
		}
	}
	return total;
}
float WaterLogList::totalWaterIntakeInLastNMonth(int n)const
{
	float total = 0;
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date current = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);

	for (int i = 0; i != n + 1; i++)
	{
		for (int i = 0; i < waterLogCount; i++)
		{
			if (watLogActivity[i]->getWaterDate().getMonth() == current.getMonth() &&
				watLogActivity[i]->getWaterDate().getYear() == current.getYear())
			{
				total = total + watLogActivity[i]->getQuantity();
			}
		}
		cout << current.getMonth();
		current.decMonth(1);
	}
	return total;
}
void WaterLogList::printMonthWiseHistogram(int n)const
{
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date current = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);

	for (int i = 0; i != n; i++)
	{
		float total = 0;
		for (int i = 0; i < waterLogCount; i++)
		{
			if (watLogActivity[i]->getWaterDate().getMonth() == current.getMonth() &&
				watLogActivity[i]->getWaterDate().getYear() == current.getYear())
			{
				total = total + watLogActivity[i]->getQuantity();
			}
		}
		cout.fill('0');
		cout << current.getYear() << "-" << setw(2) << current.getMonth() << "-> ";
		if (getDefaultWaterUnit() != MILLI_LITRE)
		{
			//convert to ml
			total = total * 1000;
		}
		for (int i = 0; i < total/0.5; i++)
		{
			cout << "*";
		}
		cout << ": " << total << " ml";
		cout << "\n";
		current.decMonth(1);
	}
}
void WaterLogList::printDayWiseHistogramLastNDays(int n)const
{
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date current = Date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);

	for (int i = 0; i != n; i++)
	{
		float total = 0;
		for (int i = 0; i < waterLogCount; i++)
		{
			if (watLogActivity[i]->getWaterDate().isEqual(current))
			{
				total = total + watLogActivity[i]->getQuantity();
			}
		}
		cout.fill('0');
		current.printFormat1(); cout << setw(3) << " : ";
		if (getDefaultWaterUnit() != MILLI_LITRE)
		{
			//convert to ml
			total = total * 1000;
		}
		for (int i = 0; i < total / 0.25; i++)
		{
			cout << "*";
		}
		cout << ": " << total << " ml";
		cout << "\n";
		current.decDay(1);
	}
}