#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int cnst = 1e7 - 2;
bool eratosthenes[cnst];
vector<int> primelist;
vector<pair<ll, int>> factorization;
vector<pair<int, int>> res;
ll in;
int cnt = 0;

void sieve()
{
	for (int i = 3; i < 3163; i += 2)
		if (eratosthenes[i])
			for (int j = i * i; j < cnst; j += i)
				eratosthenes[j] = false;

	primelist.push_back(2);
	for (int i = 3; i < cnst; i += 2)
		if (eratosthenes[i]) primelist.push_back(i);
}

void factor(ll inp)
{
	for (int i = 0; primelist[i] * primelist[i] <= inp; ++i)
	{
		if (inp % primelist[i] == 0)
		{
			int exp = 0;
			while (inp % primelist[i] == 0)
			{
				inp /= primelist[i];
				exp++;
			}
			factorization.emplace_back(primelist[i], exp);
			cnt++;
		}
	}
	if (inp > 1) factorization.emplace_back(inp, 1), cnt++;
}

void process()
{
	int common_exp = factorization[0].second;
	if (common_exp == 1)
		cout << 0;
	else
	{
		for (int i = 1; i < cnt; ++i)
			if (factorization[i].second != common_exp)
			{
				common_exp = 0;
				break;
			}

		if (common_exp)
		{

			int base = 1;
			for (int i = 0; i < cnt; ++i)
				base *= factorization[i].first;

			set<int> divisorlist;
			divisorlist.insert(1);
			for (int i = 2; i <= sqrt(common_exp); ++i)
				if (common_exp % i == 0)
				{
					divisorlist.insert(i);
					divisorlist.insert(common_exp / i);
				}

			for (auto x : divisorlist)
				res.emplace_back(pow(base, x), common_exp / x);
			reverse(res.begin(), res.end());
			cout << divisorlist.size() << endl;
			for (auto x : res)
				cout << x.first << ' ' << x.second << endl;
		}
		else cout << 0;
	}
}

int main()
{
	freopen("powerlst.inp", "r", stdin);
	freopen("powerlst.out", "w", stdout);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	cin >> in;
	factor(in);
	process();
	return 0;
}