#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
ull sum, miss = 0;
bool eratosthenes[1000001];
vector<ull> primelist, e(1000000, 0);
ull nodecnt;

void sieve(ull a)
{
	for (ull i = 3; i <= floor(sqrt(a)); i += 2)
		if (!eratosthenes[i])
			for (ull j = i * i; j <= a; j += i)
				eratosthenes[j] = true;

	primelist.push_back(2);
	for (ull i = 3; i <= a; i += 2)
		if (!eratosthenes[i])
			primelist.push_back(i);

}

ull pwrmod(ull base, ull exp)
{
	if (!exp) return 1;
	ull temp = pwrmod(base, exp / 2);
	temp = fmod(temp * temp, 1000000007);
	if (exp & 1) temp = fmod(temp * base, 1000000007);
	return temp;
}

ull combination(ull a, ull b)
{
	ull res = 1;
	ull sz = primelist.size();
	for (ull i = 0; i < sz; ++i)
	{
		ull x = primelist[i];
		while (a / x)
		{
			e[i] += a / x;
			x *= primelist[i];
		}
	}

	for (ull i = 0; i < sz and primelist[i] <= b; ++i)
	{
		ull x = primelist[i];
		while (b / x)
		{
			e[i] -= b / x;
			x *= primelist[i];
		}
	}

	ull t = a - b;
	for (ull i = 0; i < sz and primelist[i] <= t; ++i)
	{
		ull x = primelist[i];
		while (t / x)
		{
			e[i] -= t / x;
			x *= primelist[i];
		}
	}

	for (ull i = 0; i < sz; ++i)
		if (e[i] > 0)
			res = fmod(res * pwrmod(primelist[i], e[i]), 1000000007);

	return res;
}

int main()
{
	cin >> nodecnt;
	sum = 2 * (nodecnt - 1);
	for (ull i = 0; i < nodecnt; ++i)
	{
		ull temp;
		cin >> temp;
		if (temp == -1) miss++;
		else if (temp > 0) sum -= temp;
	}
	sum--, miss--;
	if (miss * 2 > sum) miss = sum - miss;
	sieve(sum);
	cout << combination(sum, miss);
	return 0;
}