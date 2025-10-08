#include <bits/stdc++.h>
using namespace std;

int a[10005];

void selection(int n)
{
	int k, mi;
	for (int i = 1; i < n; ++i)
	{
		mi = a[i];
		for (int j = i + 1; j <= n; ++j)
			if (a[j] < mi)
			{
				mi = a[j];
				k = j;
			}
		if (a[i] != mi)
			swap(a[i], a[k]);
	}
}

void insertion(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		int j = i;
		while ((j > 1) and (a[j] < a[j - 1]));
		{
			swap(a[j], a[j - 1]);
			--j;
		}
	}	
}

void bubble(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = n; j >= i + 1; --j)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
	}
}

void quick(int l, int r)
{
	int x, i = l, j = r;
	x = a[(i + j)/2];
	while (i <= j)
	{
		while (a[i] < x) ++i;
		while (a[j] > x) --j;
		if (i <= j)
		{
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
}

int main()
{
	int n, t;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cout << "1. Selection Sort \n2. Insertion Sort \n3. Bubble Sort \n4. Quick Sort \nChoose:";
	cin >> t;
	if (t == 1) selection(n);
	else if (t == 2) insertion(n);
	else if (t == 3) bubble(n);
	else if (t == 4) quick(1,n);
	for (int i = 1; i <= n; ++i)
		cout << a[i] << '\n';
	return 0;
}