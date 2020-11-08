#include<iostream>
#include"CString.h"

istream& operator>>(istream& cin, CString& ref)
{
	ref.input();
	return cin;
}
ostream& operator<<(ostream& cout, const CString& ref)
{
	ref.display();
	return cout;
}
void CString::sortArray(int *arr , int size)
{
	int temp;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - 1; j++) 
		{
			if (arr[j] > arr[i]) 
			{
				//swap them
				temp = arr[i]; 
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
bool CString::operator==(const CString& s2)
{
	int s1Len = this->getLength(),
		s2Len = s2.getLength();

	if (s1Len == s2Len)
	{
		int count = 0;
		for (int  i = 0; i != s1Len; i++)
		{
			if (data[i] == s2.data[i])
			{
				count++;
			}
		}
		if (count == s1Len)
		{
			return true;
		}
		count = 0;
	}
	return false;
}
int CString::getLength(const char* str)
{
	if (str == 0)
		return 0;
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return count;
}

int CString::getLength() const
{
	if (data == nullptr)
		return 0;
	int count = 0;
	while (data[count] != '\0')
	{
		count++;
	}
	return count;
}

int CString::getSize() const
{
	return size;
}

void CString::CStrCpy(char* dest, const char* source)
{
	if (source == nullptr)
		return;
	int i = 0;
	for (i = 0; source[i] != '\0'; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
}

CString::CString() :data(nullptr), size(0)
{
	//places null and size 0
}
CString::CString(const char x) :CString()
{
	if (x == '\0')
	{
		data = 0;
		size = 0;
		return;
	}
	data = new char[2];
	data[0] = x;
	data[1] = '\0';
	size = 2;
}
CString::CString(const char* str) : CString()
{
	if (str == nullptr)
	{
		size = 0;
		return;
	}
	int len = getLength(str);
	data = new char[len + 1];
	CStrCpy(data, str);
	size = len + 1;
}
CString::CString(const CString& ref) : CString()
{
	if (ref.data == nullptr)
	{
		this->~CString();
		size = 0;
		return;
	}
	int len = getLength(ref.data);
	size = len + 1;
	data = new char[size];
	CStrCpy(this->data, ref.data);
}

CString &CString::operator=(const CString& ref)
{
	//self Assignment
	if (&ref == this)
	{
		return *this;
	}
	if (ref.data == nullptr)
	{
		this->~CString();
		size = 0;
		return *this;
	}
	int len = getLength(ref.data);
	size = len + 1;
	data = new char[size];
	CStrCpy(this->data, ref.data);
	return *this;
}

CString::CString(CString&& ref) :data(move(ref.data)), size(move(ref.size))
{
	ref.data = nullptr;
	ref.size = 0;
}

CString& CString::operator=(CString&& ref)
{
	//self Assignment
	if (&ref == this)
	{
		return *this;
	}
	if (ref.data == nullptr)
	{
		this->~CString();
		size = 0;
		return *this;
	}
	data = move(ref.data);
	size = move(ref.size);
	ref.data = nullptr;
	ref.size = 0;
	return *this;
}

CString::~CString()
{
	if (data == nullptr)
	{
		size = 0;
		return;
	}
	delete[]data;
	size = 0;
}
void CString::display() const
{
	if (size == 0 || data == nullptr)
		return;
	for (int i = 0; data[i] != '\0'; i++)
	{
		cout << data[i];
	}
	cout << "\n";
}

bool CString::isValidIndex(int index)const
{
	if (index < 0 || index >= size - 1)
	{
		return false;
	}
	return true;
}

bool CString::isEmpty() const
{
	if (data == nullptr || size == 0)
		return true;
	return false;
}
char& CString::operator[](const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "\nINDEX OUT OF BOUND!!!!";
	exit(0);
}
const char& CString::operator[](const int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	cout << "\nINDEX OUT OF BOUND!!!!";
	exit(0);
}
void CString::makeUpper()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
		i++;
	}
}
void CString::makeLower()
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
		i++;
	}
}
void CString::reSize(int s)
{
	char* copy = new char[s + 1];
	int i = 0;
	for (i = 0; i < (s < size ? s: size); i++)
	{
		copy[i] = this->data[i];
	}
	copy[i] = 0;
	int len;
	if (s < size)
		len = getLength(copy) + 1;
	len = s + 1;
	size = len;
	data = copy;
}
void CString::trimLeft()
{
	if (data[0] != ' ' && data[0] != '\t' && data[0] != '\n' && data[0] != '\0')
	{
		return;
	}
	bool isWhiteSpace = true;
	int i = 0;
	for (i = 0; isWhiteSpace; i++)
	{
		if (data[i] != ' ' && data[i] != '\t' && data[i] != '\n' && data[i] != '\0')
		{
			isWhiteSpace = false;
		}
	}
	remove(0, i - 1);
}
void CString::trim()
{
	trimLeft();
	trimRight();
}
void CString::trimRight()
{	
	bool character = false;
	int i = getLength();
	for (i; !character; i--)
	{
		if (data[i] != ' ' && data[i] != '\t' && data[i] != '\n' && data[i] != '\0')
		{
			character = true;
		}
	}
	i = i + 2;
	remove(i, size - i - 1);
}
void CString::reverse()
{
	char* reverse = new char[size];
	//stops null at end to be place at start
	int j = getLength() - 1;
	for (int i = 0; i < size; i++, j--)
	{
		reverse[i] = data[j];
	}
	//null at end of reversed string...
	reverse[size - 1] = '\0';
	delete[]data;
	data = reverse;
}
CString CString::operator+(const CString& s2)const
{
	int len = getLength();
	int concatLen = len + s2.getLength() + 1;
	char* concat = new char[concatLen];
	int i;
	for (i = 0; i < data[i] != 0; i++)
	{
		concat[i] = data[i];
	}
	for (int j = 0; j < s2.getLength(); j++)
	{
		concat[i] = s2.data[j];
		i++;
	}
	concat[i] = 0;
	CString ans(concat);
	return ans;
}
void CString::operator+=(const CString& s2)
{
	if (data != nullptr)
	{
		size = getLength() + s2.getLength() + 1;
		char* concat = new char[size];
		int i;
		for (i = 0; i < data[i] != 0; i++)
		{
			concat[i] = data[i];
		}
		for (int j = 0; j < s2.getLength(); j++)
		{
			concat[i] = s2.data[j];
			i++;
		}
		concat[i] = 0;
		data = concat;
	}
	else // if calling object is not yet constructed!!
	{
		*this = s2;
	}
}
void CString::input()
{
	data = new char[10000];
	cin.getline(data, 10000);
	size = getLength(data);
	reSize(size);
}

