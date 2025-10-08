#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<pair<int, int>> res;
int inp;
void process(int a1, int b1, int a2, int b2)
{
	if (b1 + b2 > inp) res.emplace_back(a2, b2);
	else
	{
		process(a1, b1, a1 + a2, b1 + b2);
		process(a1 + a2, b1 + b2, a2, b2);
	}
}

int main()
{
	freopen("irreducible.inp", "r", stdin);
	freopen("irreducible.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> inp;
	process(0, 1, 1, 1);
	for (auto x : res)
		cout << x.first << ' ' << x.second << endl;
	res.pop_back();
	for (int i = res.size() - 1; i >= 0; --i)
		cout << res[i].second << ' ' << res[i].first << endl;
	return 0;
}