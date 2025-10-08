#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int main()
{
	ull in;
	cin >> in;
	ull t = 0;
	while (t / 10 or in / 10)
	{
		while (in)
		{
			t += in % 10;
			in /= 10;
		}
		swap(t, in);
	}
	cout << max(t, in);
	return 0;
}