#include"BoundedInteger.h"
#include<iostream>
using namespace std;

BoundedInteger::BoundedInteger()
{
	lowerBound = INT_MIN;
	upperBound = INT_MAX;
	value = 0;
}
BoundedInteger::BoundedInteger(int lb, int ub) :BoundedInteger()
{
	if (!isValidBound(lb, ub))
		return;
	lowerBound = lb;
	upperBound = ub;
	value = lb;
}
BoundedInteger::BoundedInteger(int lb, int ub, int val) :BoundedInteger()
{
	if (!isValidBound(lb, ub))
		return;
	lowerBound = lb;
	upperBound = ub;
	if (isValidValue(val))
	{
		value = val;
	}
	else
	{
		value = lb;
	}
}
void BoundedInteger::setValue(int val)
{
	if (isValidValue(val))
	{
		value = val;
		return;
	}
	cout << "\nVALUE OUT OF BOUND.";
	exit(0);
}
int BoundedInteger::getValue()const
{
	return value;
}
int BoundedInteger::getLowerBound()const
{
	return lowerBound;
}
int BoundedInteger::getUpperBound()const
{
	return upperBound;
}
void BoundedInteger::increment(int inc)
{
	for (int i = 0; i < inc; i++)
	{
		if (value >= upperBound)
		{
			value = lowerBound;
		}
		else
		{
			value = value + 1;
		}
	}
}
void BoundedInteger::decrement(int dec)
{
	for (int i = 0; i < dec; i++)
	{
		if (value <= lowerBound)
		{
			value = upperBound;
		}
		else
		{
			value = value - 1;
		}
	}
}
bool BoundedInteger::isValidValue(int val)const
{
	if (val >= lowerBound && val <= upperBound)
	{
		return true;
	}
	return false;
}
bool BoundedInteger::isValidBound(int lb, int ub)
{
	if (lb > INT_MIN && ub < INT_MAX)
	{
		return true;
	}
	return false;
}