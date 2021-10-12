#include<iostream>
using namespace std;

template<class T>
class Stack {
public:
	void clear();
	bool push(const T item);
	bool pop(T& item);
	bool top(T& item);
	bool isEmpty();
	bool isFull();
};

template <class T>
class arrStack:public Stack<T> {
private:
	int mSize;
	int mtop;
	T* st;
public:
	arrStack(int size) {
		mSize = size;
		mtop = -1;
		st = new T[mSize];
	};
	arrStack(){
		mtop = -1;
	};
	~arrStack(){
		delete[] st;
	};
	void clear();
	bool push(const T item);
	bool pop(T& item);
	bool top(T& item);
	bool isEmpty();
	bool isFull();

};

template<class T>
bool arrStack<T>::push(const T item) {
	if (mtop == mSize - 1) {
		cout << "栈满溢出" << endl;
		return false;
	}
	else {
		st[++mtop] = item;
		return true;
	}
}

template<class T>
bool arrStack<T>::pop(T& item) {
	if (mtop == -1) {
		cout << "栈为空,不能执行出栈操作" << endl;
		return false;
	}
	else {
		item = st[mtop--];
		return true;
	}
}

template<class T>
bool arrStack<T>::top(T& item) {
	if (mtop == -1) {
		cout << "栈为空,不能读取栈顶元素" << endl;
		return false;
	}
	else {
		item = st[mtop];
		return true;
	}
}

template<class T>
void arrStack<T>::clear() {
	mtop = -1;
}

template<class T>
bool arrStack<T> :: isFull() {
	return (mtop == mSize - 1);
}

int main() {
	arrStack<int> a(5);
	int x ;
	a.pop(x);
	a.push(5);
	a.pop(x);
	return 0;
}