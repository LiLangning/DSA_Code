#include<iostream>
using namespace std;

int main()
{
	int N, M, sum, check, num[100001], val;
	char op;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < M; i++)
	{
		cin >> op;
		cin >> val;
		if (op == 'C')
		{
			for (int j = 0; j < N; j++)
				num[j] = (num[j] + val) % 65536;
		}
		if (op == 'Q')
		{
			sum = 0;
			for (int j = 0; j < N; j++)
			{
				check = num[j] >> val;
				if (check % 2 == 1)
					sum++;
			}
			cout << sum << endl;
		}	
	}
	return 0;
}