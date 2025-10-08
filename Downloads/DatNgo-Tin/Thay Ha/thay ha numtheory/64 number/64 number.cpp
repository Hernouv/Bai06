#include <bits/stdc++.h>
using namespace std;

vector<int> digit;
int initial_d, mul;

int main()
{
	freopen("number.inp", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> initial_d >> mul)
	{
		digit.clear();
		int x = initial_d;
		int proc = 0;
		while (true)
		{
			int t = x * mul + proc;
			digit.push_back(t % 10);
			if (t == initial_d) break;
			proc = t / 10;
			x = t % 10;
		}
		digit.pop_back();
		reverse(digit.begin(), digit.end());
		if (digit[0] == 0) cout << -1 << endl;
		else
		{
			for (auto a : digit)
				cout << a;
			cout << initial_d << endl;
		}
	}
	return 0;
}