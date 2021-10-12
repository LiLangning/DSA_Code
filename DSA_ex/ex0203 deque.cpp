#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> a;
	int t, n, typ, num;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> typ >> num;
			if (typ == 1)
				a.push_back(num);
			if (typ == 2)
			{
				if (num == 0)
					a.pop_front();
				if (num == 1)
					a.pop_back();
			}
		}
		if (a.empty())
			cout << "NULL" << endl;
		else
		{
			int len = a.size();
			for (int k = 0; k < len - 1; k++)
			{
				num = a.front();
				a.pop_front();
				cout << num << " ";
			}
			num = a.front();
			a.pop_front();
			cout << num << endl;
		}
	}
}