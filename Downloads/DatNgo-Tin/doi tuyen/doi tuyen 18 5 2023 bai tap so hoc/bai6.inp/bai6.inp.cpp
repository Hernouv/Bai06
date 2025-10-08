#include <bits/stdc++.h>
using namespace std;

bool check = false;

int main()
{
	int n;
	cin >> n;
	vector<int> t;
	for (int i = 1; i <= n; ++i)
	{
		int a;
		cin >> a;
		t.push_back(a);
	}
	sort(t.begin(), t.end());
	for (int i = 2; i != t.size(); ++i) 
		if (t[i] % t[0] == 0)
		{
			check = true;
			break;
		}
	if (check) cout << t[0];
	else cout << -1;
	return 0;
}