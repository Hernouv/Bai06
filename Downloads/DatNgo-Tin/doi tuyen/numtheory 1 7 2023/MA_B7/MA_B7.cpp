#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define eb emplace_back
#define fi first
#define se second
ull intg = 1, sq = 1;
ull inp;
vector<ull> primelist;
vector<pair<ull, ull>> pfact;

bool erastos[1000001];

void sieve()
{
	memset(erastos, true, sizeof(erastos));
	erastos[0] = erastos[1] = false;
	for (int i = 2; i <= 1000; ++i)
		if (erastos[i])
			for (int j = i * i; j <= 1000000; j += i)
				erastos[j] = false;

	primelist.eb(2);
	for (int i = 3; i <= 1000000; i += 2)
		if (erastos[i]) primelist.eb(i);
}

void factor(ull in)
{
	for (auto it : primelist)
	{
		if (in % it == 0)
		{
			ull exp = 0;
			while (in % it == 0) exp++, in /= it;
			pfact.eb(it, exp);
		}
	}
	if (in > 1) pfact.eb(in, 1);
}

int main()
{
	freopen("MA_B7.INP", "r", stdin);
	freopen("MA_B7.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	sieve();
	cin >> inp;
	factor(inp);
	for (auto it : pfact)
	{
		intg *= pow(it.fi, it.se / 2);
		if (it.se & 1) sq *= it.fi;
	}
	cout << intg << ' ' << sq;
	return 0;
}