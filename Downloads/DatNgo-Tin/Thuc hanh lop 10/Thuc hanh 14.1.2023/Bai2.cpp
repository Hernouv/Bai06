#include <bits/stdc++.h>
using namespace std;

void friendlynum(int a, int b)
{
	int c = 0;
	for (int i = a; i <= b; ++i)
	{
		int rev = 0, t = i;
		while (t > 0)
		{
			rev += t%10;
			rev *= 10;
			t /= 10;
		}
		if (__gcd(rev,i) == 1) cout << i << rev;
	}
}

int main()
{
	int a, b;
	cin >> a >> b;
	friendlynum(a, b);
	return 0;
}