#include <bits/stdc++.h>
using namespace std;

vector<int> digit, odd, scan, d2, d3, d4, d5, d6, d7;
vector<int>::iterator iter;
int testres;
bool checked[10000000];
bool eratosthenes[10000000];

void sieve()
{
	eratosthenes[0] = eratosthenes[1] = true;
	for (int i = 4; i < 10000000; i += 2)
		eratosthenes[i] = true;

	for (int i = 3; i < 3163; i += 2)
		if (!eratosthenes[i])
			for (int j = i * i; j < 10000000; j += i)
				eratosthenes[j] = true;
}

void process()
{
	testres = 0;
	for (auto i : digit)
		if (!eratosthenes[i] and !checked[i]) scan.push_back(i), testres++, checked[i] = true;

	/////////////////////////////////////////
	
	for (auto i1 : odd)
	{
		d2 = digit;
		iter = find(d2.begin(), d2.end(), i1);
		d2.erase(iter, iter + 1);
		if (d2.size() > 0)
		{
			for (auto i2 : d2)
			{
				int t = i2 * 10 + i1;
				if (!eratosthenes[t] and !checked[t]) scan.push_back(t), testres++, checked[t] = true;
				d3 = d2;
				iter = find(d3.begin(), d3.end(), i2);
				d3.erase(iter, iter + 1);
				if (d3.size() > 0)
				{
					for (auto i3 : d3)
					{
						int t1 = i3 * 100 + t;
						if (!eratosthenes[t1] and !checked[t1]) scan.push_back(t1), testres++, checked[t1] = true;
						d4 = d3;
						iter = find(d4.begin(), d4.end(), i3);
						d4.erase(iter, iter + 1);
						if (d4.size() > 0)
						{
							for (auto i4 : d4)
							{
								int t2 = i4 * 1000 + t1;
								if (!eratosthenes[t2] and !checked[t2]) scan.push_back(t2), testres++, checked[t2] = true;
								d5 = d4;
								iter = find(d5.begin(), d5.end(), i4);
								d5.erase(iter, iter + 1);
								if (d5.size() > 0)
								{
									for (auto i5 : d5)
									{
										int t3 = i5 * 10000 + t2;
										if (!eratosthenes[t3] and !checked[t3]) scan.push_back(t3), testres++, checked[t3] = true;
										d6 = d5;
										iter = find(d6.begin(), d6.end(), i5);
										d6.erase(iter, iter + 1);
										if (d6.size() > 0)
										{
											for (auto i6 : d6)
											{
												int t4 = i6 * 100000 + t3;
												if (!eratosthenes[t4] and !checked[t4]) scan.push_back(t4), testres++, checked[t4] = true;
												d7 = d6;
												iter = find(d7.begin(), d7.end(), i6);
												d7.erase(iter, iter + 1);
												if (d7.size() > 0)
												{
													for (auto i7 : d7)
													{
														int t5 = i7 * 1000000 + t4;
														if (!eratosthenes[t5] and !checked[t5]) scan.push_back(t5), testres++, checked[t5] = true;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	d2.clear();
	d3.clear();
	d4.clear();
	d5.clear();
	d6.clear();
	d7.clear();
	for (auto x : scan)
		checked[x] = false;
	scan.clear();
}

int main()
{
	freopen("gnumber.inp", "r", stdin);
	freopen("gnumber.out", "w", stdout);
	sieve();
	int testcnt;
	cin >> testcnt;
	for (int i = 0; i < testcnt; ++i)
	{
		string inp;
		cin >> inp;
		digit.clear();
		odd.clear();
		bool that_one_special_case = false;
		for (int j = 0, sz = inp.size(); j < sz; ++j)
		{
			int t = inp[j] - '0';
			if (t == 2) that_one_special_case = true;
			digit.push_back(t);
			if (t & 1) odd.push_back(t);
		}
		if (odd.size() == 0)
		{
			if (that_one_special_case) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else
		{
			process();
			cout << testres << endl;
		}
	}
	return 0;
}