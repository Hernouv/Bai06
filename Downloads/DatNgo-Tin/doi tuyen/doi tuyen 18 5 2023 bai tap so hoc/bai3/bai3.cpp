#pragma warning (disable: 4996)
#include <bits/stdc++.h>
using namespace std;

int arr[10001], sum = 0;
bool check = false;

int main()
{
	freopen("bai3.inp.txt", "r", stdin);
	freopen("bai3.out.txt", "w", stdout);
	string n;
	cin >> n;
	for (int i = 0; i < n.size(); ++i)
	{
		arr[i] = int(n[i]) - 48;
		sum += arr[i];
	}
	
	for (auto x: arr)
		if (x == 0)
		{
			check = true;
			break;
		}

	if (sum % 3 == 0 and check)
	{
		sort(arr, arr + n.size(), greater<int>());
		for (int i = 0; i < n.size(); ++i)
			cout << arr[i];
	}
	else if (sum % 3 != 0 or !check) cout << -1;
	return 0;
}