#include <bits/stdc++.h>
using namespace std;

int a, b, intPart, nonrepdec, repdec, curr_rem;

int analyze25(int inp)
{
	int c2 = 0, c5 = 0;
	while (inp % 2 == 0)
	{
		c2++;
		inp /= 2;
	} 

	while (inp % 5 == 0)
	{
		c5++;
		inp /= 5;
	} 
	return max(c2, c5);
}

int main()
{
	//freopen("decfrac.inp", "r", stdin);
	//freopen("decfrac.out", "w", stdout);
	while (cin >> a >> b)
	{
		if ((a < 0 and b > 0) or (a > 0 and b < 0)) std::cout << '-';
		a = abs(a), b = abs(b);
		std::cout << a / b;
		a %= b;
		if (a != 0)
		{
			std::cout << '.';
			int multiplier = analyze25(b);
			if (multiplier)
			{
				for (int i = 1; i <= multiplier; ++i)
					a *= 10;
				std::cout << a / b;
				a %= b;
			}

			if (a)
			{
				int initial_rem = a;
				std::cout << '(';
				while (true)
				{
					a *= 10;
					std::cout << a / b;
					a %= b;
					if (a == initial_rem) break;
				}
				std::cout << ')';
			}
		}
		std::cout << endl;
	}
	return 0;
}