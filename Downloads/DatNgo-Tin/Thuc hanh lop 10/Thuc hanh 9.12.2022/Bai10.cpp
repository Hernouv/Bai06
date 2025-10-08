//Bai10
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xaudiv3.inp", "r", stdin);
	freopen("xaudiv3.out", "w", stdout);
	string inp;
	cin >> inp;
	int sum = 0;
	for (int i = 0; i < inp.size(); ++i)
		sum += (int)inp[i] - 48;
	
	if (sum % 3 == 0)	
		cout << "YES";
	else
		cout << "NO";
	
	return 0;		
} 