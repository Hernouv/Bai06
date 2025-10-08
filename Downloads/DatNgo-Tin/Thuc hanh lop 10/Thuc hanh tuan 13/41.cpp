#include <bits/stdc++.h>
#define nmax 105
using namespace std;
long long a[nmax], n, S = 0;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		S += a[i];
 	}
	cout << S;
	return 0;
}