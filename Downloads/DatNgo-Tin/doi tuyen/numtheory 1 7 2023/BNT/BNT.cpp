#include <bits/stdc++.h>
using namespace std;

bool erastos[1000001];
vector<int> prlist;
void sieve()
{
	for (int i = 2; i <= 1000; ++i)
		if (!erastos[i])
			for (int j = i * i; j <= 1000000; j += i)
				erastos[j] = true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("bnt.inp", "r", stdin);
	freopen("bnt.out", "w", stdout);
	sieve();
	int n;
	cin >> n;
	int lim = sqrt(n - 4);
	for (int i = 3; i <= lim; i += 2)
	{
		if (!erastos[i])
		{
			int sum = i * i + 4;
			if (!erastos[sum])
			{
				cout << 2 << ' ' << i << ' ' << sum << '\n';
			}
		}
	}
	if (lim < 3) cout << -1;
	return 0;
}