#include <bits/stdc++.h>
using namespace std;

int main()
{
	double inp, c = 0;
	cin >> inp;
	for (double i = 210; i <= inp; i += 210)
		c++;
	cout << inp - c;
	return 0;
}