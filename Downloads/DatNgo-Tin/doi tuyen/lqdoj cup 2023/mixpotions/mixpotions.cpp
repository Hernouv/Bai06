#include <bits/stdc++.h>
using namespace std;

int n, c, k;
long long id[1000010];
long long sub1_bit[1000010];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("mixpotions.inp", "r", stdin);
    freopen("mixpotions.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> id[i];
    int it = 1, mix_sz = n * (n - 1) / 2;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            sub1_bit[it++] = id[i] xor id[j];
    sort(sub1_bit + 1, sub1_bit + mix_sz + 1);
    cout << sub1_bit[k];
    return 0;
}