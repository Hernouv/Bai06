#include <bits/stdc++.h>
using namespace std;

long long mcount = 0;
int main()
{
	string s;
	int t;
	cin >> t;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'M') mcount++;
	}

	long long v = 0, ans = 0, m = 0;
	for (int i = 0; i <= s.size(); ++i)
	{
		if (s[i] == 'V') v++;
		if (s[i] == 'M') m++;
		if (s[i] == 'N') ans += v * (mcount - m);
	}
	cout << ans;
	return 0;
}