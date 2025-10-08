#include <bits/stdc++.h>
using namespace std;

#define qnp quantity_and_price

int n, m;
int arr[101][7];

int purchase(int c, int d, int e, int f, int t)
{
	if (!t) return 0;
	int retval = 100000;
	int limx = ceil(double(t) / c);
	for (int x = limx; x >= 0; --x)
	{
		int y = ceil(double(t - c * x) / e);
		retval = min(retval, d * x + f * y);
	}
	return retval;
}

int cost(int k)
{
	int s = 0;
	for (int i = 1; i <= n; ++i) s += purchase(arr[i][3], arr[i][4], arr[i][5], arr[i][6], max(0, k * arr[i][1] - arr[i][2]));
	return s;
}

int main()
{
	freopen("assem.inp", "r", stdin);
	freopen("assem.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < 7; ++j)
			cin >> arr[i][j];

	int lo = 0, hi = 1;
	while (cost(hi) <= m) hi <<= 1;
	while (lo < hi)
	{
		int mid = (lo + hi + 1) >> 1;
		if (cost(mid) <= m) lo = mid;
		else hi = mid - 1;
	}

	cout << hi;
	return 0;
}