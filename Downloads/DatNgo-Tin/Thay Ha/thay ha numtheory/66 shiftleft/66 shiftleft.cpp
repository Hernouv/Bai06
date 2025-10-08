#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull mod = 1e8 + 7;

ull pwrmod(ull base, ull exp, ull m)
{
	if (!exp) return 1;
	ull t = pwrmod(base, exp / 2, m);;
	t = (t * t) % m;
	if (exp & 1) t = (t * base) % m;
	return t;
}

int main()
{
	freopen("shiftleft.inp", "r", stdin);
	freopen("shiftleft.out", "w", stdout);
	ull x, k;
	cin >> x >> k;
	ull mul = pwrmod(10, k + 1, 9 * mod) - 1;
	mul /= 9;
	mul *= x % mod;
	cout << mul % mod;
	return 0;
}