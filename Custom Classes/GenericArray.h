#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
class Array
{
	T* data;
	int capacity;
	int isValidIndex(int index)const
	{
		return index >= 0 && index < capacity;
	}
public:
	Array(initializer_list<T> list)
	{
		int size = list.size();
		if (size == 0)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		data = new T[size];
		capacity = size;
		int i = 0;
		// for range loop
		for (auto item : list)
		{
			data[i] = item;
			i++;
		}
	}
	Array()
	{
		capacity = 0;
		data = nullptr;
	}
	Array(int size)
	{
		if (size < 0)
		{
			capacity = 3;
		}
		else
		{
			capacity = size;
		}
		data = new T[capacity];
	}
	T& operator[](int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		cout << "INVALID INDEX/n";
		exit(0);
	}
	const T& operator[](int index)const
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		cout << "INVALID INDEX/n";
		exit(0);
	}
	Array(Array&& ref) :data(move(ref.data)), capacity(move(ref.capacity))
	{
		ref.data = 0;
		ref.capacity = 0;
	}
	Array<T>& operator=(Array&& ref)
	{
		if (&ref == this)
		{
			return *this;
		}
		this->~Array();
		data = move(ref.data);
		capacity = move(ref.capacity);
		ref.data = nullptr;
		ref.capacity = 0;
		return *this;
	}
	void display()
	{
		if (data == nullptr)
		{
			cout << "{}\n";
			return;
		}
		cout << "{";
		for (int i = 0; i < capacity - 1; i++)
		{
			cout << data[i] << ",";
		}
		cout << data[capacity - 1] << "}\n";
	}
	Array(const Array& ref)
	{
		if (ref.data == nullptr)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < ref.capacity; i++)
		{
			data[i] = ref[i];
		}
	}
	Array<T> operator=(const Array& ref)
	{
		if (&ref == this)
		{
			return *this;
		}
		if (ref.data == nullptr)
		{
			data = nullptr;
			capacity = 0;
			return *this;
		}
		this->~Array();
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < ref.capacity; i++)
		{
			data[i] = ref[i];
		}
		return *this;
	}
	int getCapacity()const
	{
		return capacity;
	}
	void reSize(int newCap)
	{
		if (newCap <= 0)
		{
			this->~Array();
			return;
		}
		T* copy = new T[newCap];
		for (int i = 0; i < (newCap < capacity ? newCap : capacity); i++)
		{
			copy[i] = data[i];
		}
		this->~Array();
		capacity = newCap;
		data = copy;
	}
	~Array()
	{
		if (!data)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		delete[] data;
		data = nullptr;
		capacity = 0;
	}
};

#endif