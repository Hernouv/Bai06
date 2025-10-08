#include <bits/stdc++.h>
using namespace std;

bool erastos[1000001];
void sieve()
{
	erastos[0] = erastos[1] = true;
	for (int i = 2; i <= 1000; ++i)
		if (!erastos[i])
			for (int j = i * i; j <= 1000000; j += i)
				erastos[j] = true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("NTO.INP", "r", stdin);
	freopen("NTO.OUT", "w", stdout);
	sieve();
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int in;
		cin >> in;
		if (erastos[in] or in < 0) cout << "Yes" << '\n';
		else cout << "No" << '\n';
	}
	return 0;
}