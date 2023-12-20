#include "array.h"

Array::Array()
{
    a = new int[1]; n = 1;
}

Array::Array(int N)
{
    a = new int[N]; n = N;
}

//������ Array() � Array(int) ����� ������� ����
//����������� � ���������� �� ���������.
//��� ���������� � ������: Array(int m=1);
//��� �����������:
//Array::Array(int m)
//  {a=new int[m]; n=m;}

Array::Array(int* b, int m)		//m -����� ��-��� � ������� b
{
    a = new int[m];
    for (int i = 0; i < m; i++)
        a[i] = b[i];
    n = m;
}


Array::Array(const Array& X)
{
    n = X.n;
        a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = X.a[i];
}

int Array::FindKey(int key) // ����� �������� key � �������
{
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1; // ���������� -1, ���� ������� key �� ������
}


Array& Array::operator= (const Array& X)
{
    if (this != &X)
    {
        delete[]a;
        n = X.n;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = X.a[i];
    }
    return *this;
}

Array::~Array()
{
    delete[]a;
}


void Array::Scan(int m)			//���� ������� �� m ��-��� � ����������
{
    cout << "enter " << m << " elements: ";
    if (n != m)
    {
        delete[]a;   n = m;
        a = new int[m];
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void Array::Print()     			 //����� ������� �� �������
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

int& Array::operator[] (int i)			//���������� i-�� ��-�� ������� a
{
    if (i < 0) {
        cout << "incorrect index: i<0" << endl;
        return a[0];
    }
    if (i > n) {
        cout << "incorrect index: i>n" << endl;
        return a[n - 1];
    }
    return a[i];
}


Array& Array::operator+= (int key)	 //��������� ��-� � ����� ������� *this
{
    int i, * t;
    t = new int[n + 1];
    for (i = 0; i < n; i++)  t[i] = a[i];
    t[n] = key;
    delete[]a;
    a = t;   n++;
    return *this;
}

Array Array::operator+(Array X)
{
	Array Res(n + X.n);
	for (int i = 0; i < n; i++)
		Res.a[i] = a[i];
	for (int i = 0; i < X.n; i++)
		Res.a[n + i] = X.a[i];
	return Res;
}



Array& Array::operator-= (int key) // �������� �������� � ������������ ������
{
    int index = FindKey(key); // ������� ������ �������� � ������ key
    if (index != -1) {
        int* t = new int[n - 1];
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i != index) {
                t[j] = a[i];
                j++;
            }
        }
        delete[] a;
        a = t;
        n--;
    }
    return *this;
}

Array Array::operator-(int key)
{
	Array Res(n);
	for (int i = 0; i < n; i++) {
		if (a[i] != key)
			Res.a[i] = a[i];
	}
	return Res;
}


Array& Array::DelPosEq(int m)            //�������� ��-�� � �������� �������
{
    for (long i = m; i < n; ++i)
    {
        a[i] = a[i + 1];
    }
    --n;
    return *this;
}

bool Array::operator==(Array b)
{
	if (n != b.n) return false;
	for (int i = 0; i < n; i++)
		if (a[i] != b.a[i])
			return false;
	return true;
}

bool Array::operator!=(Array b)
{
	return!(*this == b);
}

int Array::Max()
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int Array::Min()
{
	int min = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

void Array::Sorting()
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}



ostream& operator<<(ostream& r, Array& X)
{
	X.Print();
	return r;
}

istream& operator>> (istream& r, Array& X)
{
    cout << "enter the number of elements: ";
    int m;    cin >> m;
    if (X.n != m)
    {
        delete[]X.a;
        X.a = new int[m];  X.n = m;
    }
    cout << "enter " << m << " elements of array: ";
    for (int i = 0; i < X.n; i++) r >> X[i];
    return r;
}


Array::operator int()
{
    return n;
}

