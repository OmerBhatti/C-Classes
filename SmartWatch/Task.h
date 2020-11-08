#pragma once
#ifndef TASK_H
#define TASK_H

#include"Date.h"
#include"CString.h"
#include"Time.h"

class Task
{
	Date taskDate;
	Time taskTime;
	CString taskMsg;
public:
	Task()
	{}
	Task(const Date& d, const Time& t, const CString& msg) :taskDate(d), taskMsg(msg), taskTime(t)
	{}
	void SetTask(const Date& d, const Time& t, const CString& msg);
	void updateTime(const Time& t);
	void updateDate(const Date& d);
	void updateMessage(const CString& m);
	Date getDate()const;
	Time getTime()const;
	CString getMessage()const;
};


#endif // !TASK_H


