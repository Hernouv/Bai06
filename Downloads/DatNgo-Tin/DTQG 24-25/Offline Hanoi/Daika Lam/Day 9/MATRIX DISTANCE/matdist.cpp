#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(_name) _name.begin(), _name.end()

const int nmax = 1e3 + 5;
int n, m;
ll res = 0;

struct node
{
    int x, y, val;
    bool operator<(node const &other) const
    {
        if (val == other.val)
        {
            if (x == other.x)
                return (y < other.y);
            return (x < other.x);
        }
        return (val < other.val);
    }
} a[nmax * nmax];

vector<int> posx[nmax * nmax], posy[nmax * nmax];

int ID(int a, int b)
{
    return (a - 1) * n + b;
}

void not_main()
{
    cin >> n >> m;
    int id = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[id].val;
            a[id].x = i;
            a[id].y = j;
            id++;
        }
    }
    id--;

    sort(a + 1, a + id + 1);
    int idval = 0, curval = 0;
    for (int i = 1; i <= id; ++i)
    {
        if (a[i].val > curval)
        {
            ++idval;
            curval = a[i].val;
        }
        posx[idval].emplace_back(a[i].x);
        posy[idval].emplace_back(a[i].y);
    }
    for (int i = 1; i <= idval; ++i)
        sort(whole(posy[i]));

    for (int i = 1; i <= idval; ++i)
    {
        int sz = posx[i].size();

        ll tvx = 0;
        for (int it = 1; it < sz; ++it)
            tvx += posx[i][it] - posx[i][0];

        int tsz = sz - 1;
        for (int it = 0; it < sz; ++it)
        {
            res += tvx;
            tvx -= 1LL * tsz * (posx[i][it + 1] - posx[i][it]);
            if (!tvx)
                break;
            tsz--;
        }

        ll tvy = 0;
        for (int it = 1; it < sz; ++it)
            tvy += posy[i][it] - posy[i][0];
        tsz = sz - 1;
        for (int it = 0; it < sz; ++it)
        {
            res += tvy;
            tvy -= 1LL * tsz * (posy[i][it + 1] - posy[i][it]);
            if (!tvy)
                break;
            tsz--;
        }
    }
    cout << res * 2;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}