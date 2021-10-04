#include<iostream>
using namespace std;
int findans(int k)
{
	if (k == 1 || k == 0)
		return 1;
	if (k > 1)
	{
		int sum = 0;
		if (k % 2 == 0)
		{
			for (int i = 1; i <= k / 2; i++)
				sum += findans(i - 1) * findans(k - i);
			sum *= 2;
		}
		else
		{
			for (int i = 1; i <= k / 2; i++)
				sum += findans(i - 1) * findans(k - i);
			sum *= 2;
			sum += findans(k / 2) * findans(k / 2);
		}
		
		return sum;
	}
}
int main()
{
	int n;
	cin >> n;
	printf("%d",findans(n));
	return 0;
}