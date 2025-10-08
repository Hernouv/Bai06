#include <bits/stdc++.h>
using namespace std;

int a[10001];
int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		int lo = i + 1, hi = n;
		while (lo < hi)
		{
			if (a[i] + a[lo] + a[hi] <= x) cnt += hi - lo, lo++;
			else hi--;
		}
	}
	cout << cnt;
	return 0;
}