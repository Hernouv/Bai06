#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
	while (a and b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return max(a, b);
}

int main()
{
	freopen("PAINT.INP", "r", stdin);
	freopen("PAINT.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	long long n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	long long t1 = (n / a) * p;
	long long t2 = (n / b) * q;
	long long lcm = a * b / gcd(a, b);
	long long t3 = t1 + t2 - (n / lcm) * min(p, q);
	cout << t3;
	return 0;
}