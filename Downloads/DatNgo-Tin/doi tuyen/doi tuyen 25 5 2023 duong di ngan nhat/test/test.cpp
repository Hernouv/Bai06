//dijkstra
#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

const int cnst = 1001, outbound = 1e9;
typedef pair<int, int> ii;
int start, vcount, ecount, dcount, requestcount, ascendant[cnst];
vector<ii> graph[cnst], ans_to_rqst[cnst];
int dist_from_source[cnst];
queue<int> rq_proc;
priority_queue <ii, vector<ii>, greater<ii>> pq;

void resetVal()
{
	for (int i = 1; i < cnst; ++i)
	{
		dist_from_source[i] = outbound;
		ascendant[i] = -1;
	}
	
}

void dijkstra(int start)
{
	dist_from_source[start] = 0;
	pq.push({start, 0});
	while (!pq.empty())
	{
		int index = pq.top().first;
		int min_dist = pq.top().second;
		pq.pop();
		if (dist_from_source[index] < min_dist) continue;
		for (auto v : graph[index])
		{
			int curr_index = v.first;
			int immd_dist = v.second;
			if (dist_from_source[curr_index] > dist_from_source[index] + immd_dist)
			{
				dist_from_source[curr_index] = dist_from_source[index] + immd_dist;
				ascendant[curr_index] = index;
				pq.push({ curr_index, dist_from_source[curr_index] });
			}
		}
	}
}

void path(int dest)
{
	stack<int> route;
	while (dest != start and dest != -1)
	{
		route.push(dest);
		dest = ascendant[dest];
	}
	route.push(start);

	cout << route.size() << ' ';
	while (!route.empty())
	{
		int temp = route.top();
		cout << temp << ' ';
		route.pop();
	}
	cout << endl;
}

int main()
{
	freopen("test.inp.txt", "r", stdin);
	freopen("test.out.txt", "w", stdout);

	cin >> vcount >> ecount >> requestcount;
	for (int i = 1; i <= ecount; ++i)
	{
		int t1, t2, val;
		cin >> t1 >> t2 >> val;
		graph[t1].push_back(make_pair(t2, val));
		graph[t2].push_back(make_pair(t1, val));
	}
	
	for (int i = 1; i <= requestcount; ++i)
	{
		int rqtype, dest;
		cin >> rqtype >> start >> dest;
		resetVal();
		dijkstra(start);
		if (rqtype == 0) cout << dist_from_source[dest] << endl;
		else if (rqtype == 1) path(dest);
	}
	return 0;
}