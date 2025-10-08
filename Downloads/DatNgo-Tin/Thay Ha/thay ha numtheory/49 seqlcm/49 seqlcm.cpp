#include <bits/stdc++.h>
using namespace std;

#define u unsigned long long
unordered_map<int, int> factor;

int eratosthenes[1000001];
int mod;
int in;

void sieve()
{
	for (int i = 2; i < 1000001; ++i)
		eratosthenes[i] = i;

	for (int i = 2; i < 1001; ++i)
		if (eratosthenes[i] == i)
			for (int j = i * i; j < 1000001; j += i)
				eratosthenes[j] = i;
}

int great(int a, int b)
{
	return (a > b ? a : b);
}

int main()
{
	freopen("seqlcm.inp", "r", stdin);
	freopen("seqlcm.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	sieve();
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{	
		cin >> in;
		while (in != 1)
		{
			int exp = 0;
			int p = eratosthenes[in];
			while (in % p == 0) exp++, in /= p;
			factor[p] = great(factor[p], pow(p, exp));
		}
	}

	cin >> mod;
	u ans = 1;
	for (auto it : factor)
		ans = ans * it.second % mod;

	cout << ans;
	return 0;
}