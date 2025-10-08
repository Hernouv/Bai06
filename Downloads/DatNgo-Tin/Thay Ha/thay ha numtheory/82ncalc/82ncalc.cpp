#include <bits/stdc++.h>
using namespace std;

const int cnst = 3e6 + 8;

bool eratosthenes[cnst];
vector<int> res;
int out[1000001];

void sieve()
{
	for (int i = 3; i < 1733; i += 2)
		if (eratosthenes[i])
			for (int j = i * i; j < cnst; j += i)
				eratosthenes[j] = false;

	res.push_back(0);
	for (int i = 13; i < cnst; i += 6)
		if (eratosthenes[i])
			res.push_back((i - 7) / 3);
}

void resprocess()
{
	int rs = res.size();
	for (int i = 1; i < rs; ++i)
	{
		int lo = res[i - 1], hi = res[i], assignVal = i - 1;
		for (int j = lo; j < hi; ++j)
			out[j] = assignVal;
	}
}

int main()
{
	freopen("ncalc.inp", "r", stdin);
	freopen("ncalc.out", "w", stdout);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	resprocess();
	int rqcount;
	cin >> rqcount;
	for (int i = 0; i < rqcount; ++i)
	{
		int rqnum;
		cin >> rqnum;
		cout << out[rqnum] << endl;
	}
	return 0;
}