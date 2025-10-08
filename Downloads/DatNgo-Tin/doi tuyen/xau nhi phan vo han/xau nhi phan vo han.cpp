#include <bits/stdc++.h>
using namespace std;

int p;

int process(int p)
{
	int t = 30, k = 0;
	while (t >= 1)
	{
		if (p > (1 << t)) p -= (1 << t), k++;
		t--;
	}
	return (p + k) % 2;
}

int main()
{
	freopen("bdigit.inp", "r", stdin);
	freopen("bdigit.out", "w", stdout);
	int n;
	vector<char> res;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p;
		res.push_back(char(process(p) + 48));
	}
	for (auto x : res)
		cout << x;
	return 0;
}