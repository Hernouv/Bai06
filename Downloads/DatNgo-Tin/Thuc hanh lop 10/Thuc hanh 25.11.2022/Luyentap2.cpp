#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int i = 0, counter = 0;
	while (i < 100)
	{
		if (i % 5 == 0 or i % 3 == 1)
			++counter;
		++i;
	}
	cout << counter;
	return 0; 
}