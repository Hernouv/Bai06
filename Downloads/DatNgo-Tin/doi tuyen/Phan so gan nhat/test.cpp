#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("nearestf.inp", "r", stdin);
	freopen("nearestf.out", "w", stdout);
	double x;
	double tmin = 1;
	int n, a, b;
	cin >> x >> n;
	for (int i = 1; i <= n; ++i)
	{
		int t1, t2;
		t2 = i;
		t1 = round(x * t2);
		if (abs(double(t1) / t2 - x) < tmin)
		{
			a = t1;
			b = t2;
			tmin = abs(double(t1) / t2 - x);
		}
	}
	cout << a << ' ' << b;
	return 0;
}