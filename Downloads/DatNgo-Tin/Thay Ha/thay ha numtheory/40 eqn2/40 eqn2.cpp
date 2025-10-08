#include <bits/stdc++.h>
using namespace std;

double a, b, c, delta;

int main()
{
	freopen("eqn2.inp", "r", stdin);
	freopen("eqn2.out", "w", stdout);
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	if (delta < 0) cout << "NO SOLUTION";
	else if (delta == 0) cout << fixed << setprecision(4) << -b / 2 / a;
	else 
		if (a < 0) cout << fixed << setprecision(4) << (-b + sqrt(delta)) / 2 / a << endl << (-b - sqrt(delta))/ 2 / a;
		else cout << fixed << setprecision(4) << (-b - sqrt(delta)) / 2 / a << endl << (-b + sqrt(delta)) / 2 / a;
	return 0;
}
