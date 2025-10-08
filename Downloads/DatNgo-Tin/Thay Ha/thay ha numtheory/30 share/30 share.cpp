#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	freopen("share.inp", "r", stdin);
	freopen("share.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int a, b;
		cin >> a >> b;
		int g = gcd(a, b);
		int sum = a / g + b / g;
		while (sum % 2 == 0) sum /= 2;
		if (sum != 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}