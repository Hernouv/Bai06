#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("eogroup.inp", "r", stdin);
	freopen("eogroup.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	vector <int> oelist[2];
	int numcnt, res = 0;
	cin >> numcnt;
	for (int i = 0; i < numcnt; ++i)
	{
		int temp;
		cin >> temp;
		oelist[temp & 1].push_back(temp);
	}
	int es = oelist[0].size(), os = oelist[1].size();
	int m = min(es, os);
	res += 2 * m;
	es -= m, os -= m;
	if (!os and es) res++;
	else if (os and !es)
	{
		res += (os / 3) * 2;
		os %= 3;
		if (os == 1) res--;
		else if (os == 2) res++;
	}
	cout << res;
	return 0;
}