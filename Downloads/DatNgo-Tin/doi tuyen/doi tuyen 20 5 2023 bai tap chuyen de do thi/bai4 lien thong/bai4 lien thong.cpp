#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int v, e, number[10001], low[10001], timer = 0, countcau = 0, countkhop = 0;
int child[10001];
bool checkkhop[10001];
vector<int> graph[10001];

void dfs(int index, int parent)
{
	child[index] = 0;
	number[index] = ++timer;
	low[index] = number[index];
	for (auto vertex : graph[index])
	{
		if (vertex == parent) continue;
		if (!number[vertex])
		{
			dfs(vertex, index);
			low[index] = min(low[index], low[vertex]);
			if (low[vertex] == number[vertex])
				countcau++;
			child[index]++;
			if (index == parent)
			{
				if (child[index] > 1) checkkhop[index] = true;
			}
			else
				if (low[vertex] >= number[index]) checkkhop[index] = true;
		}
		else
			low[index] = min(low[index], number[vertex]);
	}
}

void output()
{
	for (int i = 1; i <= v; ++i)
		if (!number[i])
			dfs(i, i);
	for (int i = 1; i <= v; ++i)
		if (checkkhop[i])
			countkhop++;
	cout << countkhop << ' ' << countcau;
}

int main()
{
	cin >> v >> e;
	for (int i = 0; i <= e; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	output();
	return 0;
}