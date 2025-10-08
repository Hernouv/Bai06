
#include <bits/stdc++.h>
#define int long long
#define ll long long

const int INF = 1e9 + 7;
const ll oo = 1e18 + 7;
const int nmax = 1000005;
const int MOD = 1e9 + 7;

using namespace std;
int n, m, divcnt[nmax], a[nmax], lv[nmax];
int segTree[nmax * 4];

void update(int id, int l, int r, int u, int v)
{
    if (r < u or u < l)
        return;
    if (l == r)
        segTree[id] = v;
    else
    {
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v);
        update(id * 2 + 1, mid + 1, r, u, v);
        segTree[id] = segTree[id * 2] + segTree[id * 2 + 1];
    }
}

int query(int i, int l, int r, int u, int v)
{
    if (r < u or v < l)
        return 0;
    if (u <= l and r <= v)
        return segTree[i];
    int mid = (l + r) / 2;
    int lmao1 = query(i * 2, l, mid, u, v);
    int lmao2 = query(i * 2 + 1, mid + 1, r, u, v);
    return lmao1 + lmao2;
}

void prep()
{
    for (int i = 1; i <= 1e6; ++i)
    {
        for (int j = i; j <= 1e6; j += i)
        {
            divcnt[j]++;
        }
    }
}

int root[nmax];
int find_root(int x)
{
    if (root[x] == x)
        return x;
    return root[x] = find_root(root[x]);
}

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    prep();
    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        int x = a[i];
        while (x != 1 and x != 2)
        {
            lv[i]++;
            x = divcnt[x];
        }
        update(1, 1, n, i, a[i]);
    }
    root[n + 1] = n + 1;
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int i = find_root(l);
            while (i <= r)
            {
                lv[i]--;
                a[i] = divcnt[a[i]];
                update(1, 1, n, i, a[i]);
                if (lv[i] == 0)
                {
                    root[i] = find_root(i + 1);
                    i = find_root(i);
                }
                else
                    i++;
            }
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
