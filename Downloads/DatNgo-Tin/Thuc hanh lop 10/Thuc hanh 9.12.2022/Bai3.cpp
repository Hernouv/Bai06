//Bai3
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xauthuong.inp", "r", stdin);
	freopen("xauthuong.out", "w", stdout);
	string inp;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
		if (inp[i] >= 'A' and inp[i] <= 'Z')
			inp[i] += 32;
	
	cout << inp;
	return 0;		
}