#include <bits/stdc++.h>
using namespace std;

#define l unsigned long long
l a, b, k;
string nonrepdec, repdec;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

l mul(l x, l y, l z)
{
	if (!y) return 0;
	if (y & 1) return (mul(x, y / 2, z) * 2 % z + x) % z;
	return mul(x, y / 2, z) * 2 % z;
}

l power(l x, l y, l z)
{
	if (!y) return 1;
	l t = power(x, y / 2, z);
	t = mul(t, t, z);
	if (y & 1) t = mul(t, x, z);
	return t;
}

int main()
{
	freopen("digit.inp", "r", stdin);
	freopen("digit.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	cin >> a >> b >> k;
	l g = gcd(a, b);
	a /= g, b /= g;
	a %= b;
	l m = a % b;
	l n = power(10, k - 1, b);
	l numer = mul(m, n, b);
	numer *= 10;
	numer /= b;
	cout << numer;
	return 0;
}