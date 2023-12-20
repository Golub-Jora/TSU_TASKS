#pragma once
#include <iostream>
using namespace std;
//����������� ����������� ���������

class Array
{
	int* a, n;

	void ShiftLeft(int pos);		//����� �����, ������� � ������� pos+1, 
	//�������������� �����!

public:
	Array();
	Array(int);
	//������ Array() � Array(int) ����� ������� ����
	//����������� � ���������� �� ���������:
	//Array(int m=1);
	Array(int* b, int m);		//m -����� ��-��� � ������� b

	Array(const Array&);
	Array& operator= (const Array&);
	~Array();

	void Scan(int m);  			//���� ������� �� m ��-��� � ����������
	void Print();      			//����� ������� �� �������

	int& operator [] (int);
	int FindKey(int);  			//����� ��-�� � �������. ���������� ������ 
	//��-�� ��� -1, ���� ��-� � ������� �����������


	Array& operator+= (int);	 	//��������� ��-� � ����� ������� *this
	Array  operator+ (int key);		//������� ����� ������ b=*this+key

	Array& operator+= (Array X);	//��������� ������ X � ����� ������� *this
	Array  operator+ (Array X);		//������� ����� ������ b=*this+X

	Array& operator-= (int);		//������� ��-� �� ������� *this
	Array  operator- (int key);		//������� ����� ������ ��� ��-�� key

	Array& DelPosEq(int);			//�������� ��-�� � �������� �������
	//������� *this
	Array DelPosNew(int);			//������� ����� ������, ������ ��-�
	//� �������� ������� ������� *this

	bool operator== (Array);
	bool operator!= (Array);

	int Max(); 					//���������� ������ max ��������
	int Min(); 					//���������� ������ min ��������
	void Sorting();  				//���������� �������

	friend ostream& operator<< (ostream& r, Array& X);
	friend istream& operator>> (istream& r, Array& X);

	int GetN() { return n; }
	operator int();    				//����� �� �������, ���� ���� ����� GetN
};
