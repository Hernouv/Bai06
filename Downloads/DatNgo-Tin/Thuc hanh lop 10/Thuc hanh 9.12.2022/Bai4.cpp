//bai4
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("swap.inp", "r", stdin);
	freopen("swap.out", "w", stdout);
	string inp;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
		if (inp[i] >= 'a' and inp[i] <= 'z')
			inp[i] -= 32;
		else if (inp[i] >= 'A' and inp[i] <= 'Z')
			inp[i] += 32;	
			
	cout << inp;
	return 0;		
}