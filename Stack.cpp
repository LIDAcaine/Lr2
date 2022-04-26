#include "Stack.h"
#include <iostream>
#include <locale>

using namespace std;

Stack::Stack() //����������� ��� ���������� 
{
	top = 0;
	size = 0;
} 
Stack::Stack(int size_st) //����������� � ����������
{
	top = 0;
	this->size = size_st; //���������� ������� ������������� ������
}
Stack::~Stack() //����������
{
	if ((top == 0) || (size == 0))
	{
		delete top; //������� �������
		size = 0; //������ �������
	}
	else
	{
		while (top->next != 0) //���� �� ������ �� �������� ���������
		{
			Unit* temp = top; //��������� ���������� �����, ����������� �� �������� �������
			top = temp->next; //������ ������� ��������� �� ��������� �� ��� �������,
			delete temp; //� ��������� - ��������
		}
		delete top; //������� �������
		size = 0; //������ �������
	}
}
Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size) //�����������
{
	int* buff = new int[Stack_copy.size]; //������ �������� ������, � ������� ����� ������� ���� ����� ������ �����
	Unit* el_stack = Stack_copy.top; //����� ����������-������� �������� �����

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//���� ������� �� ������ �� ����� �����
		buff[i] = el_stack->data; //������� � ������ �������� �� �����
		el_stack = el_stack->next; //������ ��������� �� ��������� ������� �����
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //������ � ����� ���� �������� �� �������

	delete[] buff; //������� �����
}

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //�������������� ����� ���� ����� � �������� ��� ���� ������
	new_unit->next = top; //������ ����� ���� ���� ��������
	top = new_unit; //� ������� ��������� �� ����� ����
	top->data = value; //������ �������� � �������
	size++;
}
int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "���� ����, ������� ������." << endl;
	}

	Unit* temp = top; //��������� ����������-������� 
	int deldata = 0; //����� ��� ��������� �������

	deldata = top->data; //����������� �������� ���������� ��������
	top = top->next; //������� ������ ��� ����, ������� ��� ��� ��������
	delete temp; //������� ����������-�������
	size--;
	return deldata; //������� ��������� �������
}
void Stack::print()
{
	if (size == 0)
	{
		cout << "���� ����, �������� ������." << endl;
	}
	else
	{
		Unit* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Unit* Stack::get_top()
{
	return top;
}
int Stack::get_size() const
{
	return size;
}
void Stack::set_size(int& value)
{
	size = value;
}

void operator+ (int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(a+buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����

	delete[] buff;
}
void operator+ (Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i]+a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����

	delete[] buff;
}
void operator += (int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}

	delete[] buff;
}
void operator += (Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}

	delete[] buff;
}
void operator -(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] - a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator -(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] - a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator -=(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
void operator -=(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
void operator *(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] * a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator *(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] * a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator *=(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
void operator *=(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
void operator /(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] / a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator /(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] / a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	delete[] buff;
}
void operator /=(int a, Stack& St)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
void operator /=(Stack& St, int a)
{
	int len = St.size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		St.push(buff[i]); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����
	}
	delete[] buff;
}
/*Stack& Stack::operator+(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
		this->push(buff[i] + a); //� �������� ������� (��� ���� �� ��������������) ������� ����� �������� � ����

	delete[] buff;
	return *this;
}
Stack& Stack::operator+=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator-(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] - a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator-=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator*(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] * a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator*=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator/(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] / a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator/=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //���������� ������� ���������� �������
	int* buff = new int[len]; //�������� ������, ���� ������� �������� �����
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //������ � ������ �������� �����, ���� �� ����� ���������� ������
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}*/