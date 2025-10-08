#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
bool erastos[10000001];
vector<ull> prlist;
unordered_map<ull, ull> pfact;
void sieve()
{
	for (ull i = 2; i * i <= 10000001; ++i)
	{
		if (!erastos[i])
		{
			prlist.push_back(i);
			for (ull j = i * i; j <= 1000001; j += i)
				erastos[j] = true;
		}
	}
}

int main()
{
	sieve();
	ull m, n;
	cin >> m >> n;
	m += n;
	for (int i = 0; prlist[i] <= m; ++i)
	{
		ull pr = prlist[i];
		while (m / pr)
		{
			pfact[prlist[i]] += m / pr;
			pr *= prlist[i];
		}
	}
	
	for (int i = 0; prlist[i] <= n; ++i)
	{
		ull pr = prlist[i];
		while (n / pr)
		{
			pfact[prlist[i]] -= n / pr;
			pr *= prlist[i];
		}
	}

	m -= n;
	for (int i = 0; prlist[i] <= m; ++i)
	{
		ull pr = prlist[i];
		while (m / pr)
		{
			pfact[prlist[i]] -= m / pr;
			pr *= prlist[i];
		}
	}

	for (auto it : pfact)
		cout << it.first << ' ' << it.second << '\n';
	return 0;
}