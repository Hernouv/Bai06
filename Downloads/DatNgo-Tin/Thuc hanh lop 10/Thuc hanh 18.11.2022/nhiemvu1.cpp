#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> factor;

	for (int i = 1; i < sqrt(n); ++i)
		if (n % i == 0)
		{
			factor.push_back(i);
			factor.push_back(n / i);
		}

	if (sqrt(n) - int(sqrt(n)) == 0)
		factor.push_back(sqrt(n));

	sort(factor.begin(), factor.end());
	for (auto x : factor)
		cout << x << "  ";

	return 0;
}