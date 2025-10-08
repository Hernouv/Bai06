#include <bits/stdc++.h>
using namespace std;

const int cnst = 1e7;
int s[cnst + 1];
typedef pair<int, int> ii;
int p[cnst];
set<int> q;
set<int>::iterator it;

void factor(int n)
{
	int x = n;
	while (x > 1)
	{
		int v = s[x], a = 0;
		while (x % v == 0)
			a++, x /= v;
		p[v] = max(p[v], a);
		q.insert(v);
	}
}

int main()
{

	memset(p, 0, sizeof(p));

	iota(s, s + cnst + 1, 0);
	for (int i = 2; i * i <= cnst; ++i)
		if (s[i] == i)
			for (int j = i * i; j <= cnst; j += i)
				s[j] = i;
	
	int T, n;
	cin >> T;
	while (T--)
	{
		cin >> n;
		factor(n);
	}

	cout << n << " = ";
	for (auto it = q.begin(); it != q.end(); ++it)
	{
		int t = *it;
		cout << t << '^' << p[t] << ' * ';
	}
	cout << endl;

	return 0;
}