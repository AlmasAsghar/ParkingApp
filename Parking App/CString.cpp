#include "CString.h"
#include<iostream>
using namespace std;
myCString::~myCString()
{
	if (data)
	{
		delete[]data;
		size = 0;
	}
	data = nullptr;
}
myCString::myCString(myCString && ref)
{
	size = ref.size;
	data = ref.data;
	ref.data = nullptr;
	ref.size = 0;
}
myCString & myCString::operator=(myCString && ref)
{
	if (this != &ref)
	{
		delete[] data;
		size = ref.size;
		data = ref.data;
		ref.data = nullptr;
		ref.size = 0;
	}
	return *this;
}
myCString::myCString()
{
	data = nullptr;
	size = 0;
}
myCString::myCString(const char c)
{
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
	size = 2;
}
myCString myCString::operator=(const myCString & obj)
{
	if (obj.data != nullptr)
	{
		data = new char[obj.size];
		size = obj.size;
		int i = 0;
		while (obj.data[i] != '\0')
		{
			data[i] = obj.data[i];
			i++;
		}
		data[i] = '\0';
	}
	else
	{
		data = nullptr;
		size = 0;
	}
	return *this;
}
bool myCString::operator==(const myCString & ref)
{
	if (this->data == ref.data)
		return true;
	else
		return false;
}
myCString::myCString(const myCString & obj)
{
	if (obj.data != nullptr)
	{
		data = new char[obj.size];
		size = obj.size;
		int i = 0;
		while (obj.data[i] != '\0')
		{
			data[i] = obj.data[i];
			i++;
		}
		data[i] = '\0';
	}
	else
	{
		data = nullptr;
		size = 0;
	}
}
myCString::myCString(const char *c)
{
	size = getStringLength(c) + 1;
	data = new char[size];
	int i = 0;
	while (c[i] != '\0')
	{
		data[i] = c[i];
		i++;
	}
	data[i] = '\0';
}
void myCString::input()
{
	this->~myCString();
	data = new char[1];
	data[0] = '\0';
	size = 1;
	char ch;
	int count = 0;
	cin.get(ch);
	while (ch != '\n')// && !cin.eof())
	{
		operator[](count) = ch;
		if (count + 1 == size)
			reSize(size * 2);
		cin.get(ch);
		count++;
	}
	data[count] = '\0';
}
char & myCString::operator [](int index)
{
	return data[index];
}
const char & myCString:: operator [] (const int index) const
{
	return data[index];
}
int myCString::getLength() const
{
	int i = 0;
	while (data[i] != '\0')
	{
		i++;
	}
	return i;
}
void myCString::display()const
{
	if (data)
	{
		cout << data;
	}
}
void myCString::reSize(int n)
{
	int l = getLength();
	if (n <= 0)
	{
		data = nullptr;
		size = 0;
		return;
	}
	myCString s;
	s.data = new char[n];
	memcpy(s.data, data, size * sizeof(char));
	this->~myCString();
	data = new char[n];
	memcpy(data, s.data, n * sizeof(char));
	data[l] = '\0';
	size = n;

}
void myCString::strCopy(myCString des, myCString source)const
{
	int i = 0;
	while (source[i] != '\0')
	{
		des[i] = source[i];
		i++;
	}
	des[i] = '\0';
}
int myCString::getStringLength(const char*s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
int myCString::find(myCString subStr, int start)const
{
	int i = start;
	int j = 0;
	while (data[i] != '\0')
	{
		if (subStr.data[j] == data[i])
		{
			if (subStr.data[j + 1] == '\0')
			{

				return i - (subStr.getLength() - 1);
			}
			j++;
		}
		else
		{
			j = 0;
		}
		i++;
	}
	return -1;
}
void myCString::concatEqual(myCString s2)
{
	int l = getLength();
	reSize(size + s2.getLength() + 2);
	size = size + s2.getLength() + 2;
	data[getLength()] = ' ';
	int i = 0;
	while (s2.data[i] != '\0')
	{
		data[l + i + 1] = s2.data[i];
		i++;
	}
	data[l + i + 1] = '\0';

}