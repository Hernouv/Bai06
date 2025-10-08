#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
#define u unsigned long long
string s;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> s;
	u t = 0, ans = 0, cnt = 0;
	for (int i = 0, l = s.length(); i < l; ++i)
	{
		t = (t * 10 + (cnt + 1) * (s[i] - '0')) % mod;
		ans = (ans + t) % mod;
		if (s[i] > '0')
			++cnt;
	}
	cout << ans;
	return 0;
}