#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll erastos[100001];
vector<pair<ll, ll>> factor[100001];
unordered_map<ll, ll> pf;

void sieve()
{
	for (int i = 0; i < 100001; ++i) erastos[i] = i;
	for (int i = 2; i * i < 100001; ++i)
		if (erastos[i] == i)
			for (int j = i * i; j < 100001; j += i)
				erastos[j] = i;
}

ll pwrmod(ll base, ll exp, ll mod)
{
	if (!exp) return 1;
	ll t = pwrmod(base, exp / 2, mod);
	t = (t * t) % mod;
	if (exp & 1) t = (t * base) % mod;
	return t;
}

void pfact()
{
	for (ll num = 2; num < 100001; ++num)
	{
		ll pr = erastos[num];
		while (num > 1)
		{
			ll exp = 0;
			while (num % pr == 0) exp++, num /= pr;
			factor[num].emplace_back(pr, exp);
		}
	}
}

ll combinmod(ll n, ll k, ll m)
{
	ll res = 1;
	for (ll i = n - k + 1; i <= n; ++i)
		for (auto it : factor[i])
			pf[it.first] += it.second;
	for (ll i = 1; i <= k; ++i)
		for (auto it : factor[i])
			pf[it.first] -= it.second;

	for (auto it : pf)
		res *= pwrmod(it.first, it.second, m);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	sieve();
	ll cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; ++i)
	{
		ll n, k, m;
		cin >> n >> k >> m;
		combinmod(n, k, m);
	}
}
// n! / k!(n - k)!