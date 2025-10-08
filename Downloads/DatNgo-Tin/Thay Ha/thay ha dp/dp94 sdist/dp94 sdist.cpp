#include <bits/stdc++.h>
using namespace std;

long long l[10005];
long long res[10005], ans = 0;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> l[i];
	sort(l + 1, l + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		long long t = abs(l[i] - l[i - 1]);
		res[i] = t * (i - 1) + res[i - 1];
		ans += res[i];
	}
	
	cout << 2 * ans;
	return 0;
}