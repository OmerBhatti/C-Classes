#include "Matrix.h"
#include "Array.h"
#include<iostream>
using namespace std;

Matrix::Matrix() :data(nullptr), rows(0), cols(0)
{ }

Matrix::Matrix(int r, int c)
{
	if (r == 0 && c == 0)
	{
		data = nullptr;
		rows = 0;
		cols = 0;
		return;
	}
	if (r < 0 || c < 0)
	{
		cout << "\nInvalid Rows or Column Passed !!!\nExitting.....\n";
		exit(0);
	}
	rows = r;
	cols = c;
	data = new Array[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i].reSize(cols);
	}
}
Array* Matrix::operator()(int rowNo)const
{
	if (rowNo<0 && rowNo>rows)
	{
		cout << "\nInvalid Rows Passed in Matrix::operator().!!!\nExitting.....\n";
		exit(0);
	}
	//rowNo is valid!!!
	Array* copy = new Array[cols];
	copy->operator=(data[rowNo]);
	return copy;
}

Array& Matrix::operator [](int index)
{
	if (index < 0)
	{
		cout << "\nInvalid Rows Passed in Matrix::operator().!!!\nExitting.....\n";
		exit(0);
	}
	//index is valid!!!
	return data[index];
}

const Array& Matrix::operator [](int index)const
{
	if (index < 0)
	{
		cout << "\nInvalid Rows Passed in Matrix::operator().!!!\nExitting.....\n";
		exit(0);
	}
	//index is valid!!!
	return data[index];
}
Matrix& Matrix::operator=(const Matrix& ref)
{
	if (ref.data == nullptr)
	{
		rows = 0;
		cols = 0;
		data = nullptr;
		return *this;
	}
	if (this == &ref)
	{
		//self copying;
		return *this;
	}
	rows = ref.rows;
	cols = ref.cols;
	data = new Array[rows];
	for (int i = 0; i < rows; i++)
	{
		data[i].reSize(cols);
		data[i].operator=(ref.data[i]);
	}
}

Matrix::~Matrix()
{
	if (data == nullptr)
	{
		rows = 0;
		cols = 0;
		return;
	}
	for (int i = 0; i < rows; i++)
	{
		data[i].~Array();
	}
	delete[]data;
}