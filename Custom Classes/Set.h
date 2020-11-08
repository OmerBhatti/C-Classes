#ifndef SET_H
#define SET_H

#include"Array.h"
class Set
{
	Array data;
	int noOfElements;
	bool isDuplicate(int element);
public:
	Set(int cap = 0);
	Set(const Set& ref);
	Set& operator=(const Set& ref);
	const int& operator[](int index)const;
	bool isFull()const;
	bool isEmpty()const;
	void insert(int element);
	void remove(int element);
	virtual void print()const;
	int getCardinality()const;
	int getElementPosition(int element)const;
	int isSubSet(Set ref)const;
	void reSize(int newCapacity);
	Set calcUnion(Set ref)const;
	Set calcDifference(Set ref)const;
	void displayPowerSet()const;
};

#endif // !SET_H

