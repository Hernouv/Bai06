#include <bits/stdc++.h>
using namespace std;

bool eratosthenes[100001];
int prclist[100001];
vector<int> primelist;
int rep2rq[17][100001];

int power(int inp, int exp)
{
	int ans = 1;
	for (int i = 1; i <= exp; ++i)
		ans *= inp;
	return ans;
}

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = false;
	int t = trunc(sqrt(100000));
	for (int i = 2; i <= t; ++i)
		if (eratosthenes[i])
			for (int j = i * i; j <= 100000; j += i)
				eratosthenes[j] = false;

	for (int i = 2; i <= 100000; ++i)
		if (eratosthenes[i])
			primelist.push_back(i);
}

void setVal()
{
	for (auto x : primelist)
		for (int i = x; i <= 100000; i += x)
		{
			int t = 1;
			while (i % (power(x, t)) == 0)
				t++;
			prclist[i] += t - 1;
		}
}

void rep2rqlist()
{
	for (int i = 1; i < 17; ++i)
		rep2rq[i][1] = 0;
	for (int i = 2; i < 100001; ++i)
	{
		for (int j = 1; j < 17; ++j)
			rep2rq[j][i] = rep2rq[j][i - 1];
		rep2rq[prclist[i]][i] = rep2rq[prclist[i]][i - 1] + 1;
	}
}

int l, r;
int main()
{
	freopen("kpfact.inp", "r", stdin);
	freopen("kpfact.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	setVal();
	rep2rqlist();
	
	int rqcount;
	cin >> rqcount;
	for (int i = 0; i < rqcount; ++i)
	{
		int l, r, primec;
		cin >> l >> r >> primec;
		int out = rep2rq[primec][r] - rep2rq[primec][l];
		if (rep2rq[primec][l] > rep2rq[primec][l - 1]) out++;
		cout << out << endl;
	}
	return 0;
}