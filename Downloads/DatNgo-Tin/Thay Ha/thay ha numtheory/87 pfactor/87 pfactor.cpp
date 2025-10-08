#include <bits/stdc++.h>
using namespace std;

bool eratosthenes[10000001];
vector<long long> primelist;
long long f;

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = false;
	for (int i = 4; i <= 10000000; i += 2)
		eratosthenes[i] = false;

	for (int i = 3; i < 3164; i += 2)
		if (eratosthenes[i])
			for (int j = i * i; j < 10000000; j += i)
				eratosthenes[j] = false;

	primelist.push_back(2);
	for (int i = 3; i < 10000000; i += 2)
		if (eratosthenes[i]) primelist.push_back(i);
}

void factor(long long inp)
{
	for (int i = 0; i < primelist.size(); ++i)
	{
		if (primelist[i] * primelist[i] > inp) break;
		if (!(inp % primelist[i]))
		{
			while (!(inp % primelist[i]))
				inp /= primelist[i];
			f = primelist[i];
		}
	}
	if (inp > 1)
		f = inp;

	cout << f;
}

int main()
{
	freopen("pfactor.inp", "r", stdin);
	freopen("pfactor.out", "w", stdout);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	long long n;
	cin >> n;
	factor(n);
	return 0;
}