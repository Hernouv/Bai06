//bai6
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xaudx.inp", "r", stdin);
	freopen("xaudx.out", "w", stdout);
	string inp;
	int c = 0;
	cin >> inp;
	for (int i = inp.size() / 2 - 1; i >= 0; --i)
		if (inp[i] != inp[inp.size() - i - 1] and inp[i] != inp[inp.size() - i - 1] - 32 and inp[i] != inp[inp.size() - i - 1] +32)
			++c;
	
	if (c == 0)
		cout << "YES";
	else
		cout << "NO";
		
	return 0;				
}