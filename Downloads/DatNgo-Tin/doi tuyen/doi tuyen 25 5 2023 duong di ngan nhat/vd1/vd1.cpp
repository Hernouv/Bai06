#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int v, s, e, parent[100001];
vector<int> graph[100001];
bool visit[100001];
stack<int> st;

void dfs(int s)
{
	visit[s] = true;
	cout << s << ' ';
	for (auto i : graph[s])
		if (!visit[i])
		{
			parent[i] = s;
			dfs(i);
		}
}

void trace(int e)
{
	int res = 0, root = e;
	st.push(e);
	do
	{
		e = parent[e];
		if (e == 0 or e == root)
		{
			res = -1;
			break;
		}
		st.push(e);
	} while (e != s);

	if (res == -1) cout << res;
	else
	{
		int u;
		while (st.size() > 1)
		{
			u = st.top();
			cout << u << " - ";
			st.pop();
		}
		cout << st.top();
	}

}
int main()
{
	freopen("vd1.inp.txt", "r", stdin);
	freopen("vd1.out.txt", "w", stdout);
	cin >> v >> s >> e;
	for (int i = 0; i <= v; ++i)
	{
		string t;
		getline(cin, t);
		stringstream ss(t);
		int num;
		while (ss >> num)
			graph[i].push_back(num);
	}

	for (int i = 1; i <= v; ++i)
		graph[i].pop_back();

	cout << s << ": ";
	dfs(s);

	cout << endl;

	cout << s << " -> " << e << ": ";
	trace(e);
}