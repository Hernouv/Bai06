#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int recallnum, roomnum, cnt = 0;
int ccno[1001];
bool visit[1001], res[10001];
vector<int> graph[1001];


void dfs(int index)
{
	ccno[index] = cnt;
	visit[index] = true;
	for (auto v : graph[index])
		if (!visit[v])
			dfs(v);
}

int main()
{
	freopen("robin.inp.txt", "r", stdin);
	freopen("robin.out.txt", "w", stdout);
	memset(visit, 0, sizeof(visit));
	cin >> roomnum >> recallnum;

	for (int i = 2; i <= roomnum; ++i)
	{
		int x, tl;
		cin >> x >> tl;
		if (tl == 1)
		{
			graph[i].push_back(x);
			graph[x].push_back(i);
		}
	}

	for (int i = 1; i <= roomnum; ++i)
		if (!visit[i])
		{
			cnt++;
			dfs(i);
			cout << endl;
		}

	for (int i = 1; i <= recallnum; ++i)
	{
		int start, finish;
		cin >> start >> finish;
		if (ccno[start] == ccno[finish]) res[i] = false;
		else res[i] = true;
	}

	for (int i = 1; i <= recallnum; ++i)
	{
		if (res[i] == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}