#include <bits/stdc++.h>
using namespace std;

int seq1[30003], seq2[30003], seq3[30003], seq4[30003];

int main()
{
	int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> seq1[i];
		seq2[i] = seq3[i] = seq4[i] = seq1[i];
	}

	for (int i = 2; i <= n; ++i)
		if (seq1[i] < seq1[i - 1])
		{
			seq1[i] = seq1[i - 1];
			res1++;
		}

	for (int i = 2; i <= n; ++i)
		if (seq3[i] > seq3[i - 1])
		{
			seq3[i] = seq3[i - 1];
			res3++;
		}

	for (int i = n - 1; i >= 1; --i)
		if (seq2[i] < seq2[i + 1])
		{
			seq2[i] = seq2[i + 1];
			res2++;
		}

	for (int i = n - 1; i >= 1; --i)
		if (seq2[i] > seq2[i + 1])
		{
			seq4[i] = seq4[i + 1];
			res4++;
		}

	cout << min(res1, min(res2, min(res3, res4)));
	return 0;
}
//