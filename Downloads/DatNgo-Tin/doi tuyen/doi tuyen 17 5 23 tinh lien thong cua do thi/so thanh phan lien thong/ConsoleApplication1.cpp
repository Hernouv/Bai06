#include <bits/stdc++.h>
using namespace std;

bool visit[10001];
vector<int> g[10001];
int edgecount, verticecount, _count;


void dfs(int u)
{
	cout << u << " ";
	visit[u] = true;
	for (auto v : g[u])
		if (!visit[v])
			dfs(v);
}

int main()
{
	memset(visit, false, sizeof(visit));
	cin >> verticecount >> edgecount;
	for (int i = 0; i < edgecount; ++i)
	{
		int edgestart, edgeend;
		cin >> edgestart >> edgeend;
		g[edgestart].push_back(edgeend);
		g[edgeend].push_back(edgestart);
	}

	//int _count = 0;
	for (int i = 1; i <= 8; ++i)
		if (!visit[i])
		{		
			_count++;
			cout << "tplt " << _count << ": ";
			dfs(i);
			cout << endl;
		}
	
	return 0;
}