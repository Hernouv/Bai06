#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	
	int n, counter = 0;
	cin >> n;
	
	for (int i = 1; i < sqrt(n); ++i)
		if (n % i == 0)
			counter += 2;
			
	if (sqrt(n) - int (sqrt(n)) == 0) 
		++counter;
		
	cout << counter;
		
	return 0;			
}