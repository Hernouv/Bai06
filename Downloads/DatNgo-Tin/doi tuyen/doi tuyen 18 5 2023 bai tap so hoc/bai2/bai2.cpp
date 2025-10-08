#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int seq[30001], _count = 0;

int main()
{
	freopen("bai2.inp.txt", "r", stdin);
	freopen("bai2.out.txt", "w", stdout);
	string inp;
	cin >> inp;
	for (int i = inp.size() - 1; i >= 0; --i)
		seq[i] = int(inp[i]) - 48;

	for (int i = 0; i < inp.size(); ++i)
		if (seq[i] % 4 == 0)
			_count++;

	for (int i = 1; i < inp.size(); ++i)
		if ((seq[i - 1] * 10 + seq[i]) % 4 == 0)
			_count += i;

	cout << _count;
	return 0;
}
