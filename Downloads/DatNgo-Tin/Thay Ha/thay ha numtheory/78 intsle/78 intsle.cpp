#include <bits/stdc++.h>
using namespace std;

int a1, b1, c1, a2, b2, c2;
const double var = 1e-5;

int gcd(int inp1, int inp2)
{
	inp1 = abs(inp1);
	inp2 = abs(inp2);
	while (inp1 and inp2)
	{
		if (inp1 > inp2) inp1 %= inp2;
		else inp2 %= inp1;
	}
	return max(inp1, inp2);
}

void process(double& inp1, double& inp2)
{
	if (inp1 == 0) inp1 = 0;
	if (inp2 == 0) inp2 = 0;
}

void specialcase()
{
	int cnt0 = 0, pos;
	if (a1) cnt0++, pos = 1;
	if (b1) cnt0++, pos = 1;
	if (a2) cnt0++, pos = 2;
	if (b2) cnt0++, pos = 2;
	if (!a1 and !a2 and !b1 and !b2)
	{
		if (c1 and c2) cout << "NO SOLUTION" << endl;
		else cout << "INFINITE" << endl;
	}
	else
	{
		if (cnt0 == 3)
		{
			if (!a1)
			{
				if (c1 % b1) cout << "NO SOLUTION" << endl;
				else
				{
					int t = c2 - (c1 / b1) * b2;
					if (t % a2) cout << "NO SOLUTION" << endl;
					else cout << t / a2 << ' ' << c1 / b1 << endl;
				}
			}
			else if (!b1)
			{
				if (c1 % a1) cout << "NO SOLUTION" << endl;
				else
				{
					int t = c2 - (c1 / a1) * a2;
					if (t % b2) cout << "NO SOLUTION" << endl;
					else cout << c1 / a1 << ' ' << t / b2 << endl;
				}
			}
			else if (!a2)
			{
				if (c2 % b2) cout << "NO SOLUTION" << endl;
				else
				{
					int t = c1 - (c2 / b2) * b1;
					if (t % a1) cout << "NO SOLUTION" << endl;
					else cout << t / a1 << ' ' << c2 / b2 << endl;
				}
			}
			else if (!b2)
			{
				if (c2 % a2) cout << "NO SOLUTION" << endl;
				else
				{
					int t = c1 - (c2 / a2) * a1;
					if (t % b1) cout << "NO SOLUTION" << endl;
					else cout << c2 / a2 << ' ' << t / b1 << endl;
				}
			}
		}
		else if (cnt0 == 2)
		{
			if (!b1 and !b2)
			{
				int t1 = a1 * c2, t2 = a2 * c1;
				if (t1 and t2)
				{
					if (t1 == t2)
					{
						if (c1 % a1) cout << "NO SOLUTION" << endl;
						else cout << "INFINITE" << endl;
					}
					else cout << "NO SOLUTION" << endl;
				}
				else if (!t1 or !t2)
				{
					if ((c1 % a1 or c2 % a2) or (!c1 and c2) or (c1 and !c2)) cout << "NO SOLUTION" << endl;
					else cout << "INFINITE" << endl;
				}
			}
			else if (!a1 and !a2)
			{
				int t1 = b1 * c2, t2 = b2 * c1;
				if (t1 and t2)
				{
					if (t1 == t2)
					{
						if (c1 % b1) cout << "NO SOLUTION" << endl;
						else cout << "INFINITE" << endl;
					}
					else cout << "NO SOLUTION" << endl;
				}
				else if (!t1 or !t2)
				{
					if ((c1 % b1 or c2 % b2) or (!c1 and c2) or (c1 and !c2)) cout << "NO SOLUTION" << endl;
					else cout << "INFINITE" << endl;
				}
			}
			else if (!a2 and !b1)
			{
				if (c2 % b2 or c1 % a1) cout << "NO SOLUTION" << endl;
				else cout << c1 / a1 << ' ' << c2 / b2 << endl;
			}
			else if (!a1 and !b2)
			{
				if (c1 % b1 or c2 % a2) cout << "NO SOLUTION" << endl;
				else cout << c2 / a2 << ' ' << c1 / b1 << endl;
			}
			else if (!a2 and !b2)
			{
				if (c2) cout << "NO SOLUTION" << endl;
				else
				{
					if (c1 % gcd(a1, b1)) cout << "NO SOLUTION" << endl;
					else cout << "INFINITE" << endl;
				}
			}
			else if (!a1 and !b1)
			{
				if (c1) cout << "NO SOLUTION" << endl;
				else
				{
					if (c2 % gcd(a2, b2)) cout << "NO SOLUTION" << endl;
					else cout << "INFINITE" << endl;
				}
			}
		}
		else if (cnt0 == 1)
		{
			if (pos == 1)
			{
				if (c1 % max(abs(a1), abs(b1)) == 0 and !c2) cout << "INFINITE" << endl;
				else cout << "NO SOLUTION" << endl;
			}
			else if (pos == 2)
			{
				if (c2 % max(abs(a2), abs(b2)) == 0 and !c1) cout << "INFINITE" << endl;
				else cout << "NO SOLUTION" << endl;
			}
		}
	}
}

int main()
{
	int setcnt;
	cin >> setcnt;
	for (int i = 0; i < setcnt; ++i)
	{
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
		if (!a1 or !b1 or !a2 or !b2) specialcase();
		else
		{
			double f1 = double(a1) / a2, f2 = double(b1) / b2, f3;
			if (!c1 or !c2) f3 = 0;
			else f3 = double(c1) / c2;
			//cout << f1 << ' ' << f2 << ' ' << f3 << endl;
			if ((f1 == f2 and f2 == f3) or (f1 == f2 and !c1 and !c2))
			{
				if (c1 % gcd(a1, b1)) cout << "NO SOLUTION" << endl;
				else cout << "INFINITE" << endl;
			}
			else if (f1 == f2 and f2 != f3) cout << "NO SOLUTION" << endl;
			else
			{
				double x, y;
				y = (c2 * f1 - c1) / (b2 * f1 - b1);
				x = (c2 - b2 * y) / a2;
				process(x, y);
				int intx = x > 0 ? x + 0.5 : x - 0.5, inty = y > 0 ? y + 0.5 : y - 0.5;
				if ((abs(x - intx) <= var or abs(x + intx) <= var) and (abs(y - inty) <= var or abs(y + inty) <= var)) cout << intx << ' ' << inty << endl;
				else cout << "NO SOLUTION" << endl;
			}
		}
	}
	return 0;
}