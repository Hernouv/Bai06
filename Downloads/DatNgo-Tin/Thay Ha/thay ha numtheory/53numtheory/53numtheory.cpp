#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>

ll a, b;
vector<pll> steps;

ll minimalize(ll a, ll b)
{
	if (a == 0 or b == 0)
		return 0;
	else
	{
		if (a <= b)
			return a;
		else
			return b;
	}
}

int main()
{
	freopen("numbcard.inp", "r", stdin);
	freopen("numbcard.out", "w", stdout);
	cin >> a >> b;
	do
	{
		if (abs(a) >= abs(b))
		{
			ll d = a / b;
			if (d < 0)
			{
				if (abs(a - d * b) <= abs(a - (d - 1) * b))
				{
					steps.emplace_back(1, -d);
					a = a - d * b;
				}
				else
				{
					steps.emplace_back(1, -d + 1);
					a = a - (d - 1) * b;
					
				}

			}
			else
			{
				if (abs(a - d * b) <= abs(a - (d + 1) * b))
				{
					steps.emplace_back(1, -d);
					a = a - d * b;	
				}
				else
				{
					steps.emplace_back(1, -d - 1);
					a = a - (d + 1) * b;
				}
			}
		}
		else
		{
			swap(a, b);
			ll d = a / b;
			if (d < 0)
			{
				if (abs(a - d * b) <= abs(a - (d - 1) * b))
				{
					steps.emplace_back(2, -d);
					a = a - d * b;
				}
				else
				{
					steps.emplace_back(2, -d + 1);
					a = a - (d - 1) * b;
				}

			}
			else
			{
				if (abs(a - d * b) <= abs(a - (d + 1) * b))
				{
					steps.emplace_back(2, -d);
					a = a - d * b;
				}
				else
				{
					steps.emplace_back(2, -d - 1);
					a = a - (d + 1) * b;
				}
			}
			swap(a, b);
		}
	} while (a != 0 and b != 0);

	cout << steps.size() << endl;

	for (auto x : steps)
		cout << x.first << ' ' << x.second << endl;

	return 0;
}
