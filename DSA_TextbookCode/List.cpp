#include<iostream>
using namespace std;

template<class T>
class List {
	void clear();
	bool isEmpty();
	bool append(const T value);
	bool insert(const int p, const T value);
	bool remove(const int p);
	bool getPos(int& p, const T value);
	bool getValue(const int p, T& value);
	bool setValue(const int p, const T value);
};

template<class T>
class arrList:public List<T>{
private:
	T* aList;
	int maxSize;
	int curLen;
	int position;
public:
	arrList(const int size){
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}
	~arrList(){
		delete[]aList;
	}
	void clear() {
		delete[]aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}
	int length();
	bool append(const T value);
	bool insert(const int p,const T value);
	bool remove(const int p);
	bool setValue(const int p, const T value);
	bool getValue(const int p, T& value);
	bool getPos(int& p, const T value);
};
template<class T>
bool arrList<T>::getPos(int& p, const T value) {
		for (int i = 0; i < curLen; i++)
		if (value == aList[i]){
			p = i;
			return true;
		}
	return false;
}
template<class T>
bool arrList<T>::insert(const int p, const T value) {
	int i;
	if (curLen >= maxSize) {
		cout << "The list is overflow" << endl;
		return false;
	}
	if (p<0 || p>curLen) {
		cout << "Insertion point is illegal" << endl;
		return false;
	}
	for (i = curLen; i > p; i--)
		aList[i] = aList[i - 1];
	aList[p] = value;
	curLen++;
	return true;
}
template<class T>
bool arrList<T>::remove(const int p) {
	int i;
	if (curLen <= 0) {
		cout << "No element to delete" << endl;
		return false;
	}
	if (p<0 || p>curLen - 1) {
		cout << "deletion is illegal" << endl;
		return false;
	}
	for (i = p; i < curLen - 1; i++)
		aList[i] = aList[i + 1];
	curLen--;
	return true;
}
template<class T>
bool arrList<T>::setValue(const int p, const T value) {
	aList[p] = value;
	return true;
}

template<class T> class Link {
public:
	T data;
	Link<T>* next;
	Link(const T info, const Link<T>* nextValue = NULL) {
		data = info;
		next = nextValue;
	}
	Link(const Link<T>* nextValue) {
		next = nextValue;
	}
};

template<class T>class lnkList :public List<T> {
private:
	Link<T>* head, * tail;
	Link<T>* setPost(const int p);
public:
	lnkList(int s);
	~lnkList();
	bool isEmpty();
	void clear();
	int length();
	bool append(const T value);
	bool insert(const int p, const T value);
	bool remove(const int p);
	bool getValue(const int p, T& value);
	bool getPos(int& p, const T value);
};

template<class T>
Link<T>* lnkList<T>::setPost(int i) {
	int count = 0;
	if (i == -1)
		return head;
	Link<T>* p = new Link<T>(head->next);
	while (p != NULL && count < i) {
		p = p->next;
		count++;
	}
	return p;
}
template<class T>
int lnkList<T>::length() {
	Link<T>* p = head->next;
	int count = 0;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count;
}

int main() {
	arrList<int> a(5);
	for (int i = 0; i < 5; i++)
		a.setValue(i, i+1);
	a.remove(3);
	return 0;
}