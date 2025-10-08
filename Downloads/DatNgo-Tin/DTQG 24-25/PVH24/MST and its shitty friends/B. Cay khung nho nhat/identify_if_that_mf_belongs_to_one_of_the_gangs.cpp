#include <bits/stdc++.h>
using namespace std;

#define whole(_name) _name.begin(), _name.end()

const int nmax = 5e5 + 10;

struct node
{
    int id, u, v, w;
};
vector<node> e;

int n, m;
int root[nmax];
int sz[nmax];
bool chosen[nmax];

void setDefault()
{
    for (int i = 1; i <= n; ++i)
    {
        root[i] = i;
        sz[i] = 1;
    }
}

int find_root(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = find_root(root[u]);
}

bool if_inMST(int u, int v)
{
    int ru = find_root(u);
    int rv = find_root(v);
    if (ru != rv)
        return true;
    return false;
}

void conn(int u, int v)
{
    int ru = find_root(u);
    int rv = find_root(v);
    if (ru == rv)
        return;

    if (sz[ru] < sz[rv])
        swap(ru, rv);
    root[rv] = ru;
    sz[ru] += sz[rv];
}

void not_main()
{
    cin >> n >> m;
    int tu, tv, tw;
    for (int i = 1; i <= m; ++i)
    {
        cin >> tu >> tv >> tw;
        e.push_back({i, tu, tv, tw});
    }
    sort(whole(e), [](node &a, node &b)
         { return a.w < b.w; });
    e.push_back({0, 0, 0, 0});

    setDefault();
    queue<int> tmp_save;
    for (int i = 0; i < m; ++i)
    {
        if (if_inMST(e[i].u, e[i].v))
            tmp_save.push(i);

        if (e[i].w != e[i + 1].w)
            while (!tmp_save.empty())
            {
                int fr = tmp_save.front();
                tmp_save.pop();
                conn(e[fr].u, e[fr].v);
                chosen[e[fr].id] = true;
            }
    }
    for (int i = 1; i <= m; ++i)
        cout << (chosen[i] ? "Yes " : "No ");
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mst.inp", "r"))
    {
        freopen("mst.inp", "r", stdin);
        freopen("mst.out", "w", stdout);
    }
    int s;
    cin >> s;
    not_main();
    return 0;
}