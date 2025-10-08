#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, m, y, x;
int garden[101][101], number[101][101], tnum = 0, veg_res = 0;
vector<int> graph[10001];
bool visit[10001];

void dfs(int index)
{
	veg_res++;
	visit[index] = true;
	for (auto v : graph[index])
		if (!visit[v])
			dfs(v);
}

int main()
{
	freopen("ocse.inp.txt", "r", stdin);
	freopen("ocse.out.txt", "w", stdout);

	memset(garden, 1, sizeof(garden));
	memset(visit, false, sizeof(false));

	cin >> n >> m >> y >> x;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			cin >> garden[i][j];
			if (garden[i][j] == 0)
			{
				tnum++;
				number[i][j] = tnum;
			}

		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (garden[i][j] == 0)
			{
				if (garden[i - 1][j] == 0)
					graph[number[i - 1][j]].push_back(number[i][j]);

				if (garden[i + 1][j] == 0)
					graph[number[i + 1][j]].push_back(number[i][j]);

				if (garden[i][j - 1] == 0)
					graph[number[i][j - 1]].push_back(number[i][j]);

				if (garden[i][j + 1] == 0)
					graph[number[i][j + 1]].push_back(number[i][j]);
			}

	if (garden[y][x]) cout << 0;
	else
	{
		dfs(number[y][x]);
		cout << veg_res << endl;
	}

	return 0;
 }