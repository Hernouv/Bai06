#include <bits/stdc++.h>
using namespace std;

int cnt, res;
int a[30001], dp[30001][3];

int cal()
{
	cin.tie(0)->sync_with_stdio(false);
	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	dp[0][a[0] - 1]--;

	for (int i = 1; i < cnt; ++i)
	{
		dp[i][0] = dp[i - 1][0] + 1 - (a[i] == 1);
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1 - (a[i] == 2);
		dp[i][2] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }) + 1 - (a[i] == 3);
	}
	return min({ dp[cnt - 1][0], dp[cnt - 1][1], dp[cnt - 1][2] });
}

int main()
{
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
		cin >> a[i];
	res = cal();

	for (int i = 0; i < cnt; ++i)
		a[i] = 4 - a[i];
	res = min(res, cal());
	cout << res;
	return 0;
}