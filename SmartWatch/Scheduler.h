#ifndef SCHEDULER_H
#define SCHEDULER_H

#define _CRT_SECURE_NO_WARNINGS
#include"Task.h"
class Scheduler
{
	Task* taskList;
	int noOfTasks;
	int capacity;
public:
	Scheduler();
	void addTask(const Task& t);
	void displayTask(const Date& d = Date());
	void displayTodaysTask();
	void reSize(int);
};

#endif // 



