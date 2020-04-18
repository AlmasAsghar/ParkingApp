#ifndef myCString_H       
#define  myCString_H
class myCString
{
	char * data;
	int size;

public:
	~myCString();
	myCString();
	myCString(const char c);
	myCString(const char *c);
	myCString(const myCString & obj);
	myCString operator=(const myCString & obj);
	myCString(myCString && ref);
	myCString & operator=(myCString && ref);
	bool operator==(const myCString & ref);
	void input();
	void reSize(int n);
	int getLength()const;
	void display()const;
	char & operator [](int index);
	int find(myCString subStr, int start = 0)const;//find the first occurence's index
	void concatEqual(myCString c2);
	const char & operator [] (const int index) const;
	int getStringLength(const char*s);
	void strCopy(myCString des, myCString source)const;
};

#endif



