#include <bits/stdc++.h>
using namespace std;

unsigned long long cnt = 0;
int erastos[1000001], lim;
bool sq[1010000];
int t[1000001];
void sieve()
{
	for (int i = 0; i <= 1000000; ++i) erastos[i] = i;
	for (int i = 2; i <= 1000; ++i)
		if (erastos[i] == i)
			for (int j = i * i; j <= 1000000; j += i)
				erastos[j] = i;
}

void factor()
{
	cnt = 0;
	memset(t, 0, sizeof(t));
	int sqcnt = 1;
	while (sqcnt * sqcnt <= lim) sqcnt++;
	sqcnt--;
	int minmul = INT_MAX, maxmul = 0;
	cnt += (sqcnt * (sqcnt - 1) * (sqcnt - 2)) / 6;
	for (int i = 2; i <= lim; ++i)
	{
		if (!sq[i])
		{
			int x = i, mul = 1;
			while (x > 1)
			{
				int pr = erastos[x], exp = 0;
				while (x % pr == 0) exp++, x /= pr;
				if (exp & 1) mul *= pr;
			}
			t[mul]++;
			minmul = min(minmul, mul);
			maxmul = max(maxmul, mul);
		}
	}
	for (int i = minmul; i <= maxmul; ++i)
		if (t[i] >= 3) cnt += (t[i] * (t[i] - 1) * (t[i] - 2)) / 6;
}

int main()
{
	freopen("CPROD.INP", "r", stdin);
	freopen("CPROD.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	sieve();
	memset(sq, false, sizeof(sq));
	for (int i = 1; i <= 1000; ++i)
		sq[i * i] = true;
	int test;
	cin >> test;
	for (int i = 1; i <= test; ++i)
	{
		cin >> lim;
		factor();
		cout << cnt << '\n';
	}
	return 0;
}