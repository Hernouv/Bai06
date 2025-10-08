#include <bits/stdc++.h>
using namespace std;

int factor[1000001];

int main()
{
	memset(factor, 0, sizeof(factor));
    int n;
    cin >> n;
    int tmax;
    
    for(int i = 2; i <= n; i++)
	{
        while(n % i == 0)
		{
            factor[i]++;
            n /= i;
        }
        tmax = i;
    }

	for (int i = 2; i < tmax; i++)
	{
		if (factor[i] == 1)
			cout << i << " * ";
		else if (factor[i] > 1)
			cout << i << "^" << factor[i] << " * ";	
	}
	if (factor[tmax] == 1) cout << tmax;
	else if (factor[tmax] > 1) cout << tmax << "^" << factor[tmax];
	
	int c = 0, c1 = 0;
	for (int i = 2; i <= tmax; ++i)
		if (factor[i] > 0)
		{ 
			++c;
			c1 += factor[i];
		}
		
	cout << "\nso uoc: " << c;
	cout << "\ntong uoc: " << c1;
	
	
	return 0;
}