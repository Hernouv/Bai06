#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
int cnt;
int permutation[100001];
int cycleId[100001];
vector<int> cycle_size;

int gcd(int a, int b)
{
	while (a and b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return max(a, b);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b)) % 123456789;
}

int main()
{
	freopen("permute.inp", "r", stdin);
	freopen("permute.out", "w", stdout);
	memset(cycleId, 0, sizeof(cycleId));
	cin >> cnt;
	for (int i = 1; i <= cnt; ++i)
		cin >> permutation[i];

	for (int i = 1; i <= cnt; ++i)
		if (!cycleId[i])
		{
			int number = 1;
			cycleId[i] = number;
			int trace = permutation[i];
			while (trace != i)
			{
				cycleId[trace] = ++number;
				trace = permutation[trace];
			}
			cycle_size.push_back(number);
		}

	ull res = 1;
	for (auto x : cycle_size)
		res = lcm(res, x);

	cout << res;
	
	return 0;
}