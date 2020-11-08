#include "NamedSet.h"
#include <stdarg.h>
using namespace std;
NamedSet::NamedSet(CString n, int cap, ...) :name(n)
{
	if (cap >= 0)
	{
		this->reSize(cap);
	}
	va_list vl;
	va_start(vl, cap);
	for (int i = 0; i < cap; i++)
	{
		insert(va_arg(vl, int));
	}
	va_end(vl);
}
NamedSet::NamedSet(const NamedSet& ref) :Set(ref), name(ref.name)
{}
NamedSet& NamedSet::operator=(const NamedSet& ref)
{	
	if (&ref == this)
	{
		return *this;
	}
	this->operator=(ref);
	name = ref.name;
	return *this;
}

void NamedSet::setname(CString s)
{
	name = s;
}
CString NamedSet::getName()const
{
	return name;
}
int NamedSet::isSubSet(const NamedSet& s2)const
{
	return Set::isSubSet(s2);
}
NamedSet NamedSet::calcUnion(const NamedSet& s2)const
{
	return Set::calcUnion(s2);
}
NamedSet NamedSet::calcSymmetricDifference(const NamedSet& ref)const
{
	//(A - B) U (B - A)
	return ((this->Set::calcDifference(ref)).Set::calcUnion(ref.calcDifference(*this)));
}
void NamedSet::print()const
{
	cout << name << " = ";
	Set::print();
}
//conversion constructor
NamedSet::NamedSet(const Set& ref)
{
	Set::operator=(ref);
	name = "X";
}