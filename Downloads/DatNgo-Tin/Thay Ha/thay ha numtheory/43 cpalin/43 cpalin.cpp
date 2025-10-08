#include <bits/stdc++.h>
using namespace std;

#define u unsigned long long
string s;
u pref_sum[300001][26];

int main()
{
	freopen("cpalin.inp", "r", stdin);
	freopen("cpalin.out", "w", stdout);
	cin >> s;
	int l = s.length();
	u ans = 0;
	for (int i = 1; i <= l; ++i)
	{
		for (int j = 0; j < 26; ++j)
			pref_sum[i][j] = pref_sum[i - 1][j];
		pref_sum[i][s[i - 1] - 'a']++;
	}
	for (int i = 1; i < l - 1; ++i)
		for (int j = 0; j < 26; ++j)
			ans += pref_sum[i][j] * (pref_sum[l][j] - pref_sum[i + 1][j]);

	cout << ans;
	return 0;
}