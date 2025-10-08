#include <bits/stdc++.h>
using namespace std;

int sum;
unsigned long long arr[5001];

void display(int i)
{
	cout << arr[i] << ' ';
}

int main()
{
	//freopen("intpartion.inp", "r", stdin);
	//freopen("intpartion.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> sum;
	arr[0] = 1;
	for (int i = 1; i <= sum; ++i)
	{
		for (int j = i; j <= sum; ++j)
			arr[j] = (arr[j] + arr[j - i]) % 1000000007;
		display(i);
	}
	cout << endl << arr[sum];
	return 0;
}