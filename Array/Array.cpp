#include<iostream>
#include<stdarg.h>
#include"Array.h"
using namespace std;

Array::~Array()
{
	if (data)
		delete[] data;
	data = nullptr;
	capacity = 0;
}
int& Array::operator[](int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "INVALID INDEX/n";
	exit(0);
}
const int& Array::operator[](int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "INVALID INDEX/n";
	exit(0);
}
void Array::display()
{
	cout << "{";
	for (int i = 0; i < capacity - 1; i++)
	{
		cout << data[i] << ",";
	}
	cout << data[capacity - 1] << "}\n";
}
Array::Array(int argCount , ...)
{
	if (argCount == 0)
	{
		capacity = 0;
		data = nullptr;
		return;
	}
	capacity = argCount;
	data = new int[capacity];
	va_list vl;
	va_start(vl, argCount);
	for (int i = 0; i < capacity; i++)
	{
		data[i] = va_arg(vl, int);
	}
	va_end(vl);
}
Array::Array(const Array& ref)
{
	if (ref.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	capacity = ref.capacity;
	data = new int[capacity];
	memcpy(data, ref.data, capacity * sizeof(int));
}
Array& Array::operator=(const Array& ref)
{
	if (ref.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		return *this;
	}
	capacity = ref.capacity;
	data = new int[capacity];
	memcpy(data, ref.data, capacity * sizeof(int));
	return *this;
}
int Array::getCapacity()
{
	return capacity;
}
void Array::reSize(int newCap)
{
	if (newCap <= 0)
	{
		this->~Array();
		return;
	}
	int* copy = new int[newCap];
	for (int i = 0; i < (newCap < capacity ? newCap : capacity); i++)
	{
		copy[i] = data[i];
	}
	this->~Array();
	capacity = newCap;
	data = copy;
}