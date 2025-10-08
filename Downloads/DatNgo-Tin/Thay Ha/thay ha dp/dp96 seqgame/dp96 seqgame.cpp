#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int n, k;
int score[10001], res[10001];

int main()
{
	freopen("seqgame.inp", "r", stdin);
	freopen("seqgame.out", "w", stdout);
	memset(res, 0, sizeof(res));
	score[0] = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> score[i];

	for (int i = 1; i <= n; ++i)
	{
		res[i] = res[i - 1] + score[i];
		for (int j = i - k; j < i - 1; ++j)
			res[i] = max(res[i], res[j] + score[i]);
	}

	sort(res + 1, res + 1 + n, greater<int>());

	cout << res[1];
	return 0;
}