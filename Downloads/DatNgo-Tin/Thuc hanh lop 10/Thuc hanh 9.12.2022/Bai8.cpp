//bai8
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("ktpb.inp", "r", stdin);
	freopen("ktpb.out", "w", stdout);	
	string inp;
	cin >> inp;
	set<char> out;
	for (int i = 0; i < inp.size(); ++i)
		out.insert(inp[i]);
		
	cout << out.size();
	return 0;	
}