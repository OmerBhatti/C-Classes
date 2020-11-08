#ifndef ARRAY_H
#define ARRAY_H
#define _CRT_SECURE_NO_WARNINGS
class Array
{
	int* data;
	int capacity;
	int isValidIndex(int index)const
	{
		return index >= 0 && index < capacity;
	}
public:
	Array(int argCount = 0, ...);
	Array& operator=(const Array&);
	Array(const Array& ref);
	~Array();
	int& operator[](int index);
	const int& operator[](int index)const;
	int getCapacity();
	void reSize(int newCap);
	void display();

};

#endif