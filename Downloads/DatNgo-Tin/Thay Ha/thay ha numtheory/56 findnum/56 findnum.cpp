#include <bits/stdc++.h>
using namespace std;

bool eratosthenes[1000001];
int pg1k_fexp[1000001];
vector<int> primelist;
vector<pair<int, int>> pfactor[1000001];
int cnt;

void sieve()
{
	primelist.push_back(2);
	for (int i = 3; i < 1001; i += 2)
		if (!eratosthenes[i])
			for (int j = i * i; j < 1000001; j += i)
				eratosthenes[j] = true;

	for (int i = 3; i < 1000001; i += 2)
		if (!eratosthenes[i])
			primelist.push_back(i);
}

void factor()
{
	for (auto x : primelist)
	{
		for (int i = x; i < 1000001; i += x)
		{
			int exp = 0;
			while (pg1k_fexp[i] % x == 0) exp++, pg1k_fexp[i] /= x;
			pfactor[i].emplace_back(x, exp);
		}
	}

	for (int i = 1009; i < 1000001; ++i)
		if (pg1k_fexp[i] > 1)
			pfactor[i].emplace_back(pg1k_fexp[i], 1);
	
	memset(pg1k_fexp, 0, sizeof(pg1k_fexp));
}

int power(int base, int exp)
{
	long long out = 1;
	int i = 1;
	while (i <= exp)
	{
		out *= base;
		if (out > 1000000) break;
		i++;
	}
	i--;
	if (i != exp) return 1000002;
	else return int(out);
}

int main()
{
	freopen("findnum.inp", "r", stdin);
	freopen("findnum.out", "w", stdout);
	sieve();
	for (int i = 0; i < 1000001; ++i)
		pg1k_fexp[i] = i;
	factor();
	
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int temp;
		cin >> temp;
		for (auto x : pfactor[temp])
			pg1k_fexp[x.first] += x.second;
	}

	int min = 1000001;
	for (auto x : primelist)
	{
		int scan = power(x, pg1k_fexp[x] + 1);
		if (min > scan) min = scan;
	}
	cout << min;
	return 0;
}