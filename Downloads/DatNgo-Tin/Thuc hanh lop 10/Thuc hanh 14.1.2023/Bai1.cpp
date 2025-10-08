#include <bits/stdc++.h>
using namespace std;

#define n 10000005
int arr[n];

int main()
{
	freopen("MA_B2.INP", "r", stdin);
	freopen("MA_B2.OUT", "w", stdout);
	int a,b;
	cin >> a >> b;
	
	for (int i = 1; i <= 10000000; ++i)
		arr[i] = i;
		
	arr[1] = 0;
	
	for (int i = 2; i <= sqrt(n); ++i)
		if (arr[i] != 0)
			for (int j = i * i; j <= 10000000; j += i)
				arr[j] = 0;
				
	int c = 0;
	for (int i = a; i <= b; ++i)
		if (arr[i] != 0) ++c;
		
	cout << c;
	return 0;
}