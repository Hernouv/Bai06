#include <bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long base, unsigned long long index)
{
	unsigned long long res = 1;
	for (unsigned long long i = 1; i <= index; ++i)
		res *= base;
	return res;
}

int main()
{
	//freopen("cdigit.inp", "r", stdin);
	//freopen("cdigit.out", "w", stdout);
	unsigned long long n, t;
	cin >> n;
	t = n;
	unsigned long long digit = 0;
	while (t > 0)
	{
		t /= 10;
		digit++;
	}
	unsigned long long res = 0;
	for (unsigned long long i = 1; i <= digit - 1; ++i)
		res += 9 * power(10, i - 1) * i;
	res += (n - power(10, digit - 1)) * digit;
	cout << res + digit;
	return 0;
}