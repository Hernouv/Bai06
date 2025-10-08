#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef long long ll;

const int mmax = 32, nmax = 12;
const ll outbound = 1e16;

int m, n;
ll price[mmax];
bool fav_food[nmax][nmax];
int pow3[nmax];
ll dp[mmax][60000], res = outbound;

void add_data(string s, int id)
{
    s += ' ';
    int tnum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != ' ')
        {
            tnum *= 10;
            tnum += (s[i] - '0');
        }
        else
        {
            fav_food[id][tnum] = true;
            tnum = 0;
        }
    }
}

void not_main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cin >> price[i];
    string tmp;
    for (int i = 0; i <= n; ++i)
    {
        getline(cin, tmp);
        add_data(tmp, i);
    }

    pow3[0] = 1;
    for (int i = 1; i <= 10; ++i)
        pow3[i] = pow3[i - 1] * 3;

    for (int i = 0; i <= m; ++i)
        for (int msk = 1; msk < pow3[n]; ++msk)
            dp[i][msk] = outbound;

    for (int i = 0; i < m; ++i)
    {
        for (int msk = 0; msk < pow3[n] - 1; ++msk)
        {
            if (dp[i][msk] == outbound)
                continue;

            dp[i + 1][msk] = dp[i][msk];
            bool fwd = true;
            for (int it = 1; it <= n; ++it)
                if (fav_food[it][i + 1] and (msk / pow3[it - 1]) % 3 == 2)
                {
                    fwd = false;
                    break;
                }

            if (fwd)
            {
                int new_msk = msk;
                for (int it = 1; it <= n; ++it)
                    if (fav_food[it][i + 1])
                        new_msk += pow3[it - 1];

                minimize(dp[i + 1][new_msk], dp[i][msk] + price[i + 1]);
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        minimize(res, dp[i][pow3[n] - 1]);
    cout << (res == outbound ? -1 : res);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}