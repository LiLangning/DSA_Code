#include<iostream>
#include<cmath>
using namespace std;

int ex0101()
{
	int a[100005], N, M, weishu;
	char c;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> a[i];

	for (int i = 1; i <= M; i++)
	{
		cin >> c >> weishu;
		if (c == 'Q')
		{
			int count = 0;
			int num = int(pow(2.0, weishu + 1));
			int num2 = int(pow(2.0, weishu));
			for (int j = 1; j <= N; j++)
			{
				int temp = a[j] % num;
				if (temp >= num2)
					count++;
			}
			cout << count << endl;
		}
		if (c == 'C')
			for (int j = 1; j <= N; j++)
				a[j] = (a[j] + weishu) % 65536;
	}
	return 0;
}