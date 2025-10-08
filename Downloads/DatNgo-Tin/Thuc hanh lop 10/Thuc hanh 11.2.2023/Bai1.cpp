//fib
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long f[2];
	f[0] = 0, f[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		f[i % 2] = f[0] + f[1];
	
	cout << f[n % 2];
	return 0;
}