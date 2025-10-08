#include <bits/stdc++.h>
using namespace std;

set<long long> divisor;

int main()
{
	long long in;
	cin >> in;
	for (long long i = 1; i * i <= in; ++i)
	{
		if (in % i == 0)
		{
			divisor.insert(in / i);
			divisor.insert(i);
		}
	}
	for (auto it : divisor) cout << it << ' ';
	return 0;
}