#include <bits/stdc++.h>
using namespace std;

int a[50001];

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	int q;
	cin >> q;
	
	for (int i = 0; i < q; ++i)
	{
		int temp;
		cin >> temp;
		int lo = 1, hi = n, cnt = 0;
		while (lo < hi)
		{
			if (a[lo] + a[hi] <= temp) cnt += hi - lo, ++lo;
			else --hi;
		}
		cout << cnt << '\n';
	}
}