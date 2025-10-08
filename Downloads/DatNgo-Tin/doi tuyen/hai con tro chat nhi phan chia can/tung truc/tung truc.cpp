#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tree;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, i, j, k, a, b, s[2] = { 0 };
	s[0] = 0, s[1] = 0;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		int d, k;
		cin >> d >> k;
		tree.emplace_back(d, k);
	}
	sort(tree.begin(), tree.end());
	j = -1, k = 1e9;
	for (int i = 0; i < n; ++i)
	{
		if (i) --s[tree[i - 1].second & 1];
		while ((s[1] < a or s[0] < b) and j < n)  ++s[(tree[++j].second) & 1];
		if (j == n) break;
		k = min(k, tree[j].first - tree[i].first);
	}
	if (k == 1e9) cout << -1;
	else cout << k;
	return 0;
}