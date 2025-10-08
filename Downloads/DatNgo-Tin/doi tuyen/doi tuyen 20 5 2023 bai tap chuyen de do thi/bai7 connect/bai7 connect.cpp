#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int v, e, tsize;
vector<int> graph[10001], res;
bool visit[10001];

void dfs(int index)
{
	tsize++;
	visit[index] = true;
	for (auto x : graph[index])
		if (!visit[x])
			dfs(x);
}

int main()
{
	freopen("connect.inp.txt", "r", stdin);
	freopen("connect.out.txt", "w", stdout);
	memset(visit, false, sizeof(visit));
	cin >> v >> e;
	for (int i = 1; i <= e; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2; 
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	for (int i = 1; i <= v; ++i)
		if (!visit[i])
		{
			tsize = 0;
			dfs(i);
			res.push_back(tsize);
		}

	sort(res.begin(), res.end(), greater<int>());
	if (res.size() == 0) cout << res[0];
	else cout << res[0] + res[1];
	return 0;
}