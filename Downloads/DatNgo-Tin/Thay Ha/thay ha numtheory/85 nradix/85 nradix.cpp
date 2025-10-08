#include <bits/stdc++.h>
using namespace std;

string rq, inp;

void bwconvert()
{
	int base = 0, num = 0;
	for (short i = 5; i < rq.size(); ++i)
	{
		base *= 10;
		base += rq[i] - '0';
	}
	base -= 2 * base;
		
	int l = inp.size() - 1;
	for (int i = 0; i <= l; ++i)
		num += (inp[i] - '0') * pow(base, l - i);
	cout << num;
}

void fwconvert()
{
	int base = 0, num = 0;
	stack<int> convert;
	for (short i = 3; i < rq.size(); ++i)
	{
		base *= 10;
		base += rq[i] - '0';
	}

	short a = 0;
	if (inp[0] == '-') a++;
	for (short i = a; i < inp.size(); ++i)
	{
			num *= 10;
			num += inp[i] - '0';
	}

	if (num)
	{
		int checkeven = 1;
		if (a) checkeven = 0;
		while (num / base or num % base)
		{
			int r = num % base;
			if (checkeven or !r)
			{
				convert.push(r);
				num /= base;
			}
			else
			{
				convert.push(base - r);
				num += base - r;
				num /= base;
			}
			checkeven = 1 - checkeven;
		}

		while (!convert.empty())
		{
			int t = convert.top();
			cout << t;
			convert.pop();
		}
	}
	else cout << 0;
}

int main()
{
	freopen("nradix.inp", "r", stdin);
	freopen("nradix.out", "w", stdout);
	cin >> rq >> inp;
	if (rq[0] == 't') fwconvert();
	else bwconvert();
	return 0;
}