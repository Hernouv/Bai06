#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull inp;
set<ull> res;

int main()
{
	freopen("divisors.inp", "r", stdin);
	freopen("divisors.out", "w", stdout);
	cin >> inp;
	for (ull i = 1; i <= trunc(sqrt(inp)); ++i)
	{
		if (inp % i == 0)
		{
			res.insert(i);
			res.insert(inp / i);
		}
	}

	for (auto x : res)
		cout << x << endl;

	return 0;
}