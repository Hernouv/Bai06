#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[5001], b[5001], dp[5001][5001];

int proc(int m, int n)
{
	if (m < 0 or n < 0) return 0;
	int& ret = dp[m][n];
	if (ret != -1) return ret;
	ret = max(ret, proc(m - 1, n));
	ret = max(ret, proc(m, n - 1));
	ret = max(ret, (a[m] == b[n]) + proc(m - 1, n - 1));
	return ret;
}

void trace(int m, int n)
{
	if (m < 0 or n < 0) return;

	if (proc(m - 1, n) == proc(m, n)) trace(m - 1, n);
	else if (proc(m, n - 1) == proc(m, n)) trace(m, n - 1);
	else
	{
		trace(m - 1, n - 1);
		cout << a[m] << ' ';
	}
}

int main()
{
	freopen("lcs.inp", "r", stdin);
	freopen("lcs.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	memset(dp, 0xff, sizeof(dp));
	cout << proc(m - 1, n - 1) << '\n';
	trace(m - 1, n - 1);
	return 0;
}