int CString::find(const CString& subStr, int start) const
{
	if (subStr.isEmpty() || this->isEmpty())
	{
		return -1;
	}
	int subStrLen = subStr.getLength();
	for (int i = start; i < data[i]!='\0'; i++)
	{
		int count = 0;
		if (data[i] == subStr[0])
		{
			//search Next Index
			for (int j = 0; j < subStrLen; j++, i++)
			{
				if (data[i] == subStr[j])
				{
					count++;
				}
			}
			if (count == subStrLen)
			{
				return i - subStrLen;
			}
		}
	}
	return -1;
}
CString::operator long long int()const
{
	if (data[0] == '-')
	{
		long long int number = 0;
		int mul = 1;
		for (int i = 1; i < getLength() - 1; i++)
		{
			mul = mul * 10;
		}
		for (int i = 1; i < getLength(); i++)
		{
			number = number + (data[i] - '0') * mul;
			mul = mul / 10;
		}
		return -number;
	}
	else
	{
		long long int number = 0;
		int mul = 1;
		for (int i = 0; i < getLength() - 1; i++)
		{
			mul = mul * 10;
		}
		for (int i = 0; i < getLength(); i++)
		{
			number = number + (data[i] - '0') * mul;
			mul = mul / 10;
		}
		return number;
	}
}
CString::operator double()const
{
	if (data[0] == '-')
	{
		double number = 0;
		int mul = 1;
		for (int i = 1; i < getLength() - 2; i++)
		{
			mul = mul * 10;
		}
		for (int i = 1; i < getLength(); i++)
		{
			if (data[i] != '.')
			{
				number = number + (data[i] - '0') * mul;
				mul = mul / 10;
			}
		}
		int posOfpoint = find('.');
		int div = 1;
		for (int i = 0; i < size - posOfpoint - 2; i++)
		{
			div = div * 10;
		}
		return -number / div;
	}
	else
	{
		double number = 0;
		int mul = 1;
		for (int i = 0; i < getLength() - 1; i++)
		{
			mul = mul * 10;
		}
		for (int i = 0; i < getLength(); i++)
		{
			if (data[i] != '.')
			{
				number = number + (data[i] - '0') * mul;
				mul = mul / 10;
			}
		}
		int posOfpoint = find('.');
		int div = 1;
		for (int i = 0; i < size - posOfpoint - 1; i++)
		{
			div = div * 10;
		}
		return number / div;
	}
}
CString CString::left(int count)
{
	CString obj(*this);
	obj.remove(count, size - count - 1);
	return obj;
}
CString CString::right(int count)
{
	CString obj(*this);
	obj.remove(0, size - count - 1);
	return obj;
}
void CString::remove(int index, int count)
{
	for (int i = index; i < size; i++)
	{
		data[i] = data[i + count];
	}
	size = size - count;
}
CString CString::tokenize(const CString& delim)
{
	if (this->isEmpty() || getLength() == 0)
	{
		data = nullptr;
		CString x;
		return x;
	}
	CString token(delim);
	int* indexes = new int[delim.getLength()];
	for (int i = 0; i < delim.getLength(); i++)
	{
		int index = find(delim[i]);
		if (index == -1)
		{
			indexes[i] = size + 100;
		}
		else
		{
			indexes[i] = index;
		}
	}
	sortArray(indexes, delim.getLength());
	if (indexes[0] == 0)
	{
		token = left(1);
		remove(0, 1);
	}
	else
	{
		token = left(indexes[0]);
		remove(0, indexes[0]);
	}
	return token;
}

CString CString::operator()(const CString& delim)
{
	CString token = tokenize(delim);
	return token;
}
void CString::insert(int index, const CString& subStr)
{
	if (index > size)
	{
		return;
	}
	reSize(size + subStr.getLength());
	CString copy(*this);
	for (int i = 0; i < subStr.getLength(); i++)
	{
		data[index + i] = subStr[i];
	}
	for (int j = index; j < copy.getLength(); j++)
	{
		data[j + subStr.getLength()] = copy[j];
	}
	data[size - 2] = '\0';
}
int CString::replace(const CString& old, const CString& newSubStr)
{
	int count = 0;
	while (find(old) != -1)
	{
		int index = find(old);
		remove(index, old.getLength());
		insert(index, newSubStr);
		count++;
	}
	remove(getLength() - count + 1, count - 1);
	return count;
}