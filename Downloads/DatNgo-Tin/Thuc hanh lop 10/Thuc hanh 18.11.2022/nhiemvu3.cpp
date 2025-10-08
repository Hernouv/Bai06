#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	unsigned int n;
	double res = 1;
	
	cin >> n;
	
	for (int i = 1; i <= n; ++i)
		res*= i;
		
	cout << fixed << setprecision(0) << res;
}