#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<char> s;
	char c;
	while (cin >> c)
	{
		if(c=='('||c=='['||c=='{')
			s.push(c);
		if (c == ')')
		{
			if (s.empty()||s.top()!='(')
			{
				cout << "No";
				return 0;
			}
			else
				s.pop();
		}
		if (c == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				cout << "No";
				return 0;
			}
			else
				s.pop();
		}
		if (c == '}')
		{
			if (s.empty() || s.top() != '{')
			{
				cout << "No";
				return 0;
			}
			else
				s.pop();
		}
	}
	if (!s.empty())
		cout << "No";
	else
		cout << "Yes";
	return 0;
}
