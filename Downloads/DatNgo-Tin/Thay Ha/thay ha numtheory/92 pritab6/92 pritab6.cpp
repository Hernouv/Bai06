#include <bits/stdc++.h>
using namespace std;

bool tnumadd[1000000];
int m, n, cnt = 0;
long long sum = 0, numscan;
int arr[1501][1501];
multiset<int> templist;

void sieve()
{
	tnumadd[0] = tnumadd[1] = 0;
	for (int i = 2; i < 1000; ++i)
	{
		if (tnumadd[i])
			for (int j = i * i; j < 1000000; j += i)
				tnumadd[j] = false;
	}
}

void scan1digit()
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
		{
			numscan = arr[i][j];
			if (tnumadd[numscan]) cnt += 1, sum += numscan;
		}
}

void scan2digit()
{
	//per row
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < n; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 10 + arr[i][j + 1];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per column
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m; ++j)
		{
			if (arr[j][i])
			{
				numscan = arr[j][i] * 10 + arr[j + 1][i];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per diagonal
	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 10 + arr[i + 1][j + 1];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}
}

void scan3digit()
{
	//per row
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < n - 1; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 100 + arr[i][j + 1] * 10 + arr[i][j + 2];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per column
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m - 1; ++j)
		{
			if (arr[j][i])
			{
				numscan = arr[j][i] * 100 + arr[j + 1][i] * 10 + arr[j + 2][i];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per diagonal
	for (int i = 1; i < m - 1; ++i)
		for (int j = 1; j < n - 1; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 100 + arr[i + 1][j + 1] * 10 + arr[i + 2][j + 2];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}
}

void scan4digit()
{
	//per row
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < n - 2; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 1000 + arr[i][j + 1] * 100 + arr[i][j + 2] * 10 + arr[i][j + 3];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per column
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m - 2; ++j)
		{
			if (arr[j][i])
			{
				numscan = arr[j][i] * 1000 + arr[j + 1][i] * 100 + arr[j + 2][i] * 10 + arr[j + 3][i];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per diagonal
	for (int i = 1; i < m - 2; ++i)
		for (int j = 1; j < n - 2; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 1000 + arr[i + 1][j + 1] * 100 + arr[i + 2][j + 2] * 10 + arr[i + 3][j + 3];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}
}

void scan5digit()
{
	//per row
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < n - 3; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 10000 + arr[i][j + 1] * 1000 + arr[i][j + 2] * 100 + arr[i][j + 3] * 10 + arr[i][j + 4];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per column
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m - 3; ++j)
		{
			if (arr[j][i])
			{
				numscan = arr[j][i] * 10000 + arr[j + 1][i] * 1000 + arr[j + 2][i] * 100 + arr[j + 3][i] * 10 + arr[j + 4][i];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per diagonal
	for (int i = 1; i < m - 3; ++i)
		for (int j = 1; j < n - 3; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 10000 + arr[i + 1][j + 1] * 1000 + arr[i + 2][j + 2] * 100 + arr[i + 3][j + 3] * 10 + arr[i + 4][j + 4];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}
}

void scan6digit()
{
	//per row
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j < n - 4; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 100000 + arr[i][j + 1] * 10000 + arr[i][j + 2] * 1000 + arr[i][j + 3] * 100 + arr[i][j + 4] * 10 + arr[i][j + 5];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per column
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < m - 4; ++j)
		{
			if (arr[j][i])
			{
				numscan = arr[j][i] * 100000 + arr[j + 1][i] * 10000 + arr[j + 2][i] * 1000 + arr[j + 3][i] * 100 + arr[j + 4][i] * 10 + arr[j + 5][i];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}

	//per diagonal
	for (int i = 1; i < m - 4; ++i)
		for (int j = 1; j < n - 4; ++j)
		{
			if (arr[i][j])
			{
				numscan = arr[i][j] * 100000 + arr[i + 1][j + 1] * 10000 + arr[i + 2][j + 2] * 1000 + arr[i + 3][j + 3] * 100 + arr[i + 4][j + 4] * 10 + arr[i + 5][j + 5];
				if (tnumadd[numscan]) cnt += 1, sum += numscan;
			}
		}
}


int main()
{
	freopen("pritab6.inp", "r", stdin);
	freopen("pritab6.out", "w", stdout);
	memset(tnumadd, true, sizeof(tnumadd));
	sieve();
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> arr[i][j];

	scan1digit();
	if (m > 1 or n > 1) scan2digit();
	if (m > 2 or n > 2) scan3digit();
	if (m > 3 or n > 3) scan4digit();
	if (m > 4 or n > 4) scan5digit();
	if (m > 5 or n > 5) scan6digit();

	cout << cnt << ' ' << sum;
	return 0;
}