#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
	freopen("MA_B8.INP", "r", stdin);
	freopen("MA_B8.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		ull inp;
		cin >> inp;
		ull a = inp;
		ull b = inp + 1;
		ull c = 2 * inp + 1;
		ull mul = (a * b * c) / 6;
		cout << mul << '\n';
	}
	return 0;
}
