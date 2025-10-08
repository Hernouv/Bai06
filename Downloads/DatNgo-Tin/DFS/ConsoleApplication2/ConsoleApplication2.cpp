//nhung hieu biet dau tien ve dfs :))

#include <bits/stdc++.h>
using namespace std;

bool visit[10001];
int parent[10001];
vector<int> graph[10001];
int F, S, V, E;


void dfs(int u)
{
	cout << u << ' ';
	visit[u] = true;
	for (auto v : graph[u])
		if (!visit[v])
		{
			parent[v] = u;
			dfs(v);
		}
}

void trace()
{
	stack<int> St;
	St.push(F);
	int u = F;
	while (u != S);
	{
		u = parent[u];
		St.push(u);
	}
	St.push(S);
	while (!St.empty())
	{
		cout << St.top() << ' ';
		St.pop();
	}
}

void input()
{
	cin >> V >> E >> S >> F;
	for (int i = 1; i <= E; ++i)
	{
		int p1, p2;
		cin >> p1 >> p2;
		graph[p1].push_back(p2);
		graph[p2].push_back(p1);
	}
}

int main()
{
	//freopen
	cin.tie(0)->sync_with_stdio(false);
	memset(parent, 0, sizeof(parent));
	input;
	cin >> V >> E >> S >> F;
	dfs(S);
	parent[S] = -1;
	if (parent[F] <= 0)
		cout << "none";
	else
		trace();
	return 0;
}