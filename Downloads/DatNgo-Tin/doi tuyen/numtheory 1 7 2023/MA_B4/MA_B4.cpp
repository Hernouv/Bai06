#include <bits/stdc++.h>
using namespace std;

int divsum[100001];
bool check[100001];

void proc()
{
	for (int i = 1; i <= 100000; ++i) divsum[i] = i - 1;
	for (int i = 2; i < 100001; ++i)
		for (int j = i * 2; j < 100001; j += i)
			divsum[j] -= i;

	for (int i = 2; i <= 100000; ++i)
		if (divsum[i] < 0) check[i] = true;
}

int main()
{
	freopen("MA_B4.INP", "r", stdin);
	freopen("MA_B4.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	proc();
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		if (check[i] == true) cnt++;
	cout << cnt;
	return 0;
}