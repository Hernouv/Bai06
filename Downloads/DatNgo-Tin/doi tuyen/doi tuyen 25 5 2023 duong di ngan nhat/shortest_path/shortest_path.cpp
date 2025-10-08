#include <bits/stdc++.h>
using namespace std;

const int cnst = 10001, outbound = 1e9;
typedef pair<int, int> ii;
int vcount, ecount, start, dest_count;
vector<ii> graph[cnst];
int dist_source[cnst];
int parent[cnst];
priority_queue<ii, vector<ii>, greater<ii>> vertices_list;

void dijkstra(int start)
{
	dist_source[start] = 0;
	vertices_list.push({start, 0});
	while (!vertices_list.empty())
	{
		int index = vertices_list.top().first;
		int min_dist = vertices_list.top().second;
		vertices_list.pop();
		if (dist_source[index] < min_dist)
			continue;
		for (auto v : graph[index])
		{
			int curr_indx = v.first;
			int immd_dist = v.second;
			if (dist_source[curr_indx] > dist_source[index] + immd_dist)
			{
				dist_source[curr_indx] = dist_source[index] + immd_dist;
				parent[curr_indx] = index;
				vertices_list.push({curr_indx, dist_source[curr_indx]});
			}
		}
	}
}

void path(int dest)
{
	stack<int> route;
	while (dest != start)
	{
		route.push(dest);
		dest = parent[dest];
	}
	route.push(start);

	while (!route.empty())
	{
		int temp = route.top();
		cout << temp << ' ';
		route.pop();
	}
	cout << '\n';
}

int main()
{
	freopen("spath.inp.txt", "r", stdin);
	freopen("spath.out.txt", "w", stdout);

	for (int i = 0; i < cnst; ++i)
		dist_source[i] = outbound;

	cin >> vcount >> ecount;
	int t1, t2, val;
	for (int i = 1; i <= ecount; ++i)
	{
		cin >> t1 >> t2 >> val;
		graph[t1].push_back({t2, val});
		graph[t2].push_back({t1, val});
	}

	cin >> start;
	dijkstra(start);
	for (int i = 1; i <= vcount; ++i)
		cout << dist_source[i] << ' ';
	cout << '\n';

	cin >> dest_count;
	for (int i = 1; i <= dest_count; ++i)
	{
		int destination;
		cin >> destination;
		cout << dist_source[destination] << '\n';
		path(destination);
	}
	return 0;
}