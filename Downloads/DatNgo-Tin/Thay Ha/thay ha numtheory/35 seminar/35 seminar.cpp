#include <bits/stdc++.h>
using namespace std;

#define u unsigned long long

int main()
{
	freopen("seminar.inp", "r", stdin);
	freopen("seminar.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n, res = 0;
	u k;
	cin >> n >> k;
	u scan = 0;
	for (int i = 0; i < n; ++i)
	{
		u inp;
		cin >> inp;
		scan += inp;
		if (scan >= k) res++;
		scan %= k;
	}
	cout << res;
	return 0;
}