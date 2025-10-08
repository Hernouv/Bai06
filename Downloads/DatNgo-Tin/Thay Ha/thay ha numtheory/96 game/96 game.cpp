#include <bits/stdc++.h>
using namespace std;

bool erastosthenes[2001];

void sieve()
{
	erastosthenes[0] = erastosthenes[1] = false;
	for (int i = 2; i * i <= 2000; ++i)
	{
		if (erastosthenes[i])
			for (int j = i * i; j <= 2000; j += i)
				erastosthenes[j] = false;
	}
}

bool check(int c, int d, int plus)
{
	for (int i = c; i <= d; ++i)
		if (erastosthenes[i + plus]) return true;
	return false;
}

int main()
{
	freopen("game.inp", "r", stdin);
	freopen("game.out", "w", stdout);
	memset(erastosthenes, true, sizeof(erastosthenes));
	sieve();
	int matchcount;
	cin >> matchcount;
	for (int i = 1; i <= matchcount; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		bool tcheck = true;
		for (int j = a; j <= b; ++j)
			if (!check(c, d, j))
			{
				tcheck = false;
				break;
			}
		if (tcheck) cout << "Cam" << endl;
		else cout << "Tam" << endl;
	}
	return 0;
}