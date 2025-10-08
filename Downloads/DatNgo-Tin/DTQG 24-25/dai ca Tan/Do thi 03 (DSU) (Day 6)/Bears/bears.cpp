#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 5;
pair<int, int> p[nmax];
int root[nmax], sz[nmax], ans[nmax];
bool mark[nmax];

int find(int v)
{
    return (root[v] == v ? v : root[v] = find(root[v]));
}

void dsu(int u, int v)
{
    u = find(u);
    v = find(v);
    root[u] = v;
    sz[v] += sz[u];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    for (int i = 0; i < nmax; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n, greater<pair<int, int>>());
    int cur = 1;
    for (int i = 0; i < n; ++i)
    {
        int pos = p[i].second;
        int val = p[i].first;
        mark[pos] = true;
        if (pos and mark[pos - 1])
            dsu(pos, pos - 1);
        if (pos < n - 1 and mark[pos + 1])
            dsu(pos, pos + 1);
        int s = sz[find(pos)];
        while (cur <= s)
            ans[cur++] = val;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
