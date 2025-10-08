#include <bits/stdc++.h>
using namespace std;

int parent[10001], d[10001], s, f, v, e;
bool visit[1001];
vector<int> g[10001];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	memset(d, 0, sizeof(d));
	memset(visit, false, sizeof(visit));
	memset(parent, -1, sizeof(parent));
	visit[s] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto v : g[u])
			if (!visit[v])
			{
				d[v] = d[u] + 1;
				parent[v] = u;
				q.push(v);
				visit[v] = true;
			}
	}
}

void trace(int u)
{
	if (!visit[u]) cout << "none";
	else
	{
		vector <int> path;
		for (int v = u; v != -1; v = parent[v])
			path.push_back(v);
		reverse(path.begin(), path.end());
		for (auto x : path) cout << x << ' ';
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> v >> e >> s >> f;
	for (int i = 1; i <= e; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	bfs(s);
	trace(f);
	return 0;
}