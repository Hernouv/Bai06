#include <bits/stdc++.h>
using namespace std;

const int nmax = 3e5 + 10;

int n, m;
int lose_to[nmax], r_closest[nmax];
int out_cnt;

int get_r_closest(int v)
{
    if (r_closest[v] == v)
        return v;
    else
        return r_closest[v] = get_r_closest(r_closest[v]);
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n + 2; ++i)
        r_closest[i] = i;

    int l, r, x;
    for (int i = 1; i <= m; ++i)
    {
        cin >> l >> r >> x;
        int it = get_r_closest(l);
        while (it <= r)
        {
            if (it == x)
                ++it;
            else
            {
                lose_to[it] = x;
                ++out_cnt;
                r_closest[it] = it + 1;
            }
            it = get_r_closest(it);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << lose_to[i] << ' ';
}

int32_t main()
{
    if (fopen("knight.inp", "r"))
    {
        freopen("knight.inp", "r", stdin);
        freopen("knight.out", "w", stdout);
    }
    not_main();
    return 0;
}