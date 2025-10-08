#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	cout << fixed << setprecision(0) << double(((n / k) + 1) * k);
	return 0;
}