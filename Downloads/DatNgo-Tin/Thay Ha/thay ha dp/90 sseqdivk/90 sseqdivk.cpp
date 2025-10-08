#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
const int N = 1 + 1e4, K = 1 + 1e3;
const int inf = 0x3f3f3f;

int n, k, a[N], f[N][K];
int dp(int i, int r)
{
	if (i < 0) return (r ? -inf : 0);
	int& ret = f[i][r];
	if (ret != -1) return ret;
	return ret = max(dp(i - 1, r), 1 + dp(i - 1, (r + k - a[i] % k) % k));
}

void trace(int i, int r)
{
	if (!i)
	{
		if (r == (a[i] % k + k) % k) cout << i + 1 << ' ';
		return;
	}
	if (dp(i, r) == dp(i - 1, r)) trace(i - 1, r);
	else
	{
		trace(i - 1, (r + k - a[i] % k) % k);
		cout << i + 1 << ' ';
	}
}

int main()
{
	freopen("sseqdivk.inp", "r", stdin);
	freopen("sseqdivk.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	memset(f, 0xff, sizeof(f));
	cout << dp(n - 1, 0) << '\n';
	trace(n - 1, 0);
	return 0;
}