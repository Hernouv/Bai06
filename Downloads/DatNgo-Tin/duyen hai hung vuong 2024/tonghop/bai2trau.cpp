#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int k, res = 0;
string paren;

void not_main()
{
    cin >> k;
    cin >> paren;
    int l = paren.size();
    int conv[l];
    for (int i = 0; i < l; ++i)
    {
        if (paren[i] == '(')
            conv[i] = 1;
        else
            conv[i] = -1;
    }

    for (int i = 0; i < (1 << l); ++i)
    {
        int t = __builtin_popcount(i);
        if (l - t < 2 * k)
            continue;

        int check = 0;
        for (int it = 0; it < l; ++it)
        {
            if (!((i >> it) & 1))
                check += conv[it];
            if (check < 0)
            {
                break;
                continue;
            }
        }
        if (check)
            continue;

        int t1 = 0, t2 = 0, t3 = 0;
        for (int it = 0; it < l; ++it)
            if (!((i >> it) & 1))
            {
                if (conv[it] == 1)
                {
                    t1 = max(t1, t3);
                    t3 = 0;
                    ++t2;
                }
                else if (conv[it] == -1)
                {
                    ++t3;
                    --t2;
                }
            }
        t1 = max(t1, t3);

        if (t1 == k)
            ++res;
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BRACKET.INP", "r"))
    {
        freopen("BRACKET.INP", "r", stdin);
        freopen("BRACKET.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
