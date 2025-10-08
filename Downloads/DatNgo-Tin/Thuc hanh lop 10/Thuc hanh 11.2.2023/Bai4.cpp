//goc boi
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull muldigit(string a)
{
	unsigned long long n = 1;
	for (int i = 0; i < a.size(); ++i)
		n *= int(a[i]) - 48;
	
	return n;
}

int main()
{
	string a;
	ull res;
	short c = 1;
	cin >> a;
	if (a.size() == 1) cout << 0;
	else
	{
		res = muldigit(a);
		while (res >= 10)
		{
			stringstream temp;
			temp << res;
			a = temp.str();
			res = muldigit(a);
			++c;
		}
	}
	
	cout << c;
	return 0;
}