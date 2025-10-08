#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("bai5.inp.txt", "r", stdin);
	freopen("bai5.out.txt", "w", stdout);
	int n, x, c = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; ++i)
		if (x % i == 0)
			if (x / i <= n)
				c++;
	cout << c;
	return 0;
}