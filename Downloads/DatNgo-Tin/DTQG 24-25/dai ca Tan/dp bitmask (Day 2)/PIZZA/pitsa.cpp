#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define FOR(i, l, r) for (int i = l; i <= r; i++)

struct node
{
    int x, y, s, sum;
};

int k, r, m, n, res;
int shop_conn[105], mask_bit[25], summax;
node a[25], b[105];
vector<int> adj[25];

bool in(int i, int j)
{
    int x = b[i].x - a[j].x;
    int y = b[i].y - a[j].y;
    return (x * x + y * y <= r * r);
}

void dq(int x, int prev_bit, int val)
{
    if (val == summax)
    {
        cout << summax;
        exit(0);
    }
    if (x == k + 1)
    {
        res = max(res, val);
        return;
    }

    for (int i = prev_bit + 1; i <= m; ++i)
        if (!mask_bit[i])
        {
            mask_bit[i] = 1;
            for (int j : adj[i])
                if (!shop_conn[j])
                    val += b[j].s, shop_conn[j] = x;
            dq(x + 1, i, val);
            mask_bit[i] = 0;
            for (int j : adj[i])
                if (shop_conn[j] == x)
                    val -= b[j].s, shop_conn[j] = 0;
        }
}

void not_main()
{
    cin >> k >> r >> m;
    for (int i = 1; i <= m; ++i)
        cin >> a[i].x >> a[i].y;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i].x >> b[i].y >> b[i].s;
        bool fwd = 0;
        for (int j = 1; j <= m; ++j)
            if (in(i, j))
            {
                adj[j].push_back(i);
                a[j].sum += b[i].s;
                fwd = 1;
            }
        if (fwd)
            summax += b[i].s;
    }

    dq(1, 0, 0);
    cout << res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}