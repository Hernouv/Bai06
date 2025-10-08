#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("demktso.inp", "r", stdin);
	freopen("demktso.out", "w", stdout);
	int c = 0;
	string inp;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
		if (inp[i] >= '0' and inp[i] <= '9')
			++c;
			
	cout << c;
	return 0;		
}