#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e5 + 10;
const ll mod = 1e9 + 7;

int n, q;
string chips;

ii segTree[4 * nmax];
void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        if (chips[l] == 'A')
            segTree[id] = {1, 0};
        else
            segTree[id] = {0, 1};
        return;
    }

    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    segTree[id].fi = segTree[id * 2].fi + segTree[id * 2 + 1].fi;
    segTree[id].se = segTree[id * 2].se + segTree[id * 2 + 1].se;
}

pair<bool, bool> lazy[4 * nmax];
void lazyupd(int id, int l, int r)
{
    if (!lazy[id].fi and !lazy[id].se)
        return;

    if (lazy[id].fi)
    {
        segTree[id].fi = r - l + 1;
        segTree[id].se = 0;
    }
    else
    {
        segTree[id].fi = 0;
        segTree[id].se = r - l + 1;
    }

    if (l != r)
    {
        int mid = (l + r) / 2;
        if (lazy[id].fi)
        {
            lazy[id * 2].fi = mid - l + 1;
            lazy[id * 2].se = 0;
            lazy[id * 2 + 1].fi = r - mid;
            lazy[id * 2 + 1].se = 0;
        }
        else
        {
            lazy[id * 2].fi = 0;
            lazy[id * 2].se = mid - l + 1;
            lazy[id * 2 + 1].fi = 0;
            lazy[id * 2 + 1].se = r - mid;
        }
    }
    lazy[id] = {0, 0};
}

void update(int L, int R, char ctype, int id = 1, int l = 1, int r = n)
{
    lazyupd(id, l, r);
    if (r < L or l > R)
        return;
    if (L <= l and r <= R)
    {
        if (ctype == 'A')
        {
            lazy[id].fi = 1;
            lazy[id].se = 0;
            lazyupd(id, l, r);
        }
        else
        {
            lazy[id].fi = 0;
            lazy[id].se = 1;
            lazyupd(id, l, r);
        }
        return;
    }

    int mid = (l + r) / 2;
    update(L, R, ctype, id * 2, l, mid);
    update(L, R, ctype, id * 2 + 1, mid + 1, r);
    segTree[id].fi = segTree[id * 2].fi + segTree[id * 2 + 1].fi;
    segTree[id].se = segTree[id * 2].se + segTree[id * 2 + 1].se;
}

ii getval(int L, int R, int id = 1, int l = 1, int r = n)
{
    lazyupd(id, l, r);
    if (r < L or l > R)
        return {0, 0};
    if (L <= l and r <= R)
        return segTree[id];

    int mid = (l + r) / 2;
    ii t1 = getval(L, R, id * 2, l, mid);
    ii t2 = getval(L, R, id * 2 + 1, mid + 1, r);
    return {t1.fi + t2.fi, t1.se + t2.se};
}

struct mt
{
    ll ar[2][2] = {{1, 1}, {1, 1}};
    void iniA()
    {
        // ar[0][1] = 1;
        ar[0][0] = 1;
        ar[0][1] = 1;
        ar[1][0] = -1;
        ar[1][1] = 1;
    }
    void iniB()
    {
        ar[0][0] = 1;
        ar[0][1] = -1;
        ar[1][0] = 1;
        ar[1][1] = 1;
    }
};

mt mtmul(mt a, mt b)
{
    mt ret;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
        {
            ll tmp = 0;
            for (int k = 0; k < 2; ++k)
                tmp = (tmp + 1LL * a.ar[i][k] * b.ar[k][j] + 1LL * mod * mod) % mod;
            ret.ar[i][j] = tmp;
        }
    return ret;
}

mt pwrmod(mt base, mt p, int expo)
{
    while (expo)
    {
        if (expo % 2)
            base = mtmul(base, p);
        p = mtmul(p, p);
        expo /= 2;
    }
    return base;
}

void not_main()
{
    cin >> n >> q;
    cin >> chips;
    chips = ' ' + chips;
    construct();

    int type, L, R, x, y;
    char chiptype;
    for (int i = 1; i <= q; ++i)
    {
        cin >> type >> L >> R;
        if (type == 1)
        {
            cin >> chiptype;
            update(L, R, chiptype);
        }
        else
        {
            cin >> x >> y;
            ii coef = getval(L, R);
            mt base;
            base.ar[0][0] = x;
            base.ar[0][1] = y;
            mt pwr;
            pwr.iniA();
            base = pwrmod(base, pwr, coef.fi);
            pwr.iniB();
            base = pwrmod(base, pwr, coef.se);
            cout << base.ar[0][0] << ' ' << base.ar[0][1] << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}