#include "Task.h"

void Task::SetTask(const Date& d, const Time& t, const CString& msg)
{
	taskDate = d;
	taskTime = t;
	taskMsg = msg;
}
void Task::updateTime(const Time& t)
{
	taskTime = t;
}
void Task::updateDate(const Date& d)
{
	taskDate = d;
}
void Task::updateMessage(const CString& m)
{
	taskMsg = m;
}
Date Task::getDate()const
{
	return taskDate;
}
Time Task::getTime()const
{
	return taskTime;
}
CString Task::getMessage()const
{
	return taskMsg;
}