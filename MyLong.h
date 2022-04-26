#pragma once
#include <iostream>

using namespace std;
class myLong
{
	long* value;
public:
	explicit myLong(long a); //����������� � ����������
	myLong(); //����������� ��� ���������
	myLong(const myLong& a); //����������� �����������
	~myLong(); //����������

	myLong& operator --(int);
	myLong& operator --();
	long operator !() const;
	friend myLong& operator ++(myLong& op, int);
	friend myLong& operator ++(myLong& op);
	friend ostream& operator <<(ostream& stream, myLong& a);
};