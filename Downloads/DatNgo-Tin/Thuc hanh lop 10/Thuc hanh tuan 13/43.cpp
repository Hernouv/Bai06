#include <bits/stdc++.h>
#define nmax 1000
using namespace std;

int main()
{
	int a[nmax], n, S = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		if (a[i] % 2 == 0) S += a[i];
		
	cout << S;
	return 0;	
}