#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int vertices_count, edges_count;
int start_cycle, end_cycle;
int parent[100001];
bool visited[100001], check_cycle[100001];
set<int> graph[100001];

bool dfs(int index)
{
	visited[index] = true;
	for (auto v : graph[index])
	{
		if (!visited[v])
		{
			parent[v] = index;
			if (dfs(v)) return true;
		}
		else
		{
			if (!check_cycle[v])
			{
				if (v != parent[index])
				{
					start_cycle = v;
					end_cycle = index;
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	freopen("vd2.inp.txt", "r", stdin);
	freopen("vd2.out.txt", "w", stdout);

	memset(visited, false, sizeof(visited));
	memset(parent, -1, sizeof(parent));

	cin >> vertices_count >> edges_count;
	for (int i = 1; i <= edges_count; ++i)
	{
		int es, ee;
		cin >> es >> ee;
		graph[es].insert(ee);
	}

	int cnt = 0;
	for (int i = 1; i <= vertices_count; ++i)
	{
		if (!visited[i])
		{
			if (dfs(i))
			{
				cnt++;
				if (cnt == 1) cout << "YES" << endl;
				stack<int> res;

				res.push(start_cycle);
				do
				{
					res.push(end_cycle);
					end_cycle = parent[end_cycle];
				} while (end_cycle != start_cycle);
				res.push(start_cycle);

				while (!res.empty())
				{
					int t = res.top();
					check_cycle[t] = true;
					cout << t << ' ';
					res.pop();
				}
			}
		}
		else if (i == vertices_count and cnt == 0)
		{
			cout << "NO";
			return 0;
		}
	}

	return 0;
}