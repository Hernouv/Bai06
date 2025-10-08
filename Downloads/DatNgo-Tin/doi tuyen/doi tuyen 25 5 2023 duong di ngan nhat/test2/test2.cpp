#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

const int cnst = 100001, outbound = 1e9;
typedef pair<int, int> ii;
int vcount, ecount;
vector<long long> spath_count(cnst, 1);
vector<int> dist_from_source(cnst, outbound), ascendant(cnst);
vector<ii> graph[cnst];
priority_queue<ii, vector<ii>, greater<ii>> pq;

void dijkstra(int start)
{
	dist_from_source[start] = 0;
	pq.emplace(start, 0);
	while (!pq.empty())
	{
		int index = pq.top().first;
		int min_dist = pq.top().second;
		pq.pop();
		if (dist_from_source[index] < min_dist) continue;
		for (auto v : graph[index])
		{
			int curr_indx = v.first;
			int immd_dist = v.second;
			if (dist_from_source[curr_indx] == dist_from_source[index] + immd_dist)
				spath_count[curr_indx] += spath_count[index];
			else if (dist_from_source[curr_indx] > dist_from_source[index] + immd_dist)
			{
				dist_from_source[curr_indx] = dist_from_source[index] + immd_dist;
				spath_count[curr_indx] = spath_count[index];
				pq.emplace(curr_indx, dist_from_source[curr_indx]);
			}
		}
	}
}

int main()
{
	freopen("test2.inp.txt", "r", stdin);
	freopen("test2.out.txt", "w", stdout);
	cin >> vcount >> ecount;
	for (int i = 1; i <= ecount; ++i)
	{
		int orient, t1, t2, val;
		cin >> orient >> t1 >> t2 >> val;
		graph[t1].emplace_back(t2, val);
		if (orient == 2)
			graph[t2].emplace_back(t1, val);
	}

	dijkstra(1);
	cout << dist_from_source[vcount] << ' ' << spath_count[vcount];
	return 0;
}