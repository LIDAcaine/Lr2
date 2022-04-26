typedef struct Unit
{
	int data;
	Unit* next;
} Unit; //������� �����

class Stack
{
private:
	Unit* top = 0; //��������� �� ��������� ������� ����� - ������������������ �������
	int size = 0; //������ �����
public:
	Stack(); //����������� ��� ����������
	explicit Stack(int size_st); //����������� � �����������
	~Stack(); //����������
	Stack(const Stack& Stack_copy); //����������� �����������

	void push(int value); //���������� �������� � ����
	int pop(); //���������� �������
	void print(); //����� ����� �� �����

	Unit* get_top(); //����� ������� �����
	void set_size(int& value); //��������� �������� � ����
	int get_size() const; //����� ������ ����� 

	friend void operator+ (int, Stack& St);
	friend void operator+ (Stack& St, int);
	friend void operator+= (int, Stack & St);
	friend void operator+= (Stack& St, int);
	friend void operator-(int, Stack& St);
	friend void operator- (Stack& St, int);
	friend void operator-=(int, Stack& St); 
	friend void operator-= (Stack& St, int);
	friend void operator*(int, Stack& St); 
	friend void operator* (Stack& St, int);
	friend void operator*=(int, Stack& St); 
	friend void operator*= (Stack& St, int);
	friend void operator/(int, Stack& St); 
	friend void operator/ (Stack& St, int);
	friend void operator/=(int, Stack& St);
	friend void operator/= (Stack& St, int);
	/*Stack& operator+(int);
	Stack& operator+=(int);
	Stack& operator-(int);
	Stack& operator-=(int);
	Stack& operator*(int);
	Stack& operator*=(int);
	Stack& operator/(int);
	Stack& operator/=(int);*/
};
