#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
char X[22];
ull N, factorial[22];
unsigned i, c[10];

void factorial_setVal()
{
	factorial[0] = 1;
	for (unsigned i = 1; i < 22; ++i)
		factorial[i] = factorial[i - 1] * i;
}

ull count(unsigned c[])
{
	unsigned i, sum = 0;
	for (unsigned int i = 1; i < 10; ++i)
		sum += c[i];

	ull res = factorial[sum];
	for (unsigned i = 1; i < 10; ++i)
		if (c[i])
			res /= factorial[c[i]];

	return res;
}

string solve(ull N, unsigned c[])
{
	ull num = 0, temp;
	for (unsigned i = 1; i < 10; ++i)
	{
		if (!c[i]) continue;
		c[i]--;
		temp = count(c);
		num += temp;
		if (num >= N)
			return char(i + '0') + solve(N - num + temp, c);
		else
			c[i]++;
	}
	return "";
}

int main()
{
	//freopen("reper.inp", "r", stdin);
	//freopen("reper.out", "w", stdout);
	factorial_setVal();
	c[10] = { 0 };
	cin >> N >> X;
	for (unsigned i = 0; X[i]; ++i)
		c[X[i] - '0']++;
	cout << solve(N, c);
	return 0;
}