#include <bits/stdc++.h>
using namespace std;

bool eratosthenes[24];
vector<int> primemulti, primelist;

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = 0;
	for (int i = 2; i < 5; ++i)
		if (eratosthenes[i])
			for (int j = i * i; j < 24; j += i)
				eratosthenes[j] = false;

	primemulti.push_back(1);
	char temp = '0';
	for (int i = 2; i < 24; ++i)
		if (eratosthenes[i])
		{
			primelist.push_back(i);
			primemulti.push_back(primemulti[temp - '0'] * i);
			temp++;
		}
	primemulti[0] = 0;
}

void display(int inp)
{
	for (int i = 0; i < inp - 1; ++i)
		cout << primelist[i] << '*';
	cout << primelist[inp - 1];
}


int main()
{
	freopen("bprime.inp", "r", stdin);
	freopen("bprime.out", "w", stdout);
	memset(eratosthenes, true, sizeof(eratosthenes));
	sieve();
	int a;
	while (cin >> a)
	{
		if (!a) return 0;
		int x = a;
		int iter = 0;
		while (primemulti[iter] <= a)
		{
			iter++;
			if (iter == 10) break;
		}
		iter--;

		stack<pair<int, int>> res;
		for (int i = iter; i > 0; --i)
			if (a >= primemulti[i])
			{
				res.emplace(a / primemulti[i], i);
				a %= primemulti[i];
			}

		cout << x << " = ";
		if (a)
		{
			cout << a;
			if (a != x) cout << " + ";
		}
		while (!res.empty())
		{
			int t1 = res.top().first, t2 = res.top().second;
			cout << t1 << '*', display(t2);
			res.pop();
			if (!res.empty()) cout << " + ";
		}
		cout << endl;
	}
}