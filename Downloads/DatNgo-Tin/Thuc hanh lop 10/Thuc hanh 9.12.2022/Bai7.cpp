//bai7
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("dayngoac.inp", "r", stdin);
	freopen("dayngoac.out", "w", stdout);
	string inp;
	int c1 = 0, c2 = 0, count = 0;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
	{
		if (inp[i] == '(')
			++c1;
		else if (inp[i] == ')')
			++c2;
		if (c1 < c2) ++count;	
	}
	
	if (count != 0) 
		cout << "NO";
	else
		if (c1 == c2) 
			cout << "YES";
		else 
			cout << "NO";
		
	return 0;	
}