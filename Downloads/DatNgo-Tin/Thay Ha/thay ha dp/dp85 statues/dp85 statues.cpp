#include <bits/stdc++.h>
using namespace std;

int n, v[2002], f[2002][2002];
int l, r, res = 0, number = 0;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	for (int i = n - 1; i >= 1; --i)
	{
		f[i][i] = n * v[i];
		for (int j = i + 1; j <= n; ++j)
			f[i][j] = max(v[i] * (n - j + i) + f[i + 1][j], v[j] * (n - j + i) + f[i][j - 1]);
	}
	cout << f[0][n - 1];
	return 0;
}