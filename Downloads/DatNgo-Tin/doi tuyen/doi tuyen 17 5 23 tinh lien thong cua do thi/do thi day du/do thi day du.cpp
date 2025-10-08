//warshall algorithm
#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;
#define lim 101
bool a[lim][lim], visit[lim * lim];
int _count = 0, e, v;

void input()
{
	cin >> v >> e;
	for (int i = 1; i <= e; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		a[t1][t2] = true;
		a[t2][t1] = true;
	}
}

void warshall(int n)
{
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			if (a[i][k])
				for (int j = 1; j <= n; ++j)
					if (a[k][j])
						a[i][j] = true;
}

void tplt(int n)
{
	for (int i = 1; i <= n; ++i)
		if (!visit[i])
		{
			_count++;
			cout << "Connected Component " << _count << ": " << i << ' ';
			for (int j = i + 1; j <= n; ++j)
				if (a[i][j])
				{
					cout << j << ' ';
					visit[j] = true;
				}
			cout << endl;
		}
}

int main()
{
	freopen("warshall.inp.txt", "r", stdin);
	freopen("warshall.out.txt", "w", stdout);
	memset(a, false, sizeof(a));
	input();
	warshall(v);
	tplt(v);
	return 0;
}