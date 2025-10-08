#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(__) __.begin(), __.end()

const int nmax = 105;
const int mod = 1e9 + 7;

int n;
string a[nmax];
vector<ll> vals[nmax];
vector<int> dp[nmax];

void add(int &n1, int n2)
{
    n1 += n2;
    if (n1 >= mod)
        n1 -= mod;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        int sz = a[i].size();
        for (int m = 1; m < (1 << sz); ++m)
        {
            ll tmp = 0;
            for (int it = 0; it < sz; ++it)
                if ((m >> it) & 1)
                    tmp = tmp * 10 + (a[i][it] - '0');
            vals[i].push_back(tmp);
        }

        sort(whole(vals[i]));
        vals[i].resize(unique(whole(vals[i])) - vals[i].begin());
        dp[i].resize(vals[i].size() + 5, 0);
    }

    dp[1][0] = 1;
    for (int i = 1; i < n; ++i)
    {
        int sz1 = vals[i].size();
        int sz2 = vals[i + 1].size();

        for (int j = 1; j < sz1; ++j)
            add(dp[i][j], dp[i][j - 1]);

        int it1 = 0, it2 = 0;
        while (it1 < sz1)
        {
            while (it2 < sz2 and vals[i + 1][it2] < vals[i][it1])
                ++it2;
            if (vals[i + 1][it2] >= vals[i][it1])
                add(dp[i + 1][it2], dp[i][it1]);
            ++it1;
        }
    }

    int Sz = vals[n].size();
    for (int i = 1; i < Sz; ++i)
        add(dp[n][i], dp[n][i - 1]);
    int res = 0;
    for (int i = 0; i < Sz; ++i)
        add(res, dp[n][i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}