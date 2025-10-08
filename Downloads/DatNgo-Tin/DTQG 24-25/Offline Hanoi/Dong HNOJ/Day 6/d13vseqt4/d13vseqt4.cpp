#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 2e5 + 10;
const int inf = 2e9;

int n, q;
int mod;
int a[nmax];

struct node
{
    bool allsame;
    int val, lazy;
} st[4 * nmax];

void construct(int id = 1, int l = 1, int r = n)
{
    if (l == r)
    {
        st[id].val = a[l] % mod;
        st[id].allsame = true;
        st[id].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    st[id].lazy = 0;
    if (st[id * 2].allsame and st[id * 2 + 1].allsame and st[id * 2].val == st[id * 2 + 1].val)
    {
        st[id].val = st[id * 2].val;
        st[id].allsame = true;
    }
    else
        st[id].allsame = false;
}

void down(int id, int l, int r)
{
    if (!st[id].lazy)
        return;

    if (l != r)
    {
        if (st[id * 2].allsame)
            st[id * 2].val = (st[id * 2].val + st[id].lazy) % mod;
        else
            st[id * 2].lazy = (st[id * 2].lazy + st[id].lazy) % mod;

        if (st[id * 2 + 1].allsame)
            st[id * 2 + 1].val = (st[id * 2 + 1].val + st[id].lazy) % mod;
        else
            st[id * 2 + 1].lazy = (st[id * 2 + 1].lazy + st[id].lazy) % mod;
    }
    st[id].lazy = 0;
}

void update(int L, int R, int incr, int id = 1, int l = 1, int r = n)
{
    down(id, l, r);

    if (r < L or l > R)
        return;
    if (L <= l and r <= R)
    {
        if (st[id].allsame)
            st[id].val = (st[id].val + incr) % mod;
        st[id].lazy = (st[id].lazy + incr) % mod;
        return;
    }

    int mid = (l + r) / 2;
    update(L, R, incr, id * 2, l, mid);
    update(L, R, incr, id * 2 + 1, mid + 1, r);

    if (st[id * 2].allsame and st[id * 2 + 1].allsame and st[id * 2].val == st[id * 2 + 1].val)
    {
        st[id].allsame = true;
        st[id].val = st[id * 2].val;
    }
    else
        st[id].allsame = false;
}

bool check(int L, int R, int &fval, int id = 1, int l = 1, int r = n)
{
    down(id, l, r);

    if (r < L or l > R)
        return true;

    if (L <= l and r <= R)
    {
        if (st[id].allsame)
        {
            if (fval == -1)
                fval = st[id].val;
            else if (fval != st[id].val)
                return false;
            return true;
        }
        return false;
    }

    int mid = (l + r) / 2;
    bool left_check = check(L, R, fval, id * 2, l, mid);
    if (!left_check)
        return false;

    bool right_check = check(L, R, fval, id * 2 + 1, mid + 1, r);
    return right_check;
}

void not_main()
{
    cin >> n >> mod >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    construct();

    int type, L, R, c;
    for (int i = 1; i <= q; ++i)
    {
        cin >> type >> L >> R;
        if (type == 1)
        {
            cin >> c;
            update(L, R, c);
        }
        else
        {
            int fval = -1;
            bool t = check(L, R, fval);
            if (t)
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
