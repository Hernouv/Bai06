//so phong phu
#include <bits/stdc++.h>
using namespace std;

bool prime[1003];

int main()
{
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= sqrt(1003); ++i)
		if (prime[i] == true)
			for (int j = i*i; j <= 1003; j += i)
				prime[j] = false;
	int l,r, c = 0;
	cin >> l >> r;
	for (int i = l; i <= r; ++i)
		if (prime[i] == false)
		{
			int c1 = 1;
			for (int j = 2; j < sqrt(i); ++j)
				if (i % j == 0)
					c1 += j + i/j;
			if (sqrt(i) - int(sqrt(i)) == 0)
				c1 += sqrt(i);
			if (c1 > i) ++c;
		}
	cout << c;
	return 0;	
}