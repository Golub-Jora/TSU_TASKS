#include "Cstr.h"
#include <cstdlib>
#include <ctime>

// ��������� ����� ��� ��������� ��������� ������ �������� �����
char* CStr::generate(int length)
{
    //srand(time(0));
    char* result = new char[length + 1];
    for (int i = 0; i < length; ++i)
    {
        result[i] = 'a' + rand() % 26; // ��������� ��������� �������� �����
    }
    result[length] = '\0'; // ��������� �������� ������� � ����� ������
    return result;
}

// ����������� �� ���������
CStr::CStr()
{
    //srand(time(0));
    //srand(static_cast<unsigned int>(time(nullptr))); // ������������� ���������� ��������� �����
    int length = rand() % 20 + 1; // ��������� ��������� ����� �� 1 �� 20
    string = generate(length);
}

// ����������� � ���������� "������"
CStr::CStr(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        ++length;
    }
    string = new char[length + 1];
    for (int i = 0; i <= length; ++i)
    {
        string[i] = str[i];
    }
}

// ����������� � ���������� "����� ������"
CStr::CStr(int length)
{
    string = generate(length);
}

// ����������� �����
CStr::CStr(const CStr& obj)
{
    int length = obj.get_length();
    string = new char[length + 1];
    for (int i = 0; i <= length; ++i)
    {
        string[i] = obj.string[i];
    }
}

// ����������
CStr::~CStr()
{
    delete[] string;
}

// �������� ������������ ������� CStr
CStr& CStr::operator=(CStr& obj)
{
    if (this != &obj)
    {
        delete[] string;
        int length = obj.get_length();
        string = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            string[i] = obj.string[i];
        }
    }
    return *this;
}

// �������� ������������ ������ (char *)
CStr& CStr::operator=(const char* str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        ++length;
    }
    delete[] string;
    string = new char[length + 1];
    for (int i = 0; i <= length; ++i)
    {
        string[i] = str[i];
    }
    return *this;
}

CStr& CStr::operator=(const CStr& obj)
{
    if (this != &obj)
    {
        delete[] string;
        int length = obj.get_length();
        string = new char[length + 1];
        for (int i = 0; i <= length; ++i)
        {
            string[i] = obj.string[i];
        }
    }
    return *this;
}

// �������� ��������� > (��� <) �������� CStr �� �� ����������� (��������� �����)
bool CStr::operator>(CStr& obj)
{
    return strcmp(string, obj.string) > 0;
}

// �������� �������� ��������� (==) �������� CStr (��������� �����)
bool CStr::operator==(CStr& obj)
{
    return strcmp(string, obj.string) == 0;
}

bool CStr::operator==(const CStr& obj) const
{
    return strcmp(string, obj.string) == 0;
}

bool CStr::operator<(const CStr& obj) const
{
    return strcmp(string, obj.string) < 0;
}

// �����, ������������ ����� ������
int CStr::get_length() const
{
    int length = 0;
    while (string[length] != '\0')
    {
        ++length;
    }
    return length;
}

// ������������� �������� ������ � ����� <<
ostream& operator<<(ostream& stream, CStr& obj)
{
    stream << obj.string;
    return stream;
}
