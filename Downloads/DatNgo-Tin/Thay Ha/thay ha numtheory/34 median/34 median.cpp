#include <bits/stdc++.h>
using namespace std;

int arr[100001];
unordered_map<int, pair<int, int>> val;
unsigned long long res = 0;

int main()
{
	freopen("median.inp", "r", stdin);
	freopen("median.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	arr[0] = 0;
	int cnt, med, cnt0 = 0;
	cin >> cnt >> med;
	for (int i = 1; i <= cnt; ++i)
	{
		int t;
		cin >> t;
		int diff = t - med;
		if (diff > 0) arr[i] = arr[i - 1] + 1;
		else if (diff < 0) arr[i] = arr[i - 1] - 1;
		else arr[i] = arr[i - 1];
		if (arr[i] == 0 and i & 1) cnt0++;
	}
	for (int i = 1; i <= cnt; i += 2)
		val[arr[i]].first++;
	for (int i = 2; i <= cnt; i += 2)
		val[arr[i]].second++;
	
	for (auto it = val.begin(), endit = val.end(); it != endit; ++it)
		res += (it->second.first) * (it->second.second);
	cout << res + cnt0;
	return 0;
}