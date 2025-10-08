#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

vector<int> g[10001], rg[10001];
stack<int> s;
bool visit[10001];
int vertex, edge;

void dfs(int index)
{
	visit[index] = true;
	s.push(index);
	for (auto i0 : g[index])
		if (!visit[i0])
			dfs(i0);
}

void rdfs(int index)
{
	visit[index] = true;
	cout << index << ' ';
	for (auto i0 : rg[index])
		if (!visit[i0])
			rdfs(i0);
}

void connected_component()
{
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= vertex; ++i)
		if (!visit[i])
			dfs(i);

	memset(visit, false, sizeof(visit));
	int _count = 0;
	while (!s.empty())
	{
		int v = s.top();
		s.pop();
		if (!visit[v])
		{
			_count++;
			cout << "Connected Component " << _count << ": ";
			rdfs(v);
			cout << endl;
		}
	}
}

int main()
{
	freopen("kosaraju.inp.txt", "r", stdin);
	freopen("kosaraju.out.txt", "w", stdout);

	cin >> vertex >> edge;
	for (int i = 1; i <= edge; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		g[t1].push_back(t2);
		rg[t2].push_back(t1);
	}
	connected_component();
	return 0;
}