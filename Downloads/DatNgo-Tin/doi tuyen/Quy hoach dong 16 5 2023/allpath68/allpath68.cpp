#include <bits/stdc++.h>
using namespace std;

#define const 1003
#define ii pair<int, int>
long long sum = 0;
ii r[const], b[const];
int fee[const][const][2], m, n;

int dist(ii r, ii b)
{
	return (r.first - b.first) * (r.first - b.first) + (r.second - b.second) * (r.second - b.second);
}

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int main()
{
	memset(fee, 0x3f, sizeof(fee));
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2; 
		r[i] = make_pair(t1, t2);
	}

	for (int i = 1; i <= n; ++i)
	{
		int t1, t2;
		cin >> t1 >> t2;
		b[i] = make_pair(t1, t2);
	}

	fee[1][0][0] = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j <= n; ++j)
		{
			fee[i][j][0] = min(fee[i][j][0], fee[i - 1][j][0] + dist(r[i - 1], r[i]), fee[i - 1][j][1] + dist(b[j], r[i]));
			if (j > 0) fee[i][j][1] = min(fee[i][j][1], fee[i][j - 1][1] + dist(b[i - 1], b[i]), fee[i][j - 1][0] + dist(b[j], r[i]));
		}
	cout << fee[m][n][0];
	return 0;
}
