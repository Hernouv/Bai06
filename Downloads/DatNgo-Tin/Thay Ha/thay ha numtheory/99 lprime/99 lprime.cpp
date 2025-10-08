#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll inp, res;

bool checkPrime(ll inVal)
{
	for (ll i = 2; i <= trunc(sqrt(inVal)); ++i)
	{
		if (inVal % i == 0)
			return false;
	}
	return true;
}

int main()
{
	freopen("lprime.inp", "r", stdin);
	freopen("lprime.out", "w", stdout);
	cin >> inp;
	for (ll i = inp; i >= inp / 2; --i)
		if (checkPrime(i))
		{
			res = i;
			break;
		}
	cout << res;
	return 0;
}