#include <bits/stdc++.h>
#define nmax 105
using namespace std;
long long a[nmax], n, NN = 1e18;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		NN = min(NN, a[i]);
 	}
	cout << NN;
	return 0;
}