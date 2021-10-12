#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n, a[11],c[11];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		//a[i] = i+1;
		long long k = 1, sumk = 0, firstnum, lastnum = 0, knumsum,knum;
		while (1)
		{
			knum = pow(10.0, k) - pow(10.0, k - 1);
			firstnum = lastnum+k;
			lastnum = lastnum + k*knum;
			
			knumsum = (firstnum + lastnum) * knum /2;
			if (a[i] <= sumk + knumsum)
				break;
			sumk += knumsum;
			k++;
		}
		// 获得目标位数k

		int thenum, le = a[i] - sumk, currentnum = firstnum;
		for (thenum = 1; thenum <= knum; thenum++)
		{
			if (le <= currentnum)
				break;
			le = le - currentnum;
			currentnum += k;
		}
		if (thenum == knum + 1)
			thenum -= 1;
		// 获得是第k位数的第thenum个数字ans 从112...123..ans中的第le个
		// 确定位数
		int ans = thenum + pow(10.0, k - 1) - 1;
		int k2 = 1,k2numsum=0;
		
		lastnum = 0;
		while (1)
		{
			knum = pow(10.0, k2) - pow(10.0, k2-1);
			lastnum = lastnum + k2 * knum;
			if (le <= lastnum)
				break;
			k2++;
		}
		// 得到位数为k2
		lastnum = 0;
		if (k2 == 1)
			lastnum = 0;
		else
		{
			for (int j = 1; j <= k2 - 1; j++)
			{
				knum = pow(10.0, j) - pow(10.0, j - 1);
				lastnum = lastnum + j * knum ;
			}

		}
		le -= lastnum;
		int ansnum = (le+k2-1) / k2 + pow(10.0,k2-1) - 1;
		string s;
		s = to_string(ansnum);
		if (le % k2 == 0)
			cout << s[k2 - 1] - '0'<<endl;
		else
			cout << s[le % k2-1] - '0' <<endl;
		
	}


	return 0;
}