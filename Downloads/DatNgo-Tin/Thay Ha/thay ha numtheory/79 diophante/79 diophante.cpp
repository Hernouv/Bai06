#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int gcd(int a, int b)
{
	while (a and b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return max(a, b);
}

int main()
{
	freopen("diophante.inp", "r", stdin);
	freopen("diophante.out", "w", stdout);
	cin >> a >> b >> c;
	if (c < a + b) cout << 0;
	else
	{
		if (a > b) swap(a, b);
		int lim = c / b;
		if (c % b == 0) lim--;
		int r = c % a, r1 = b % a;
		int rcycle = a / gcd(a, b);
		int start = 1;
		while ((r1 * start) % a != r)
		{
			start++;
			if (start == lim)
			{
				start = 0;
				break;
			}
		}
		
		if (!start) cout << 0;
		else
			cout << (lim - start) / rcycle + 1;
	}	
	return 0;
}
//36 81 1035