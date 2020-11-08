#include "Set.h"
#include <iostream>
#include <cmath>
using namespace std;
bool Set::isDuplicate(int element)
{
	for (int i = 0;i < noOfElements; i++)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}
Set::Set(int cap )
{
	noOfElements = 0;
	if (cap >= 0)
	{
		data.reSize(cap);
		return;
	}
	data.reSize(0);
}
Set::Set(const Set& ref) :data(ref.data), noOfElements(ref.noOfElements)
{}
Set& Set::operator=(const Set & ref)
{
	if (&ref == this)
	{
		return *this;
	}
	data =(ref.data);
	noOfElements = ref.noOfElements;
	return *this;
}
const int& Set::operator[](int index)const
{
	if (index >= 0 && index <= data.getCapacity())
	{
		return data.operator[](index);
	}
	cout << "\nINDEX OUT OF BOUND!!!";
	exit(0);
}
bool Set::isFull()const
{
	if (noOfElements == data.getCapacity())
	{
		return true;
	}
	return false;
}
bool Set::isEmpty()const
{
	if (noOfElements == 0)
	{
		return true;
	}
	return false;
}
void Set::insert(int element)
{
	if (isFull())
	{
		return;
	}
	else
	{
		if (!isDuplicate(element))
		{
			data[noOfElements] = element;
			noOfElements++;
		}
	}
}
int Set::getElementPosition(int element)const
{
	int index = -1;
	bool flag = true;
	for (int i = 0; flag || i < noOfElements; i++)
	{
		if (data[i] == element)
		{
			index = i;
			return index;
		}
	}
	return index;
}
void Set::remove(int element)
{
	if (isEmpty())
	{
		return;
	}
	int index = getElementPosition(element);
	if (index == -1)
	{
		//Element not found
		return;
	}
	for (int i = index; i < noOfElements - 1; i++)
	{
		data[i] = data[i + 1];
	}
	noOfElements--;
}
void Set::print()const
{
	if (isEmpty())
	{
		cout << "{}";
		return;
	}
	cout << "{";
	for (int i = 0; i < noOfElements - 1; i++)
	{
		cout << data[i] << ",";
	}
	cout << data[noOfElements - 1] << "}";
}
int Set::getCardinality()const
{
	return noOfElements;
}
void Set::reSize(int newCapacity)
{
	data.reSize(newCapacity);
}
Set Set::calcUnion(Set ref)const
{
	Set x(*this);
	for (int  i = 0; i < ref.noOfElements; i++)
	{	
		x.reSize(noOfElements + ref.noOfElements);
		x.insert(ref[i]);
	}
	return x;
}
Set Set::calcDifference(Set ref)const
{
	Set x(*this);
	for (int i = 0; i < noOfElements; i++)
	{
		for (int j = 0; j < ref.noOfElements; j++)
		{
			if (data[i] == ref.data[j])
			{
				x.remove(ref.data[j]);
				x.reSize(getCardinality() - 1);
			}
		}
	}
	return x;
}
void Set::displayPowerSet()const
{

	if (noOfElements == 0)
	{
		cout << "{ {} }\n";
		return;
	}
	int size = pow(2, noOfElements);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < noOfElements; j++)
		{
			if (i & (1 << j))
			{
				cout << data[j] << " ";
			}
		}
		if (i == 0)
		{
			cout << "{{ },{ ";
		}
		else if (i < size - 1)
		{
			cout << "},{ ";
		}
		else if (i == size - 1)
		{
			cout << "}}\n";
		}
	}
}
int Set::isSubSet(Set ref)const
{
	if (noOfElements == ref.noOfElements)
	{
		//check if equal
		int count = 0;
		for (int i = 0; i < noOfElements; i++)
		{
			if (data[i] == ref.data[i])
			{
				count++;
			}
		}
		if (count == noOfElements)
		{
			return 0;
		}
	}
	if (noOfElements < ref.noOfElements)
	{
		return 1;
	}
	if (noOfElements > ref.noOfElements)
	{
		return -1;
	}
	return -2;
}