#include <bits/stdc++.h>
using namespace std;

long f[20000007];
long long sum = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i * i <= n; ++i)
		for (int j = 0; j * j <= n - i * i; ++j)
			f[i * i + j * j]++;
	for (int i = 0; i <= n; ++i)
		sum += f[i] * f[n-i];
	cout << sum;
	return 0;
}