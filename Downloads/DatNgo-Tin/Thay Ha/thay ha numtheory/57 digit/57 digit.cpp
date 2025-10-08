#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("digit.inp", "r", stdin);
	freopen("digit.out", "w", stdout);
	string base2, base3;
	int dec2 = 0, dec3 = 0;
	cin >> base2 >> base3;

	int b2s = base2.size() - 1, b3s = base3.size() - 1;
	for (int i = 0; i <= b2s; ++i)
		dec2 += (base2[i] - '0') * pow(2, b2s - i);
	for (int i = 0; i <= b3s; ++i)
		dec3 += (base3[i] - '0') * pow(3, b3s - i);

	vector<int> var;
	if (base2[0] == '0') var.push_back(dec2 + pow(2, b2s));
	else
	{
		for (int i = 1; i <= b2s; ++i)
		{
			int digit = base2[i] - '0';
			var.push_back(dec2 + (1 - 2 * digit) * pow(2, b2s - i));
		}
	}

	if (base3[0] == '0')
	{
		var.push_back(dec3 + 2 * pow(3, b3s));
		var.push_back(dec3 + pow(3, b3s));
	}
	else
	{
		var.push_back(dec3 + ((3 - 2 * (base3[0] - '0')) * pow(3, b3s)));
		for (int i = 1; i <= b3s; ++i)
		{
			int digit = base3[i] - '0';
			if (digit == 0)
			{
				var.push_back(dec3 + pow(3, b3s - i));
				var.push_back(dec3 + 2 * pow(3, b3s - i));
			}
			else if (digit == 1)
			{
				var.push_back(dec3 + pow(3, b3s - i));
				var.push_back(dec3 - pow(3, b3s - i));
			}
			else if (digit == 2)
			{
				var.push_back(dec3 - pow(3, b3s - i));
				var.push_back(dec3 - 2 * pow(3, b3s - i));
			}
		}
	}

	sort(var.begin(), var.end());
	for (int i = 1, sz = var.size(); i < sz; ++i)
		if (var[i] == var[i - 1])
		{
			cout << var[i];
			break;
		}
	return 0;
}