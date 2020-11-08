#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE_H
#define DATE_H
#include"BoundedInteger.h"
#include"CString.h"

class Date
{
	BoundedInteger day;
	BoundedInteger month;
	BoundedInteger year;
	static const int daysInMonth[13];
	static const CString monthsName[13];
	bool isLeapYear(int y)const;
public:
	Date();
	Date(int, int, int);
	void setDate(int,int,int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDaysInMonth()const;
	bool compareDate(const Date&)const;
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void printFormat1()const;
	void printFormat2()const;
	void printFormat3()const;
	/*
	CString getDateInFormat1()const;
	CString getDateInFormat2()const;
	CString getDateInFormat3()const;
	*/
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	void decDay(int = 1);
	void decMonth(int = 1);
	void decYear(int = 1);
};

#endif
