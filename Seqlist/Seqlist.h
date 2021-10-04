#define _CRT_SECURE_NO_WARNINGS 1 

#ifndef _SEQLIST_H__
#define _SEQLIST_H__

#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Seqlist
{
	template <typename T>
	friend ostream& operator<<<T>(ostream& os, const Seqlist<T>& list);//������������
public:
	Seqlist();    //���캯��
	~Seqlist();   //��������
	Seqlist(const Seqlist& list);   //��������
	Seqlist<T>& operator=(const Seqlist<T>& list);  //��ֵ���������
	T& operator[](const int index);  //[]���������
	void PushBack(T x);   //β��
	void PopBack();     //βɾ
	void PushFront(T x);  //ͷ��
	void PopFront();    //ͷɾ
	void Remove(T x);   //ɾ��ָ������
	void RemoveAll(T x);  //ɾ��˳�����ָ������������
	void Insert(int pos, T x);   //ָ��λ�ò���ָ��Ԫ��
private:
	void Reserve(int sz);
	T* _data;
	int _sz;
	int _capacity;
};
template <typename T>
void Seqlist<T>::Reserve(int sz)
{
	if (_capacity <= sz)
	{
		T* tmp = new T[sz];
		for (int i = 0; i < _sz; i++)
		{
			tmp[i] = _data[i];
		}
		delete[] _data;
		_data = tmp;
		_capacity = sz;
	}
}
template <typename T>
ostream& operator<<(ostream& os, const Seqlist<T>& list)
{
	for (int i = 0; i < list._sz; i++)
	{
		os << list._data[i] << " ";
	}
	return os;
}
template <typename T>
Seqlist<T>::Seqlist()
	:_data(new T[3]), _sz(0), _capacity(3)
{}

template <typename T>
Seqlist<T>::~Seqlist()
{
	if (_data != NULL)
	{
		delete[] _data;
		_data = NULL;
		_sz = 0;
		_capacity;
	}
}
template <typename T>
Seqlist<T>::Seqlist(const Seqlist& list)   //��������
{
	_data = new T[list._capacity];
	_sz = list._sz;
	_capacity = list._capacity;
	for (int i = 0; i < _sz; i++)
	{
		_data[i] = list._data[i];
	}

}
template <typename T>
Seqlist<T>& Seqlist<T>::operator=(const Seqlist<T>& list)
{
	_data = new T[list._capacity];
	_sz = list._sz;
	_capacity = list._capacity;
	for (int i = 0; i < _sz; i++)
	{
		_data[i] = list._data[i];
	}
	return *this;
}

template <typename T>
void Seqlist<T>::PushBack(T x)
{
	Reserve(_sz + 1);
	_data[_sz] = x;
	_sz++;
}

template <typename T>
void Seqlist<T>::PopBack()
{
	if (_sz == 0)
	{
		cout << "�����ݿ�ɾ" << endl;
		return;
	}
	else
	{
		_data[_sz - 1] = NULL;
		_sz--;
	}
}

template <typename T>
void Seqlist<T>::PushFront(T x)
{
	Reserve(_sz + 1);
	for (int i = _sz; i > 0; i--)
	{
		_data[i] = _data[i - 1];
	}
	_data[0] = x;
	_sz++;
}

template <typename T>
void Seqlist<T>::PopFront()
{
	if (_sz == 0)
	{
		cout << "�����ݿ�ɾ" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < _sz - 1; i++)
		{
			_data[i] = _data[i + 1];
		}
		_sz--;
	}
}

template <typename T>
T& Seqlist<T>::operator[](const int index)
{
	return _data[index];
}
template <typename T>
void Seqlist<T>::Remove(T x)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < _sz; i++)
	{
		if (_data[i] == x)
		{
			for (j = i; j <= _sz - 1; j++)
			{
				_data[j] = _data[j + 1];
			}
			_sz--;
		}
	}
	if (j == 0)
	{
		cout << "�޸�Ԫ��" << endl;
	}
}

template <typename T>
void Seqlist<T>::RemoveAll(T x)
{
	int i = 0;
	int j = 0;
	int count = 0;
	if (_sz == 0)
	{
		cout << "�����ݿ�ɾ" << endl;
		return;
	}

	while (i < _sz)
	{
		if (_data[i] == x)
		{
			for (j = i; j < _sz; j++)
			{
				_data[j] = _data[j + 1];
			}
			_sz--;
		}
		else
			i++;
	}
	if (j == 0)
	{
		cout << "�޸�����" << endl;
		return;
	}
}
template <typename T>
void Seqlist<T>::Insert(int pos, T x)
{
	Reserve(_sz + 1);
	if (pos == 1)
	{
		PushFront(x);
	}
	else if (pos == _sz + 1)
	{
		PushBack(x);
	}
	else
	{
		for (int i = _sz; i > pos - 1; i--)
		{
			_data[i] = _data[i - 1];

		}
		_data[pos - 1] = x;
		_sz++;
	}
}
void test1()
{
	Seqlist<int> seq;
	seq.PushBack(1);       //����β��
	seq.PushBack(2);
	seq.PushBack(3);
	seq.PushBack(4);
	cout << seq << endl;
	seq.PopBack();          //����βɾ
	cout << seq << endl;
	seq.PopBack();
	cout << seq << endl;
	seq.PopBack();
	cout << seq << endl;
	seq.Insert(1, 9);         //���Բ��뺯��
	cout << seq << endl;
	Seqlist<string> Seq;         //���Է��Զ�����������˳����ܲ��ܹ����ɹ�
	Seq.PushBack("hello");
	Seq.PushBack(" ");
	Seq.PushBack("world");
	cout << Seq << endl;
}

void test2()
{
	Seqlist<int> seq;
	seq.PushFront(1);   //����ͷ��
	seq.PushFront(2);
	seq.PushFront(3);
	seq.PushFront(2);
	seq.PushFront(2);
	seq.PushFront(4);
	cout << seq << endl;
	//seq.Remove(2);            //����ɾ������
	//seq.RemoveAll(2);            //����ɾ��˳����г��ֵ�����ĳ�����ݳ�Ա����
	cout << seq << endl;
	/*cout << seq << endl;
	seq.PopFront();                //����ͷɾ
	cout << seq << endl;
	seq.PopFront();
	cout << seq << endl;
	seq.PopFront();
	cout << seq << endl;
	seq.PopFront();
	cout << seq << endl;*/

	Seqlist<string> seq1;
	seq1.PushFront("hello");
	seq1.PushFront("hello");
	seq1.PushFront("askhashglaksdfsdfasdfsdfdga");
	seq1[2] = "bit";
	cout << seq1 << endl;
	seq1.PopFront();
	cout << seq1 << endl;
	seq1.PopFront();
	cout << seq1 << endl;
	seq1.PopFront();
	cout << seq1 << endl;
	Seqlist<string> seq2(seq1);  //���Կ�������
	cout << seq2 << endl;
	Seqlist<string> seq3 = seq2;  //���Ը�ֵ���������
	cout << seq3 << endl;
}
#endif