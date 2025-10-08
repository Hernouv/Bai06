#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull inp;
set<ull> res;

int main()
{
	freopen("divisum.inp", "r", stdin);
	freopen("divisum.out", "w", stdout);
	cin >> inp;
	for (ull i = 1; i <= trunc(sqrt(inp)); ++i)
	{
		if (inp % i == 0)
		{
			res.insert(i);
			res.insert(inp / i);
		}
	}

	ull sum = 0;
	for (auto x : res)
		sum += x;

	cout << sum;
	return 0;
}