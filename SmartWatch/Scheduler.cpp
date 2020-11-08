#include "Scheduler.h"
#include"Task.h"
#include<iostream>
#include<ctime>
using namespace std;

Scheduler::Scheduler()
{
	capacity = 5;
	noOfTasks = 0;
	taskList = new Task[capacity];
}
void Scheduler::addTask(const Task& t)
{
	if (noOfTasks == capacity)
	{
		reSize(capacity + 1);
	}
	taskList[noOfTasks].SetTask(t.getDate(), t.getTime(), t.getMessage());
	noOfTasks++;
}
void Scheduler::displayTask(const Date& d)
{
	if (d.getDay() == 1 && d.getMonth() == 1 && d.getYear() == 1600)
	{
		int taskNo = 1;
		//currentDate
		time_t t = time(NULL);
		tm cur = *localtime(&t);
		Date date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);
		for (int i = 0; i < noOfTasks; i++)
		{
			if (date.getDay() == taskList[i].getDate().getDay() && date.getMonth() == taskList[i].getDate().getMonth()
				&& date.getYear() == taskList[i].getDate().getYear())
			{
				cout << "-----------------Task No:";cout << taskNo;cout<<"-----------------\n";
				//it means it's today task
				cout << "Task Date: "; taskList[i].getDate().printFormat1();
				cout << "\nTask Time: "; taskList[i].getTime().printTwelveHourFormat();
				cout << "Task Message :\n";
				cout << "\t";
				taskList[i].getMessage().display();
				cout << "\n";
				taskNo++;
			}
		}
		cout << "-------------------------------------------\n";
		return;
	}

	bool found = false;
	for (int i = 0; i < noOfTasks; i++)
	{
		if (d.getDay() == taskList[i].getDate().getDay() && d.getMonth() == taskList[i].getDate().getMonth()
			&& d.getYear() == taskList[i].getDate().getYear())
		{
			found = true;
			cout << "-----------------Task Found-----------------\n";
			cout << "Task Date: "; taskList[i].getDate().printFormat1();
			cout << "\nTask Time: "; taskList[i].getTime().printTwelveHourFormat();
			cout << "Task Message :\n";
			cout << "\t";
			taskList[i].getMessage().display();
			cout << "\n";
		}
	}
	if (!found)
	{
		cout << "\nNo task Found Against Date: "; d.printFormat1(); cout << "\n";
		return;
	}
	cout << "-------------------------------------------\n";
}
void Scheduler::displayTodaysTask()
{
	//currentDate
	time_t t = time(NULL);
	tm cur = *localtime(&t);
	Date date(cur.tm_mday, cur.tm_mon + 1, cur.tm_year + 1900);
	for (int i = 0; i < noOfTasks; i++)
	{
		if (date.getDay() == taskList[i].getDate().getDay() && date.getMonth() == taskList[i].getDate().getMonth()
			&& date.getYear() == taskList[i].getDate().getYear())
		{
			cout << "---------------Todays's Task---------------\n";
			//it means it's today task
			cout << "Task Date: "; taskList[i].getDate().printFormat1();
			cout << "\nTask Time: "; taskList[i].getTime().printTwelveHourFormat();
			cout << "Task Message :\n";
			cout << "\t";
			taskList[i].getMessage().display();
			cout << "\n";
		}
	}
	cout << "-------------------------------------------\n";
	return;
}
void Scheduler::reSize(int s)
{
	Task* copy = new Task[s];
	for (int i = 0; i < noOfTasks; i++)
	{
		copy[i].SetTask(taskList[i].getDate(), taskList[i].getTime(), taskList[i].getMessage());
	}
	capacity = s;
	taskList = copy;
}