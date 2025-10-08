#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	unsigned long n;
	cin >> n;
	double s = 0;
	
	for (int i = 1; i <= n; ++i)
		s += i*i*i;
	
	cout << fixed << setprecision(0) << s;	
}