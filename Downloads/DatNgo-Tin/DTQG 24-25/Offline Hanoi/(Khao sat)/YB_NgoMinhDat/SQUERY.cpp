#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

const int nmax = 2e5 + 10;

int n, q;
int a[nmax];
int exist[nmax];
int accum[nmax];
int query[nmax];
vector<int> pos;

void not_main()
{
    cin >> n >> q;
    int maxn = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] <= n)
        {
            maxn = max(maxn, a[i]);
            exist[a[i]] = 1;
            if (a[i] == 0)
                pos.push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
        accum[i] = accum[i - 1] + exist[i];

    for (int i = 1; i <= q; ++i)
        cin >> query[i];

    for (int i = 1; i <= q; ++i)
    {
        if (query[i] > n)
        {
            cout << -1 << '\n';
            continue;
        }
        if (accum[query[i]] != query[i])
        {
            cout << -1 << '\n';
            continue;
        }

        int res1 = 0x3f, res2 = 0x3f;
        for (int p : pos)
        {
            if (p >= query[i])
            {
                set<int> ele;
                for (int tmp = p; tmp >= 1; --tmp)
                {
                    if (a[tmp] <= query[i])
                        ele.insert(a[tmp]);
                    if ((int)ele.size() == query[i])
                    {
                        res1 = p - tmp + 1;
                        break;
                    }
                }
            }
            if (n - p >= query[i])
            {
                set<int> ele;
                for (int tmp = p; tmp <= n; ++tmp)
                {
                    if (a[tmp] <= query[i])
                        ele.insert(a[tmp]);
                    if ((int)ele.size() == query[i])
                    {
                        res2 = tmp - p + 1;
                        break;
                    }
                }
            }
        }
        res1 = min(res1, res2);
        if (res1 > n)
            cout << -1 << '\n';
        else
            cout << res1 << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SQUERY.INP", "r"))
    {
        freopen("SQUERY.INP", "r", stdin);
        freopen("SQUERY.OUT", "w", stdout);
    }
    not_main();
    return 0;
}