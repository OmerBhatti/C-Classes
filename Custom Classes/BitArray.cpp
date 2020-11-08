#include "BitArray.h"
#include <iostream>
#include <cmath>
using namespace std;
int BitArray::getCapacity()const
{
	return capacity;
}
BitArray::BitArray(int n)
{
	capacity = n;
	int s = (int)ceil((float)capacity / 8);
	data = new unsigned char[s];
	for (int i = 0; i < s; i++)
	{
		//initialize with zeroes
		data[i] = data[i] & 0;
	}
}
BitArray::BitArray(const BitArray& ref)
{
	if (ref.data == nullptr)
	{
		data = nullptr;
		capacity = 0;
		return;
	}
	int s = (int)ceil((float)(ref.capacity / 8));
	capacity = ref.capacity;
	data = new unsigned char[s];
	for (int i = 0; i < s; i++)
	{
		data[i] = ref.data[i];
	}
}
void BitArray::on(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int block = bitNo / 8;
		int bit = bitNo % 8;
		unsigned char mask = (1 << (bit));
		data[block] = data[block] | mask;
	}
}
void BitArray::off(int bitNo)
{	
	if (isValidBit(bitNo))
	{
		int block = bitNo / 8;
		int bit = bitNo % 8;
		unsigned char mask = (1 << (bit));
		data[block] = data[block] & ~mask;
	}
}
bool BitArray::checkBitStatus(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int block = bitNo / 8;
		int bit = bitNo % 8;
		unsigned char x = data[block];
		return x & (1 << bit);
	}
}
void BitArray::invert(int bitNo)
{
	if (isValidBit(bitNo))
	{
		int block = bitNo / 8;
		int bit = bitNo % 8;
		unsigned char mask = (1 << (bit));
		data[block] = data[block] ^ mask;
	}
}
void BitArray::dump()
{
	for (int i = capacity - 1; i >= 0; i--)
	{
		if (i % 8 == 0)
		{
			cout << checkBitStatus(i) << " ";
		}
		else
		{
			cout << checkBitStatus(i);
		}
	}
	cout << "\n";
}
BitArray BitArray::AND(BitArray & arr2)
{
	BitArray arr(capacity);
	int s = (int)ceil((float)capacity / 8);
	for (int i = 0; i < s; i++)
	{
		arr.data[i] = data[i] & arr2.data[i];
	}
	return arr;
}

BitArray BitArray::OR(BitArray & arr2)
{
	BitArray arr(arr2);
	int s = (int)ceil((float)capacity / 8);
	for (int i = 0; i < s; i++)
	{
		arr.data[i] = data[i] | arr2.data[i];
	}
	return arr;
}

void BitArray::shiftLeft(int count)
{
	setIntegralValue(getUnsignedIntegeralValue() * pow(2, count));
}

void BitArray::shiftRight(int count)
{
	setIntegralValue(getUnsignedIntegeralValue() / pow(2, count));
}

unsigned long long BitArray::getUnsignedIntegeralValue()
{
	unsigned long long value = 0;
	for (int i = 0; i < capacity; i++)
	{
		//1101 = 1*2^0 + 1*2^1 + 0*2^2 + 1*2^3 = 1+2+0+8 = 11
		value = value + checkBitStatus(i) * pow(2, i);
	}
	return value;
}
void BitArray::setIntegralValue(unsigned long long value)
{
	int max = pow(2, capacity);
	if (value < max)
	{
		int s = (int)ceil((float)capacity / 8);
		for (int i = 0; i < s; i++)
		{
			//reset array
			data[i] = data[i] & 0;
		}
		for (int i = 0; value; i++)
		{
			if (value % 2 == 0)
			{
				off(i);
			}
			else if(value % 2 == 1)
			{
				on(i);
			}
			value = value / 2;
		}
	}
}
BitArray::~BitArray()
{
	if (data == nullptr)
	{
		capacity = 0;
		return;
	}
	delete[]data;
	capacity = 0;
}