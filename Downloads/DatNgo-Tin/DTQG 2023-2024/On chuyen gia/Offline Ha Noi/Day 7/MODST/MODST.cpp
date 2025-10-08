#pragma GCC optimize("Ofast,02,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define iii pair<int, ii>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;

int n, mn = INT_MAX;
vector<int> a;
vector<iii> e;
int root[N], sz[N], tag[N];

int find(int u)
{
    return root[u] ? root[u] = find(root[u]) : u;
}

bool join(int a, int b)
{
    ++a, ++b;
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
    cin >> n;
    a.resize(n);
    for (int &x : a)
        cin >> x;
    for (int &x : a)
        minimize(mn, x);
    uni(a);
    n = a.size();
    For(i, 0, n)
    {
        tag[i] = -1;
        sz[i] = 1;
    }

    for (int i = 0; i < n; ++i)
    {
        tag[i] = i;
        int v = i;
        for (int x = a[i]; x <= a[n - 1]; x += a[i])
        {
            v = lower_bound(a.begin() + v + 1, a.end(), x) - a.begin();
            if (v >= n)
                break;
            if (tag[v] != i)
            {
                tag[v] = i;
                int t = a[v] % a[i];
                if (t > mn)
                    continue;
                if (t == 0)
                    join(i, v);
                else
                    e.pb({t, {i, v}});
                if (a[v + 1] > a[i] + x)
                {
                    int y = (a[v + 1] - x) / a[i] - 1;
                    x += y * a[i];
                }
            }
        }
    }

    int ans = 0;
    sort(all(e));
    for (iii i : e)
    {
        if (join(i.S.F, i.S.S))
        {
            ans += i.F;
            if (sz[find(i.S.F + 1)] == n)
                break;
        }
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}