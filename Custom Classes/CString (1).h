#ifndef C_STRING_H
#define C_STRING_H

#include<iostream>
using namespace std;

class CString
{
	friend istream& operator>>(istream&, CString&);
	friend ostream& operator<<(ostream&, const CString&);
		//Data Members
	char* data;
	int size;
		//Utility Member Functions
	static int getLength(const char*);
	bool isValidIndex(int index)const;
	static void CStrCpy(char*, const char*);
	void sortArray(int* arr, int size);
public:
	CString();													// Defalt Constructor
	CString(const char character);								// Single Character Constructor
	CString(const char* str);									// Constructor receiving "some-text" in quotes
	CString(const CString& reference);							// Copy Constructor
	CString & operator=(const CString& reference);				// Assignment Operator Overloaded
	CString(CString&& reference);								// Move Constructor
	CString& operator=(CString&& reference);					// Move Assignment Operator
	void display() const;										// Display The String
	~CString();													// Destructor
	int getLength() const;										// Length of string till null
	int getSize() const;										// Size of string eeven if it's not filled
	bool isEmpty() const;
	const char& operator[](const int index)const;				// Return const reference to data for printing purposes
	char& operator[](const int index);							// Return reference to data for changing it
	void makeUpper();											// Convert to Upper Case only letter (a-z)
	void makeLower();											// Convert to Lower Case only letter (A-Z)
	void reSize(int);											// ReSize data to new Capacity
	void trim();												// Removes all leading & trailing whitespaces
	void trimLeft();											// Removes all leading Whitespaces
	void trimRight();											// Removes all trailing Whitespaces
	void input();
	void operator+=(const CString& s2);							// Concatenate the calling object with s2
	bool operator==(const CString& s2);							// Compares if two Strings are Equal?
	CString operator+(const CString& s2)const;					// Retrun a concatenated object of this and s2
	int find(const CString& subStr, int start = 0) const;		// Find the substring and returns index & -1 if not found
	void remove(int index, int count = 0);						// Removes characters from index to index + count
	CString left(int count);									// return an object containing left N characters
	CString right(int count);									// return an object containing right N characters
	explicit operator long long int()const;						// Conversion Constructor to long long int
	explicit operator double()const;							// Conversion Constructor to double
	void reverse();												// reverse the string
	CString tokenize(const CString& delim);						// Removes and return extracted string till delim(any)
	CString operator()(const CString& delim);					// Alternative of Tokenizer
	void insert(int index, const CString& subStr);				// insert the substring at index
	int replace(const CString& old, const CString& newSubStr);
	static CString to_CString(long long int num)
	{
		if (num > 0)
		{
			CString n;
			while (num)
			{
				int rem = num % 10;
				num = num / 10;
				n += (rem + '0');
			}
			n.reverse();
			return n;
		}
		else
		{
			CString n;
			num = num * -1;
			while (num)
			{
				int rem = num % 10;
				num = num / 10;
				n += (rem + '0');
			}
			n += '-';
			n.reverse();
			return n;
		}
	}
};
#endif