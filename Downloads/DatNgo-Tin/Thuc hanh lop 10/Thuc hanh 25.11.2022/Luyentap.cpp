#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int i = 1;
	while (i <= 100)
	{
		cout << i << ' ';
		if (i % 10 == 0)
			cout << endl;
		++i;
	}
	return 0;
}