#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define ii pair<int, int>
#define F first
#define S second
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

const int N = 1e6 + 7;

int n, m;
ii a[N];
int root[N], sz[N];

bool check(ii &x, ii &y)
{
    if (abs(x.F - y.F) == 1 and abs(x.S - y.S) == 1)
        return true;
    return (abs(x.F - y.F) + abs(x.S - y.S) == 1);
}

int find(int u)
{
    return root[u] ? root[u] = find(root[u]) : u;
}

bool join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        root[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

void not_main()
{
    cin >> n >> m;
    For(i, 1, m) cin >> a[i].F >> a[i].S, sz[i] = 1;
    For(i, 1, m)
    {
        For(j, 1, m)
        {
            if (check(a[i], a[j]))
                join(i, j);
        }
    }
    bool ok = 1;
    For(i, 1, m)
    {
        For(j, 1, m)
        {
            if (find(i) == find(j))
            {
                if (a[i].F == 1 and a[j].F == n)
                    ok = 0;
                if (a[i].S == 1 and a[j].S == n)
                    ok = 0;
                if (a[i].F == 1 and a[j].S == 1)
                    ok = 0;
                if (a[i].F == n and a[j].S == n)
                    ok = 0;
            }
        }
    }

    cout << (ok ? "YES" : "NO");
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}