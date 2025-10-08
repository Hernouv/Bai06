#include <bits/stdc++.h>
using namespace std;

#define l long long
l a, b;
int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int count(int a)
{
	int ret = 0;
	while (a) ret++, a /= 10;
	return ret;
}

int main()
{
	freopen("decfrac.inp", "r", stdin);
	freopen("decfrac.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	while (cin >> a >> b)
	{
		if (!a) cout << 0 << endl;
		else
		{
			if ((a < 0 and b > 0) or (a > 0 and b < 0)) cout << '-';
			a = abs(a), b = abs(b);
			l g = gcd(a, b);
			a /= g, b /= g;
			cout << a / b;
			a %= b;
			if (a)
			{
				cout << ".";
				l t = b;
				l e2 = 0, e5 = 0;
				while (t % 2 == 0) e2++, t /= 2;
				while (t % 5 == 0) e5++, t /= 5;
				l nonrep = max(e2, e5);
				if (nonrep)
				{
					a *= pow(10, nonrep);
					nonrep -= count(a / b);
					for (int i = 0; i < nonrep; ++i) cout << '0';
					if (a / b) cout << a / b;
					a %= b;
				}
				if (a)
				{
					cout << '(';
					a *= 10;
					cout << a / b;
					l initial = a;
					a %= b;
					while (true)
					{
						a *= 10;
						if (a == initial) break;
						cout << a / b;
						a %= b;
					}
					cout << ')';
				}
			}
			cout << endl;
		}
	}
	return 0;
}