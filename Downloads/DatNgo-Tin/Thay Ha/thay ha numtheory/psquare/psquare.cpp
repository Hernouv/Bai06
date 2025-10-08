#include <bits/stdc++.h>
using namespace std;

set<int> scan;
int oddcheck = 0;
bool eratosthenes[998], inodd[1000001];
vector<int> primelist;
int pg1k_fexp[1000001];
vector<pair<int, int>> pfactor[1000001];

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = false;
	for (int i = 3; i < 32; i += 2)
		if (eratosthenes[i])
			for (int j = i * i; j < 998; j += i)
				eratosthenes[j] = false;
	
	//subtask
	primelist.push_back(2);
	for (int i = 3; i < 998; i += 2)
		if (eratosthenes[i])
			primelist.push_back(i);
}

void factorization()
{
	for (int i = 0; i < 1000001; i++)
		pg1k_fexp[i] = i;

	for (auto x: primelist)
		for (int i = x; i < 1000001; i += x)
		{
			int exp = 0;
			while (pg1k_fexp[i] % x == 0)
			{
				pg1k_fexp[i] /= x;
				exp++;
			}
			if (exp) pfactor[i].emplace_back(x, exp);
		}

	for (int i = 1000; i < 999998; ++i)
		if (pg1k_fexp[i] > 1) pfactor[i].emplace_back(pg1k_fexp[i], 1);
}

int main()
{
	freopen("psquare.inp", "r", stdin);
	freopen("psquare.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	factorization();
	memset(pg1k_fexp, 0, sizeof(pg1k_fexp));
	int numcount;
	cin >> numcount;
	for (int i = 0; i < numcount; ++i)
	{
		int inp;
		cin >> inp;
		for (auto x : pfactor[inp])
		{
			int x1 = x.first, x2 = x.second;
			scan.insert(x1);
			pg1k_fexp[x1] += x2;
			if (pg1k_fexp[x1] % 2)
			{
				if (!inodd[x1])
				{
					oddcheck++;
					inodd[x1] = true;
				}
			}
			else
			{
				if (inodd[x1]) oddcheck--;
				inodd[x1] = false;
			}

		}
		if (oddcheck) cout << 0;
		else cout << 1;
	}
	return 0;
}