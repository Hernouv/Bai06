#include <bits/stdc++.h>
using namespace std;

vector<int> beauty3;

bool erastosthenes[5105];

void sieve()
{
	erastosthenes[0] = erastosthenes[1] = false;
	for (int i = 2; i * i <= 5104; ++i)
	{
		if (erastosthenes[i])
			for (int j = i * i; j <= 5104; j += i)
				erastosthenes[j] = false;
	}
}

int cube(int inp)
{
	return inp * inp * inp;
}

void b3list()
{
	for (int a = 0; a <= 9; ++a)
		for (int b = 0; b <= 9; ++b)
			for (int c = 0; c <= 9; ++c)
				for (int d = 0; d <= 9; ++d)
					for (int e = 0; e <= 9; ++e)
						for (int f = 0; f <= 9; ++f)
							for (int g = 0; g <= 9; ++g)
							{
								int temp = cube(a) + cube(b) + cube(c) + cube(d) + cube(e) + cube(f) + cube(g);
								if (erastosthenes[temp])
									beauty3.push_back(a * 1000000 + b * 100000 + c * 10000 + d * 1000 + e * 100 + f * 10 + g);
							}
	sort(beauty3.begin(), beauty3.end());
}

int main()
{
	freopen("beauty3.inp", "r", stdin);
	freopen("beauty3.out", "w", stdout);
	memset(erastosthenes, true, sizeof(erastosthenes));
	sieve();
	b3list();

	int rqcount;
	cin >> rqcount;
	for (int i = 1; i <= rqcount; ++i)
	{
		int t;
		cin >> t;
		cout << beauty3[t - 1] << endl;
	}
	return 0;
}