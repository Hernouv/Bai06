#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n;
int res;

struct custom
{
    int x;
    int y1, y2;
    int type;
};
vector<custom> line;

bool cmp(custom a, custom b)
{
    return (a.x < b.x or (a.x == b.x and a.type < b.type));
}

int fenwickTree[nmax];

void update(int pos, int val)
{
    while (pos < n)
    {
        fenwickTree[pos] += val;
        pos += (pos & -pos);
    }
}

int getVal(int pos)
{
    int ret = 0;
    while (pos > 0)
    {
        ret += fenwickTree[pos];
        pos -= (pos & -pos);
    }
    return ret;
}

void not_main()
{
    cin >> n;
    int xa, ya, xb, yb;
    for (int i = 1; i <= n; ++i)
    {
        cin >> xa >> ya >> xb >> yb;
        if (xa > xb)
            swap(xa, xb);
        if (ya > yb)
            swap(ya, yb);
        if (xa == xb)
            line.push_back({xa, ya, yb, 1});
        else
        {
            line.push_back({xa, ya, yb, 0});
            line.push_back({xb, ya, yb, 2});
        }
    }
    sort(line.begin(), line.end(), cmp);

    for (custom it : line)
    {
        if (it.type == 0)
            update(it.y1, 1);
        else if (it.type == 1)
            res += getVal(it.y2) - getVal(it.y1 - 1);
        else if (it.type == 2)
            update(it.y1, -1);
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}