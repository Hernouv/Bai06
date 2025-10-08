#include <bits/stdc++.h>
using namespace std;

unsigned long long grid[1001][1001];

int main()
{
	memset(grid, 1, sizeof(grid));
	int m, n, k, kx, ky;
	cin >> m >> n >> k;
	cin >> kx >> ky;
	for (int i = 2; i <= m; ++i)
		for (int j = 2; j <= n; ++j)
			if (j != kx and i != ky) grid[i][j] = (grid[i - 1][j] + grid[i][j - 1]) % 1000000007;
			else grid[i][j] = 0;

	cout << grid[m][n];
	return 0;
}