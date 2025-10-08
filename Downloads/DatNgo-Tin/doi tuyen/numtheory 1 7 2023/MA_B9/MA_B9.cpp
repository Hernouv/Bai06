#include <bits/stdc++.h>
using namespace std;
#define d double

int main()
{
	freopen("MA_B9.INP", "r", stdin);
	freopen("MA_B9.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		d a, b;
		cin >> a >> b;
		d t1 = a, t2 = b + 1;
		a--;
		d lo = (a * a * t1 * t1) / 4, hi = (b * b * t2 * t2) / 4;
		cout << fixed << setprecision(0) << hi - lo << '\n';
	}
	return 0;
}