#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 2e5 + 5;
int p[nmax][70];
int a[nmax];

int n;
ll k;

int binlift(int u)
{
    for (int i = 0; (1LL << i) <= k; ++i)
        if ((k >> i) & 1)
            u = p[u][i];
    return u;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> k;
    k++;
    for (int i = 1, t; i <= n; ++i)
    {
        cin >> p[i][0];
    }
    for (int j = 1; j <= 64; ++j)
        for (int i = 1; i <= n; ++i)
            p[i][j] = p[p[i][j - 1]][j - 1];
    // for (int i = 1; i <= n; ++i)
    //     a[binlift(i)] = i;
    for (int i = 1; i <= n; ++i)
        cout << binlift(i) << ' ';
}