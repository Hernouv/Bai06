#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll conn[200001];
bool seqcheck[200001];
unordered_map<ll, vector<ll>> seq;
vector<ll> scan;
ll cnt;

void dfs_but_its_strange(ll indx)
{
	ll begin = indx;
	while (indx != -1)
	{
		seq[begin].push_back(indx);
		seqcheck[indx] = true;
		indx = conn[indx];
	}
}

ll maxi(ll x, ll y)
{
	return (x > y ? x : y);
}

int main()
{
	freopen("conint.inp", "r", stdin);
	freopen("conint.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);

	memset(conn, -1, sizeof(conn));
	ll end = -1, start = 300000;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		ll a, b;
		cin >> a >> b;
		a += 100000, b += 100000;
		end = max(end, a);
		start = min(start, a);
		conn[a] = b;
	}

	for (int i = start; i <= end; ++i)
		if (!seqcheck[i] and conn[i] != -1) scan.push_back(i), dfs_but_its_strange(i);

	ll res = 0;
	for (auto it : scan)
		res = maxi(res, seq[it].size());

	cout << res - 1;
	return 0;
}