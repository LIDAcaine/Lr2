#include "MyLong.h"

myLong::myLong(long a) //����������� � ����������
{
	value = new long(a);
}
myLong::myLong() //����������� ��� ��������� 
{
	value = new long(0);
}
myLong::myLong(const myLong& _long) //�����������
{
	value = new long(*_long.value);
}
myLong::~myLong() //����������
{
	delete value;
}

myLong& myLong::operator --()
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "������� �������� �������� ��� ����������� ���������: ";
	cin >> a;
	*value -= a;
	return *this;
}
myLong& myLong::operator --(int)
{
	--* value;
	return *this;
}
long myLong::operator !() const
{
	return -*value;
}
myLong& operator ++(myLong& op)
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "������� �������� ��� ����������� �����������: ";
	cin >> a;
	*op.value += a;
	return op;
}
myLong& operator ++(myLong& op, int)
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "������� ����������� ��������: ";
	cin >> a;
	*op.value = a;
	++* op.value;
	return op;
}
ostream& operator <<(ostream& stream, myLong& a)
{
	stream << *a.value;
	return stream;
}