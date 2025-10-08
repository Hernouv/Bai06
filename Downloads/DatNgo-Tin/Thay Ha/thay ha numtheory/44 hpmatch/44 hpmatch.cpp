#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

int main()
{
	freopen("hpmatch.inp", "r", stdin);
	freopen("hpmatch.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> a >> b >> c >> d;
	int ans = a % 2 + c % 2;
	if (b > d)
	{
		ans += b - d;
		if (c % 2) ans--;
		if (a % 2 and b - d - c % 2 > 0) ans--;
	}
	else if (b < d)
	{
		ans += d - b;
		if (a % 2) ans--;
		if (c % 2 and d - b - a % 2 > 0) ans--;
	}
	cout << ans;
	return 0;
}