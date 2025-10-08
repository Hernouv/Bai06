#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ms(v, val) memset(v, val, sizeof(v))
#define all(v) v.begin(), v.end()
#define ii pair<int, int>
// #define int long long
#define TAsk "lmeo"
#define endl "\n"

using namespace std;

void init()
{
    if (fopen(TAsk ".inp", "r"))
    {
        freopen(TAsk ".inp", "r", stdin);
        freopen(TAsk ".out", "w", stdout);
    }
}

const int NMAX = 500005;
int n, a[NMAX], par[NMAX];

int find(int x)
{
    if (par[x] != x)
        par[x] = find(par[x]);
    return par[x];
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        par[x] = y;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int bit = 30; bit >= 0; --bit)
    {
        for (int i = 1; i <= n; ++i)
        {
            par[i] = i;
        }

        int lmeo = 0;
        int prev_i = -1;

        for (int i = 1; i <= n; ++i)
        {
            if (!(a[i] & (1 << bit)))
            {
                int can = min(i + a[i], n);
                if (i > lmeo)
                {
                    lmeo = can;
                    prev_i = i;
                }
                else
                {
                    join(prev_i, i);
                    lmeo = max(lmeo, can);
                }
                prev_i = i;
            }
        }
        if (!(a[1] & (1 << bit)) && !(a[n] & (1 << bit)) && find(1) == find(n))
        {
        }
        else
            ans |= (1 << bit);
    }
    cout << ans;
    return 0;
}