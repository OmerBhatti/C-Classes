#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
class Matrix
{
	Array* data;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int, int);
	Array operator()(int rowNo)const;
	Array& operator [](int index);
	const Array& operator [](int index)const;
	Matrix& operator=(const Matrix&);
	~Matrix();
};

#endif // !MATRIX_H