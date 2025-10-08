#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	while (a != b)
		a > b ? a -= b : b -= a;
	return a;
}

int main()
{
	int n, a, b, p, q;
	long long s = 0;
	cin >> n >> a >> b >> p >> q;
	int common = gcd(a, b);
	int lcm = (a / common) * b;
	s = p * (n / a - n / lcm) + q * (n / b - n / lcm) + (n / lcm) * max(p, q);
	cout << s;
	return 0;
}