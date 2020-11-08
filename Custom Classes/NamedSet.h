#ifndef NAMEDSET_H
#define NAMEDSET_H

#define _CRT_SECURE_NO_WARNINGS
#include "Set.h"
#include "CString.h"
class NamedSet : public Set
{
	CString name;
	NamedSet(const Set& ref);
public:
	NamedSet(CString n = 'A', int cap = 0, ...);
	NamedSet(const NamedSet& ref);
	NamedSet& operator=(const NamedSet& ref);
	void setname(CString s);
	CString getName()const;
	int isSubSet(const NamedSet& s2)const;
	NamedSet calcUnion(const NamedSet& s2)const;
	NamedSet calcSymmetricDifference(const NamedSet& ref)const;
	void print()const;
};

#endif // !NAMEDSET_H

