#include <bits/stdc++.h>
using namespace std;

const float cnst = 7 + 1e9;

int main()
{
	freopen("SQSUM.inp", "r", stdin);
	freopen("SQSUM.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	float a, b;
	cin >> a >> b;
	a = ceil(a) - 1, b = floor(b);
	float r1a, r2a, r3a, r1b, r2b, r3b;;
	r1a = fmod(a, cnst);
	r2a = fmod(a + 1, cnst);
	r3a = fmod(2 * a + 1, cnst);
	r1b = fmod(b, cnst);
	r2b = fmod(b + 1, cnst);
	r3b = fmod(2 * b + 1, cnst);
	float lo = (r1a * r2a * r3a) / 6;
	float hi = (r1b * r2b * r3b) / 6;
	if (hi < lo) hi += cnst;
	cout << fixed << setprecision(0) << hi - lo;
	return 0;
}