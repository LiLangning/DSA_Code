#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int mysort(int *num, int len)
{
	int repeat = 0;
	for (int i = 0; i < len; i=i+2)
	{
		for (int j = i + 2; j < len; j = j + 2)
			if (num[j + 1] > num[i + 1])
			{
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
				temp = num[i + 1];
				num[i + 1] = num[j + 1];
				num[j + 1] = temp;
			}
			else if (num[j + 1] == num[i + 1]&&num[j+1]>=0)
			{
				num[i] += num[j];
				num[j + 1] = -1;
				repeat += 1;
			}
	}
	return repeat;
}
int main()
{
	int n, num1[305], num2[305], m1, m2, count1, count2,ansnum[605],ansm;
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
		//ÊäÈë
		m1=m1-mysort(num1, m1)*2;
		m2 = m2 - mysort(num2, m2) * 2; 
		// ÅÅĞò

		// ¼Ó·¨
		ansm = 0;
		count1 = 0;
		count2 = 0;
		while (1)
		{
			if (num1[count1 + 1] > num2[count2 + 1])
			{
				if (num1[count1] == 0)
				{
					count1 += 2;
					continue;
				}
				ansnum[ansm] = num1[count1];
				ansnum[ansm + 1] = num1[count1 + 1];
				ansm += 2;
				//cout << "[ " << num1[count1] << " " << num1[count1 + 1] << " ] ";
				count1 += 2;
			}
			else if (num1[count1 + 1] < num2[count2 + 1])
			{
				if (num2[count2] == 0)
				{
					count2 += 2;
					continue;
				}
				ansnum[ansm] = num2[count2];
				ansnum[ansm+1] = num2[count2 + 1];
				ansm += 2;
				//cout << "[ " << num2[count2] << " " << num2[count2+1] << " ] ";
				count2 += 2;
			}
			else if (num1[count1 + 1] == num2[count2 + 1])
			{
				if (num1[count1] + num2[count2] != 0)
				{
					ansnum[ansm] = num1[count1] + num2[count2];
					ansnum[ansm+1] = num1[count1 + 1];
					ansm += 2;
				}
					//cout << "[ " << num1[count1]+num2[count2] << " " << num1[count1+1] << " ] ";
				count1 += 2;
				count2 += 2;
			}
			if (count1 == m1 || count2 == m2)
				break;
		}
		while(count1 < m1)
		{
			if (num1[count1] == 0)
			{
				count1 += 2;
				continue;
			}

			ansnum[ansm] = num1[count1];
			ansnum[ansm + 1] = num1[count1 + 1];
			ansm += 2;
			//cout << "[ " << num1[count1] << " " << num1[count1 + 1] << " ] ";
			count1 += 2;
		}
		while(count2<m2)
		{
			if (num2[count2] == 0)
			{
				count2 += 2;
				continue;
			}
			ansnum[ansm] = num2[count2];
			ansnum[ansm+1] = num2[count2 + 1];
			ansm += 2;
			//cout << "[ " << num2[count2] << " " << num2[count2 + 1] << " ] ";
			count2 += 2;
		}
		for (int j = 0; j < ansm - 2; j += 2)
			cout << "[ " << ansnum[j] << " " << ansnum[j + 1] << " ] ";
		cout << "[ " << ansnum[ansm - 2] << " " << ansnum[ansm - 1] << " ]"<<endl;
	}
	return 0;
}
