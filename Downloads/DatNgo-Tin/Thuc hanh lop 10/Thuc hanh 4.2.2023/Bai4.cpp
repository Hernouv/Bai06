//ucln va bcnn cua 2 so
#include <bits/stdc++.h>
using namespace std;

int gcf(int a, int b)
{
	while (a != 0 and b != 0)	
	{
		if (a >= b)
			a %= b;
		else 
			b %= a;	
	}
	return max(a,b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	int ucln = gcf(a, b), bcnn = a / ucln * b;
	cout << ucln << " " << bcnn;
	return 0;
}