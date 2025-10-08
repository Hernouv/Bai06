#include <bits/stdc++.h>
using namespace std;

bool eratosthenes[1001000];

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = true;
	for (int i = 4; i < 1001000; i += 2)
		eratosthenes[i] = true;
	for (int i = 3; i < 1001; i += 2)
		if (!eratosthenes[i])
			for (int j = i * i; j < 1001000; j += i)
				eratosthenes[j] = true;
}

int main()
{
	sieve();
	int inp;
	cin >> inp;
	if (inp == 1) cout << 2;
	else
	{
		
		int res;
		for (int i = inp; i >= 0; --i)
			if (!eratosthenes[i])
			{
				res = i;
				break;
			}

		int upbound = inp + inp - res;
		for (int i = inp + 1; i < upbound; ++i)
			if (!eratosthenes[i])
			{
				res = i;
				break;
			}
		cout << res;
	}
	return 0;
}