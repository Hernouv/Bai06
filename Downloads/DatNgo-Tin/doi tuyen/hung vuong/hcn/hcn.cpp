#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;

bool erastos[1000001];
int primecountcolumn[301], primecountrow[301];
int grid[301][301];
int prime[301][301], checked[301][301], num = 1;
vector<pair<int, int>> primepos;
int m, n;
long long cnt = 0;
void sieve()
{
	erastos[0] = erastos[1] = false;
	for (int i = 2; i <= 1000; ++i)
	{
		if (erastos[i])
			for (int j = i * i; j <= 1000000; j += i)
				erastos[j] = false;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("hcn.inp", "r", stdin);
	freopen("hcn.out", "w", stdout);
	memset(erastos, true, sizeof(erastos));
	memset(prime, 0, sizeof(prime));
	memset(checked, 0, sizeof(prime));
	sieve();
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> grid[i][j];
			if (erastos[grid[i][j]]) prime[i][j] = 1, primepos.emplace_back(i, j);
			grid[i][j] = num;
			num++;
		}
	}
	for (auto it : primepos)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if ((prime[it.first][it.second] + prime[it.first][j] + prime[i][it.second] + prime[i][j] >= 3) and (checked[it.first][it.second] != grid[it.first][j] + grid[i][j] + grid[i][it.second] and checked[it.first][j] != grid[it.first][it.second] + grid[i][j] + grid[i][it.second] and checked[i][it.second] != grid[i][j] + grid[it.first][it.second] + grid[it.first][j] and checked[i][j] != grid[i][it.second] + grid[it.first][it.second] + grid[it.first][j]) and i != it.first and j != it.second)
				{
					cnt++;
					checked[it.first][it.second] = grid[it.first][j] + grid[i][j] + grid[i][it.second];
					checked[it.first][j] = grid[it.first][it.second] + grid[i][j] + grid[i][it.second];
					checked[i][it.second] = grid[i][j] + grid[it.first][it.second] + grid[it.first][j];
					checked[i][j] = grid[i][it.second] + grid[it.first][it.second] + grid[it.first][j];
				}
	}
	cout << cnt / 2;
	return 0;
}