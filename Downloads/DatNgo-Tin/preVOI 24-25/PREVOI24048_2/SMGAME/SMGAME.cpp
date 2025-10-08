#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(__) __.begin(), __.end()
#define loop(__, l, r) for (int __ = l; __ <= r; ++__)

const int nmax = 1e5 + 5;

int n;
int a[nmax], a2[nmax], b[nmax];
vector<ii> poslist;
int ans = 0;

void add_op(int &num1, int num2)
{
    num1 += num2;
    if (num1 > n)
        num1 -= n;
}

void minus_op(int &num1, int num2)
{
    num1 -= num2;
    if (num1 < 1)
        num1 += n;
}

void procL(int val, int pos)
{
    minus_op(pos, 1);
    while (a[pos] < val)
    {
        if (b[pos] == val)
        {
            a[pos] = val;
            minus_op(pos, 1);
            ++ans;
        }
        else
            return;
    }
}

void procR(int val, int pos)
{
    add_op(pos, 1);
    while (a[pos] < val)
    {
        if (b[pos] == val)
        {
            a[pos] = val;
            add_op(pos, 1);
            ++ans;
        }
        else
            return;
    }
}

void not_main()
{
    cin >> n;
    loop(i, 1, n)
    {
        cin >> a[i];
        a2[i] = a[i];
    }
    loop(i, 1, n)
    {
        cin >> b[i];
    }
    loop(i, 1, n)
    {
        if (a[i] > b[i])
        {
            cout << -1;
            return;
        }
    }
    poslist.resize(n);
    loop(i, 1, n)
    {
        poslist[i - 1] = {a[i], i};
    }
    sort(whole(poslist), [](ii &x, ii &y)
         { return (x.fi > y.fi); });

    loop(i, 0, n - 1)
    {
        if (a2[poslist[i].se] == b[poslist[i].se])
        {
            procR(poslist[i].fi, poslist[i].se);
            procL(poslist[i].fi, poslist[i].se);
        }
    }

    loop(i, 1, n)
    {
        if (a[i] != b[i])
        {
            cout << -1;
            return;
        }
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SMGAME.INP", "r"))
    {
        freopen("SMGAME.INP", "r", stdin);
        freopen("SMGAME.OUT", "w", stdout);
    }
    not_main();
    return 0;
}