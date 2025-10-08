#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graph[260];
bool visit[32000];

void dfs(int index)
{
	visit[index] = true;
	for (auto v : graph[index])
		if (!visit[v])
			dfs(v);
}

int main()
{
	freopen("bcdaisy.inp.txt", "r", stdin);
	freopen("bcdaisy.out.txt", "w", stdout);
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
		if (!visit[i])
			cout << i << endl;
	return 0;
}