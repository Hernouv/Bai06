#include <bits/stdc++.h>
using namespace std;

int n, time_increase[2501], res[2501];

int main()
{	
	cin >> n >> time_increase[0];
	for (int i = 1; i <= n; ++i)
	{
		int temp;
		cin >> temp;
		time_increase[i] = time_increase[i - 1] + temp;
	}

	for (int i = 1; i <= n; ++i)
	{
		res[i] = time_increase[i];
		for (int j = 1; j < i; ++j)
			res[i] = min(res[i], time_increase[j] + time_increase[0] + res[i - j]);
	}
	cout << res[n];
	return 0;
}