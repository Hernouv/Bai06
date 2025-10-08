#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull tree[100001];
vector<int> threshold;
int n, q, b;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("HOABAN.INP.txt", "r", stdin);
	freopen("HOABAN.OUT.txt", "w", stdout);
	cin >> n >> q >> b;
	tree[0] = 0x3f;
	fill(tree + 1, tree + n + 1, b);
	int min = 1;
	for (int i = 1; i <= q; ++i)
	{
		int r, p;
		cin >> r >> p;
		if (r >= min) tree[min]++, min++;
		else
		{
			int id = r;
			while (tree[id] == tree[id - 1]) id--;
			tree[id]++;
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << tree[i] << ' ';
	return 0;
}
