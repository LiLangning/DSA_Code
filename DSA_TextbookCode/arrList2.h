#ifndef __arrList_H
#define __arrList_H

#include<iostream>
#include<string>

using namespace std;

template<class T>
class arrList : public List<T>
{
private:
	T* aList;
	int maxSize;
	int curLen;
	int position;
public:
	arrList(const int size)
	{
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}
	~arrList()
	{
		delete[]aList;
	}
	void clear() {
		delete[]aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}
	int length();
	bool append(const T value);
	bool insert(const int p);
	bool delete(const int p);
	bool setValue(const int p, const T value);
	bool getValue(const int p, T& value);
	bool getPos(int& p, const T value);
};


#endif
