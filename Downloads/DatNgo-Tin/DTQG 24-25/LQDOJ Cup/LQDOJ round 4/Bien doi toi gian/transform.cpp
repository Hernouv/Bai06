#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int nmax = 2e5 + 10;
const int outbound = 1e9 + 10;

int a[nmax];
int n, q;

struct query
{
    bool type;
    int a, b;
} qry[nmax];

int minR[nmax], maxL[nmax];
void s2_proc()
{
    minR[n] = n;
    for (int i = n - 1; i >= 1; --i)
    {
        if (a[i] == a[i + 1])
            minR[i] = minR[i + 1];
        else
            minR[i] = i;
    }

    maxL[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == a[i - 1])
            maxL[i] = maxL[i - 1];
        else
            maxL[i] = i;
    }

    for (int i = 1; i <= q; ++i)
    {
        int t1 = minR[qry[i].a];
        int t2 = maxL[qry[i].b];
        if (t1 <= t2)
            cout << t2 - t1 + 1 << ' ' << 1 << '\n';
        else
            cout << 1 << ' ' << t1 - t2 + 1 << '\n';
    }
}

ii spT_min[20][nmax], spT_max[20][nmax];
void construct_spT()
{
    for (int i = 1; i <= n; ++i)
    {
        spT_min[0][i] = {i, a[i]};
        spT_max[0][i] = {i, a[i]};
    }

    for (int j = 1; j <= __lg(n); ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            if (spT_min[j - 1][i].se < spT_min[j - 1][i + (1 << (j - 1))].se)
                spT_min[j][i] = spT_min[j - 1][i];
            else
                spT_min[j][i] = spT_min[j - 1][i + (1 << (j - 1))];

            if (spT_max[j - 1][i].se > spT_max[j - 1][i + (1 << (j - 1))].se)
                spT_max[j][i] = spT_max[j - 1][i];
            else
                spT_max[j][i] = spT_max[j - 1][i + (1 << (j - 1))];
        }
    }
}
int find_min(int l, int r)
{
    int len = __lg(r - l + 1);
    ii t1 = spT_min[len][l];
    ii t2 = spT_min[len][r - (1 << len) + 1];
    if (t1.se < t2.se)
        return t1.fi;
    else
        return t2.fi;
}
int find_max(int l, int r)
{
    int len = __lg(r - l + 1);
    ii t1 = spT_max[len][l];
    ii t2 = spT_max[len][r - (1 << len) + 1];
    if (t1.se > t2.se)
        return t1.fi;
    else
        return t2.fi;
}

void s3_proc()
{
    construct_spT();
    for (int i = 1; i <= q; ++i)
    {
        int t1 = find_min(qry[i].a, qry[i].b);
        int t2 = find_max(qry[i].a, qry[i].b);
        cout << abs(t1 - t2 + 1) << ' ' << 1 << '\n';
    }
}

struct custom
{
    int max, min;
    custom()
    {
        max = -outbound;
        min = outbound;
    }
} ST[(int)1e6];

void construct(int id, int l, int r)
{
    if (l == r)
    {
        ST[id].max = a[l];
        ST[id].min = a[l];
        return;
    }
    int mid = (l + r) / 2;
    construct(id * 2, l, mid);
    construct(id * 2 + 1, mid + 1, r);
    ST[id].max = max(ST[id * 2].max, ST[id * 2 + 1].max);
    ST[id].min = min(ST[id * 2].min, ST[id * 2 + 1].min);
}

custom get(int id, int l, int r, int u, int v)
{
    if (r < u or l > v)
        return ST[0];
    if (u <= l and r <= v)
        return ST[id];
    int mid = (l + r) / 2;
    custom t1 = get(id * 2, l, mid, u, v);
    custom t2 = get(id * 2 + 1, mid + 1, r, u, v);
    custom t3;
    t3.max = max(t1.max, t2.max);
    t3.min = min(t1.min, t2.min);
    return t3;
}

void update(int id, int l, int r, int vt, int val)
{
    if (vt < l or vt > r)
        return;
    if (l == r)
    {
        ST[id].max = val;
        ST[id].min = val;
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, vt, val);
    update(id * 2 + 1, mid + 1, r, vt, val);
    ST[id].max = max(ST[2 * id].max, ST[2 * id + 1].max);
    ST[id].min = min(ST[2 * id].min, ST[2 * id + 1].min);
}

void s1_proc()
{
    construct(1, 1, n);
    for (int i = 1; i <= q; ++i)
    {
        if (!qry[i].type)
            update(1, 1, n, qry[i].a, qry[i].b);
        else
        {
            int cnt = 0;
            custom tmp = get(1, 1, n, qry[i].a, qry[i].b);
            int rmax = tmp.max, rmin = tmp.min;
            int pos_max = 0, pos_min = 0;
            int dist = qry[i].b - qry[i].a + 1;
            for (int j = qry[i].a; j <= qry[i].b; ++j)
            {
                if (a[j] == rmax)
                    pos_max = j;
                if (a[j] == rmin)
                    pos_min = j;
                if (pos_max != 0 and pos_min != 0)
                    dist = min(dist, abs(pos_max - pos_min) + 1);
            }
            for (int j = qry[i].a; j <= qry[i].b; ++j)
            {
                if (j + dist - 1 > qry[i].b)
                    break;
                tmp = get(1, 1, n, j, j + dist - 1);
                if (tmp.max == rmax and tmp.min == rmin)
                    cnt++;
            }
            cout << dist << ' ' << cnt << '\n';
        }
    }
}

vector<int> to_sub3;
void not_main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int qt, qa, qb;
    for (int i = 1; i <= q; ++i)
    {
        cin >> qt >> qa >> qb;
        if (qt == 1)
            qry[i] = {false, qa, qb};
        else
            qry[i] = {true, qa, qb};
    }

    bool to_sub2 = true;
    for (int i = 1; i <= n; ++i)
        if (a[i] - a[i - 1] < 0)
        {
            to_sub2 = false;
            break;
        }
    if (to_sub2)
    {
        s2_proc();
        return;
    }

    for (int i = 1; i <= n; ++i)
        to_sub3.push_back(a[i]);
    sort(whole(to_sub3));
    to_sub3.resize(unique(whole(to_sub3)) - to_sub3.begin());
    if (to_sub3.size() == n)
    {
        s3_proc();
        return;
    }

    s1_proc();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("transform.inp", "r"))
    {
        freopen("transform.inp", "r", stdin);
        freopen("transform.out", "w", stdout);
    }
    not_main();
    return 0;
}