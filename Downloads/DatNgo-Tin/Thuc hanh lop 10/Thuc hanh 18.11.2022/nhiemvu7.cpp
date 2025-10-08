#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int a = 1, b = 35;
	
	while (2*a + 4*b != 100)
	{
		++a;
		--b;
	} 
	
	cout << a << " " << b;
}