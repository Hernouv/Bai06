#include <bits/stdc++.h>
using namespace std;

int i = 0;

long long power(long long a, long long n, long long m) 
{ 
	if (n == 0) return 1; 
	long long t = power(a, n / 2, m);
	t = (t * t) % m;
	if (n % 2) t = (t * a) % m;
	return t; 
}

int main()
{
	//freopen("fastpow.inp", "r", stdin);
	//freopen("fastpow.out", "w", stdout);
	long long a, n, m;
	cin >> a >> n >> m;
	cout << power(a, n, m);
	return 0;
}