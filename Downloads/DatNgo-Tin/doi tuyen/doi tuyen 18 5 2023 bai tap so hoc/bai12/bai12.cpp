#include <bits/stdc++.h>
using namespace std;

vector<int> nlist[5], mlist[5];

int main()
{
	int n, m;
	long long res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		nlist[i % 5].push_back(i);

	for (int i = 1; i <= m; ++i)
		mlist[i % 5].push_back(i);

	for (int i = 0; i < 5; ++i)
		res += nlist[i].size() * mlist[4 - i].size();

	cout << res;
	return 0;
}