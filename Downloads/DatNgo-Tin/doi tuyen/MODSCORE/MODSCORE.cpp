#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("MODSCORE.inp", "r", stdin);
	freopen("MODSCORE.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n;
	cin >> n;
	int min1 = 9, min10 = 99, sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		int temp;
		cin >> temp;
		sum += temp;
		if (temp / 10) min10 = min(min10, temp);
		else min1 = min(min1, temp);
	}
	if (min1 != 9 and min10 == 99) sum += (9 - min1);
	else if (min10 != 99) sum += (9 - (min10 / 10)) * 10;
	cout << sum;
	return 0;
}