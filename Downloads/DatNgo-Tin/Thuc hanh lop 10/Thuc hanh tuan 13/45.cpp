#include <bits/stdc++.h>
#define nmax 105
using namespace std;
long long f[nmax], t, n;

int main()
{
	f[1] = f[2] = 1;
	for (int i = 3; i <= nmax; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}