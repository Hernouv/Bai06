#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	string inp;
	cin >> n >> inp;
	int t1 = 0, t2 = 1, t3;
	for (int i = 1; i < n; ++i)
	{
		if (inp[i] == inp[i - 1])
			t3 = t2 + 1;
		else
			t3 = min(t1, t2) + 1;
		t1 = t2, t2 = t3; // push_back
	}
	cout << t3;
	return 0;
}