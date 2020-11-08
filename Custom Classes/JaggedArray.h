#ifndef JAGGEDARRAY_H
#define JAGGEDARRAY_H
#include"Array.h"
#define _CRT_SECURE_NO_WARNINGS

class JaggedArray
{
	Array** data;
	int rows;
	bool isValidRow(int r)const;
public:
	JaggedArray(int r = 0, ...);
	JaggedArray(const JaggedArray& ref);
	Array& operator [](int i);
	const Array& operator [](int i)const;
	int getRows()const;
	int getColumns(int r)const;
	~JaggedArray();
};

#endif // !JAGGEDARRAY_H
