#include <bits/stdc++.h>
using namespace std;

int list[1000000];

int main()
{
	int list[200];
	int n;
	cin >> n;
	
	if (n <= 1)
		cout << -1;
		
	else
	{
		for (int i = 0; i < n; ++i)
			cin >> list[i];
		
		int m = list[0];
		for (int i = 1; i < n; ++i)
			m = min(m, list[i]);
		
		int m1[2];
		m1[0] = list[0];
		m1[1] = 0;
		for (int i = 1; i < n; ++i)
			if (list[i] != m)
			{
				m1[0] = min(m1[0], list[i]);
				if (m1[0] == list[i]) m1[1] = i;
			}
			
		cout << m1[0] << ' ' << m1[1];	
	}
	return 0;
}