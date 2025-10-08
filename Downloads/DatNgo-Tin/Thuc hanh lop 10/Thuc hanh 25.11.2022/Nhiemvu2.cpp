#include <bits/stdc++.h>
using namespace std;

int main()
{
	short t = 0;
	char i = 'A';
	cin.tie(0)->sync_with_stdio(false);
	while(i <= 'Z')
	{
		cout << i << ' ';
		++i;
		++t;
		if (t == 10)
		{
			cout << endl;
			t = 0;
		}
	}
	return 0;
}