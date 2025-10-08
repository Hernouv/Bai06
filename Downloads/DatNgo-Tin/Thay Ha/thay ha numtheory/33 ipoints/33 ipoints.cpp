#include <bits/stdc++.h>
using namespace std;
int vectx, vecty, minvect;
set<pair<int, int>> ipoint;

int gcd(int x, int y)
{
	if (!y) return x;
	return gcd(y, x % y);
}

int main()
{
	freopen("ipoints.inp", "r", stdin);
	freopen("ipoints.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		vectx = u - x;
		vecty = v - y;
		minvect = gcd(abs(vectx), abs(vecty));
		vectx /= minvect;
		vecty /= minvect;

		if (x >= u and y >= v)
		{
			while (x >= u and y >= v)
			{
				ipoint.emplace(x, y);
				x += vectx;
				y += vecty;
			}
		}
		else if (x <= u and y <= v)
		{
			while (x <= u and y <= v)
			{
				ipoint.emplace(x, y);
				x += vectx;
				y += vecty;
			}
		}
		else if (x >= u and y <= v)
		{
			while (x >= u and y <= v)
			{
				ipoint.emplace(x, y);
				x += vectx;
				y += vecty;
			}
		}
		else if (x <= u and y >= v)
		{
			while (x <= u and y >= v)
			{
				ipoint.emplace(x, y);
				x += vectx;
				y += vecty;
			}
		}
	}
	cout << ipoint.size();
	return 0;
}