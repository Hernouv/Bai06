//bai1
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("demkta.inp", "r", stdin);
	freopen("demkta.out", "w", stdout);
	string inp;
	int c = 0;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
		if (inp[i] == 'a' or inp[i] == 'A')
			++c;
			
	cout << c;
	return 0;		
}