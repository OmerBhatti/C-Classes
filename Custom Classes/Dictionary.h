#ifndef DICTIONARY_H
#define DICTIONARY_H

#include"Array.h"
#include<iomanip>
template<typename K,typename V>
class Dictionary
{
	Array<K> keys;
	Array<V> values;
	int count = 0;
	int capacity;
public:
	Dictionary() :keys(5), values(5), capacity(5)
	{}
	void insert(K key, V value)
	{
		if (count == capacity)
		{
			capacity = capacity * 2;
			keys.reSize(capacity);
			values.reSize(capacity);
		}
		keys[count] = key;
		values[count] = value;
		count++;
	}
	void find(K key)
	{
		for (int i = 0; i < count; i++)
		{
			if (keys[i] == key)
			{
				cout << key << " = " << values[i] << "\n";
				return;
			}
		}
		cout << "Nothing Found against key = " << key << "\n";
	}
	void printDictionary()const
	{
		system("cls");
		cout << " Keys\t\t\t     Values\n";
		cout << "------------------------------------\n";
		for (int i = 0; i < count; i++)
		{
			cout << " " << left << setw(25) << keys[i] << setw(10) << right << values[i] << "\n";
		}
		cout << "------------------------------------\n";
		system("pause");
		system("cls");
	}
	bool erase(K key)
	{
		for (int i = 0; i < count; i++)
		{
			if (keys[i] == key)
			{
				for (int j = i; j < count - 1; j++)
				{
					keys[j] = keys[j + 1];
					values[j] = values[j + 1];
				}
				count--;
				return true;
			}
		}
		return false;
	}
	int getNoOfRecords()const
	{
		return count;
	}
	int getCapacity()const
	{
		return capacity;
	}
};


#endif // !DICTIONARY_H