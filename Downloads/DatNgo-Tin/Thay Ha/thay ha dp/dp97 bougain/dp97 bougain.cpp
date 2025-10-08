#include <bits/stdc++.h>
using namespace std;

int n;
string inp;

int test(string in)
{
	int res = 0;
	int iter = 0;
	for (int i = 0; i < inp.length(); ++i)
		if (inp[i] == in[iter])
		{
			res++;
			iter = (iter + 1) % 3;
		}
	return res;
}

int main()
{
	freopen("bougain.inp", "r", stdin);
	freopen("bougain.out", "w", stdout);
	cin >> inp;
	n = inp.length();
	int ans = 0;
	ans = max(ans, test("WRY"));
	ans = max(ans, test("WYR"));
	ans = max(ans, test("YRW"));
	ans = max(ans, test("YWR"));
	ans = max(ans, test("RYW"));
	ans = max(ans, test("RWY"));
	cout << ans;
	return 0;
}