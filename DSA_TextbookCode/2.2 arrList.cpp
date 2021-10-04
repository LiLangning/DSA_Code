#include "arrLish2.h"

using namespace std;


template <class T>
bool arrList<T> ::getPos(int& p, const T value) {
	int i;
	for (i =0;i<n;i++)
		if (value == aList[i])
		{
			p = i;
			return true;
		}
	return false;
}
