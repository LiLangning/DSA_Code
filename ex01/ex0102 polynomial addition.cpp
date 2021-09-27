#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	int n, num1[305], num2[305],m1, m2;
	bool flag;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		m1 = 0;
		flag = true;
		while (flag)
		{
			cin >> num1[m1] >> num1[m1 + 1];
			if (num1[m1+ 1] < 0)
				flag = false;
			m1 += 2;
		}
		m1 -= 2;

		m2 = 0;
		flag = true;
		while (flag)
		{
			cin >> num2[m2] >> num2[m2 + 1];
			if (num2[m2 + 1] < 0)
				flag = false;
			m2 += 2;
		}
		m2 -= 2;

		if (m1 >= m2)
		{
			// addition
			for (int j = 0; j < m1 / 2; j++)
			{
				for (int k = 0; k < m2 / 2; k++)
				{
					if (num1[2 * j + 1] == num2[2 * k + 1])
						num1[2 * j] += num2[2 * k];
				}
			}

			// cout result
			for (int j = 0; j < m1 / 2; j++)
			{
				int maxnum=num1[1], maxindex=0;
				for (int k = 1; k < m1 / 2; k++)
				{
					if (num1[2 * k] > maxnum)
					{
						maxnum = num1[2 * k];
						maxindex = k;
					}
				}
				cout << "[ " << num1[2 * maxindex] << " " << num1[2 * maxindex + 1] << "] ";
				num1[2 * maxindex] = -1;
			}
		}

	}
	return 0;
}
