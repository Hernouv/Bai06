#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	for (int x = 1 ; x < 100; ++x)
		for (int y = 1; y <= 100 - x; ++y)
		{
			int z = 100 - x - y;
			if (5*x + 3*y + z/3.0 == 100.0)
				cout << x << " " << y << " " << z << endl;
		}
	
	return 0;
}