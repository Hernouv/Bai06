#include <bits/stdc++.h>
using namespace std;

int n, m, iter;
vector<int> primelist, exp_m, exp_n;

void factorization(int inp)
{
	iter = 0;
	for (int i = 2; i * i <= inp; ++i)
	{
		if (inp % i == 0)
		{
			primelist.push_back(i);
			exp_m.push_back(0);
			while (inp % i == 0)
			{
				exp_m[iter]++;
				inp /= i;
			}
			iter++;
		}
	}

	if (inp > 1)
	{
		primelist.push_back(inp);
		exp_m.push_back(1);
		iter++;
	}
}

void primecount(int inp, int prime)
{
	int ans = 0;
	while (inp) ans += (inp /= prime);
	exp_n.push_back(ans);
}

int main()
{
	freopen("exp.inp", "r", stdin);
	freopen("exp.out", "w", stdout);
	cin >> n >> m;
	factorization(m);
	for (auto x : primelist)
		primecount(n, x);
	int res = INT_MAX;
	for (int i = 0; i < iter; ++i)
		res = min(res, exp_n[i] / exp_m[i]);
	cout << res;
	return 0;
}