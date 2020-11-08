#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

class BitArray
{
	unsigned char* data;
	int capacity;
	bool isValidBit(int i)
	{
		return i >= 0 && i < capacity;
	}
public:
	int getCapacity()const;
	BitArray(int n = 8);
	BitArray(const BitArray& ref);
	void on(int bitNo);
	void off(int bitNo);
	bool checkBitStatus(int bitNo);
	void invert(int BitNo);
	void dump();
	BitArray AND(BitArray& arr2);
	BitArray OR(BitArray& arr2);
	/*void NOT()
	{
		int s = (int)ceil((float)capacity / 8);
		for (int i = 0; i < s; i++)
		{
			data[i] = ~data[i];
		}
	}*/
	void shiftLeft(int count);
	void shiftRight(int count);
	void setIntegralValue(unsigned long long value);
	unsigned long long getUnsignedIntegeralValue();
	~BitArray();
};

#endif // !BIT_ARRAY_H