#include"Array.h"
#include"JaggedArray.h"
#include<stdarg.h>
#include<iostream>
using namespace std;

bool JaggedArray::isValidRow(int r)const
{
	if (r < 0)
	{
		return false;
	}
	return true;
}
JaggedArray::JaggedArray(int r, ...)
{
	if (r == 0)
	{
		data = nullptr;
		rows = 0;
		return;
	}
	rows = r;
	data = new Array * [r];
	va_list vl;
	va_start(vl, r);
	for (int i = 0; i < rows; i++)
	{
		data[i] = new Array(va_arg(vl, int));
	}
	va_end(vl);
}
JaggedArray::JaggedArray(const JaggedArray& ref)
{
	if (ref.data == this->data)
	{
		//self copy
		return;
	}
	if (ref.data == nullptr)
	{
		data = nullptr;
		rows = 0;
		return;
	}
	rows = ref.rows;
	data = new Array * [rows];
	for (int i = 0; i < rows; i++)
	{
		//making array
		data[i] = new Array(ref.data[i]->getCapacity());
		//copying data
		data[i]->operator=(*ref.data[i]);
	}
}
Array& JaggedArray::operator [](int i)
{
	if (isValidRow(i))
	{
		return data[i][0];
	}
	cout << "INVALID INDEX!\n";
	exit(0);
}
const Array& JaggedArray::operator [](int i)const
{
	if (isValidRow(i))
	{
		return data[i][0];
	}
	cout << "INVALID INDEX!\n";
	exit(0);
}
int JaggedArray::getRows()const
{
	return rows;
}
int JaggedArray::getColumns(int r)const
{
	return data[r]->getCapacity();
}
JaggedArray::~JaggedArray()
{
	if (data == nullptr)
	{
		rows = 0;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		data[i]->~Array();
	}
	delete data;
}