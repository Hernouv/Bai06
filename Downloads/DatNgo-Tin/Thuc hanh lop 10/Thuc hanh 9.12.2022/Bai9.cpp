//bai9
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("demtu.inp", "r", stdin);
	freopen("demtu.out", "w", stdout);
	string inp, i1 = " ";
	getline(cin, inp);
	string i2 = inp + i1;
	int c = 0;
	for (int i = 0; i < i2.size(); ++i)
		if (i2[i] != ' ' and i2[i + 1] == ' ')
			++c;
	
	cout << c;
	return 0;		
}