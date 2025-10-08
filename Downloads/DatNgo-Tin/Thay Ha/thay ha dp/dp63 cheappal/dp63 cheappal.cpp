#include <bits/stdc++.h>
using namespace std;

long n, m;
string inp;
long long res[2001][2001], costchar[27];


int main()
{
	cin >> n >> m;
	cin >> inp;
	inp = ' ' + inp;
	for (int i = 1; i <= n; ++i)
	{
		char chartemp;
		long inscost, delcost;
		cin >> chartemp >> inscost >> delcost;
		costchar[chartemp] = min(inscost, delcost);
	}

	for (int l = m - 1; l >= 1; --l)
		for (int r = l + 1; r <= m; ++r)
		{
			res[l][r] = INT_MAX;
			if (inp[l] == inp[r])
			{
				res[l][r] = min(res[l + 1][r] + costchar[inp[l]], min(res[l][r - 1] + costchar[inp[r]], res[l + 1][r - 1]));
			}
			else
				res[l][r] = min(res[l + 1][r] + costchar[inp[l]], res[l][r - 1] + costchar[inp[r]]);
		}

	cout << res[1][m];
	return 0;
}