#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("lastz10.inp", "r", stdin);
	freopen("lastz10.out", "w", stdout);
	int ans = 0;
	int n;
	cin >> n;
	while (n) ans += n /= 5;
	cout << ans;
	return 0;
}