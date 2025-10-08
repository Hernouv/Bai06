#include <bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef pair<int, int> pii;

const int nmax = 1 << 20;

int n, q;

vector<pii> T[nmax];
int a[nmax];
int ls[nmax], rs[nmax];
int Left[nmax];
int Right[nmax];
int ans[nmax];

void update(int x, int l, int r, int L, int v)
{
    if (L > r or L < l)
        return;
    T[x].push_back({rs[v], v});
    int mid = (l + r) / 2;
    if (l == r)
        return;
    update(x * 2, l, mid, L, v);
    update(x * 2 + 1, mid + 1, r, L, v);
}

void query_update(int x, int l, int r, int L, int R, int p1, int p2)
{
    if (L > r or R < l)
        return;
    if (l >= L and r <= R)
    {
        T[x].push_back({p1, -1});
        T[x].push_back({p2, -2});
        return;
    }
    int mid = (l + r) / 2;
    query_update(x * 2, l, mid, L, R, p1, p2);
    query_update(x * 2 + 1, mid + 1, r, L, R, p1, p2);
}

void solve(int x, int l, int r)
{
    sort(T[x].begin(), T[x].end());
    int cnt = 0;
    for (auto v : T[x])
    {
        if (v.second == -1)
            ++cnt;
        else if (v.second == -2)
            --cnt;
        else
            ans[v.second] += cnt;
    }
    if (l == r)
        return;
    int mid = (l + r) / 2;
    solve(x * 2, l, mid);
    solve(x * 2 + 1, mid + 1, r);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < q; ++i)
    {
        cin >> ls[i] >> rs[i];
        --ls[i];
        --rs[i];
        update(1, 0, n - 1, ls[i], i);
    }

    map<int, int> M;
    for (int i = 0; i < n; ++i)
    {
        int pos = -1;
        if (M.count(a[i]))
            pos = M[a[i]];
        Left[i] = pos;
        M[a[i]] = i;
    }

    M.clear();
    for (int i = n - 1; i >= 0; --i)
    {
        int pos = n;
        if (M.count(a[i]))
            pos = M[a[i]];
        Right[i] = pos;
        M[a[i]] = i;
    }

    Right[n] = n;

    for (int i = 0; i < n; ++i)
    {
        int rpos = Right[i];
        if (rpos == n)
            continue;
        query_update(1, 0, n - 1, Left[i] + 1, i, rpos, Right[rpos]);
    }

    solve(1, 0, n - 1);
    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    return 0;
}
