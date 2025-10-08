//bai5
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xoakta.inp", "r", stdin);
	freopen("xoakta.out", "w", stdout);
	string inp;
	vector<char> i1;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
		if (inp[i] != 'a' and inp[i] != 'A')
				i1.push_back(inp[i]);
				
	for (auto x: i1)
		cout << x;
	return 0;		
}