#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll cnst = 1e9 + 7;
bool eratosthenes[100000001];
vector<int> primelist;
vector<ll> prevsum;

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = false;
	for (int i = 4; i <= 100000000; i += 2)
		eratosthenes[i] = false;

	for (int i = 3; i < 10000; i += 2)
		if (eratosthenes[i])
			for (int j = i * i; j < 100000000; j += i)
				eratosthenes[j] = false;

	ll tcs = 0;
	for (int i = 1; i < 99999998; ++i)
	{
		if (!eratosthenes[i]) tcs += i;
		else
		{
			primelist.push_back(i);
			prevsum.push_back(tcs);
		}
	}
}

void ans(ll inp)
{
	ll primeq = 0, compq;
	ll primesum = 0, compositesum;

	if (inp < 3) cout << inp - 1;
	else
	{
		ll t1 = inp, t2 = inp + 1;
		compositesum = t1 * t2 / 2;

		while (primelist[primeq] <= inp)
		{
			primesum += primelist[primeq];
			primeq++;
			if (primeq == primelist.size()) break;
		}
		compq = inp - primeq;
		compositesum -= primesum;

		ll out = 0;
		for (int i = 0; i < primeq; ++i)
		{
			ll a1 = primelist[i];
			ll a2 = prevsum[i];

			ll prevcount = a1 - i - 1;
			ll aftercount = compq - prevcount;

			ll prev = prevcount * a1 - a2;
			ll after = compositesum - a2 - aftercount * a1;

			out += prev + after;
			if (out >= cnst)
			{
				ll r = out / cnst;
				r *= cnst;
				out -= r;
			}
		}
		cout << out;
	}
}

int main()
{
	freopen("pnpdiff.inp", "r", stdin);
	freopen("pnpdiff.out", "w", stdout);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	int rqcount;
	cin >> rqcount;
	for (int i = 1; i <= rqcount; ++i)
	{
		ll temp;
		cin >> temp;
		ans(temp);
		cout << endl;
	}
	return 0;
}