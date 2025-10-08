#include <bits/stdc++.h>
using namespace std;

const int mod = 531039;


int main()
{
	int n;
	cin >> n;
	long long a = n % mod, b = (n + 1) % mod, c = (n + 2) % mod;
	long long mul = a * b * c;
	mul %= mod;
	cout << mul / 3;
	return 0;
}