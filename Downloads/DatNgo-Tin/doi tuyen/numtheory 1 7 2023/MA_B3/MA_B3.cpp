#include <bits/stdc++.h>
using namespace std;

int inv_gcd[100001];
bool check[100001];
int cnt = 0, a, b;

int gcd(int a, int b)
{
	while (a and b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return max(a, b);
}

int inverse(int inp)
{
	int res = 0;
	while (inp) res += inp % 10, inp /= 10, res *= 10;
	return res / 10;
}

int main()
{
	freopen("MA_B3.INP", "r", stdin);
	freopen("MA_B3.OUT", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		if (i % 10) 
			if (gcd(i, inverse(i)) == 1) cnt++;
	cout << cnt;
	return 0;
}