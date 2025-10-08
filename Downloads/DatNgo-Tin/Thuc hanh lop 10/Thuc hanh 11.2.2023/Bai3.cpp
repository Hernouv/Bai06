// ucln va bcnn
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n[2];
	cin >> n[0];
	n[1] = n[0];
	for (int i = 1; i < 10; ++i)
	{
		int a;
		cin >> a;
		n[0] = gcd(n[0], a);
		n[1] = lcm(n[1], a);
	}
	
	cout << n[0] << '\n' << n[1];
	return 0;	
}