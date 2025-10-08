#include <bits/stdc++.h> using namespace std;

const long long MOD = 998244353;

struct DSU
{
    int parent;
    vector<int> comp;
    long long cnt, sum, sumSq;
};

int findp(vector<DSU> &dsu, int a) { return dsu[a].parent == a ? a : dsu[a].parent = findp(dsu, dsu[a].parent); }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, long long>> edges;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<DSU> dsu(n + 1);
    vector<long long> dval(n + 1, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dsu[i].parent = i;
        dsu[i].comp.push_back(i);
        dsu[i].cnt = 1;
        dsu[i].sum = 0;
        dsu[i].sumSq = 0;
    }
    sort(edges.begin(), edges.end(), [](auto &a, auto &b)
         { return get<2>(a) > get<2>(b); });
    for (auto &e : edges)
    {
        int u, v;
        long long w;
        tie(u, v, w) = e;
        int ru = findp(dsu, u), rv = findp(dsu, v);
        if (ru == rv)
            continue;
        if (dsu[ru].comp.size() < dsu[rv].comp.size())
            swap(ru, rv);
        long long delta = dval[u] + 1 - dval[v];
        for (auto j : dsu[rv].comp)
            dval[j] += delta;
        for (auto i : dsu[ru].comp)
        {
            long long tmp = ((((dval[i] + 1) % MOD * (dval[i] + 1) % MOD) % MOD * (dsu[rv].cnt % MOD)) % MOD + (2 * ((dval[i] + 1) % MOD) % MOD * (dsu[rv].sum % MOD)) % MOD + (dsu[rv].sumSq % MOD)) % MOD;
            ans[i] = (ans[i] + (w % MOD) * (tmp % MOD)) % MOD;
        }
        for (auto j : dsu[rv].comp)
        {
            long long tmp = ((((dval[j] + 1) % MOD * (dval[j] + 1) % MOD) % MOD * (dsu[ru].cnt % MOD)) % MOD + (2 * ((dval[j] + 1) % MOD) % MOD * (dsu[ru].sum % MOD)) % MOD + (dsu[ru].sumSq % MOD)) % MOD;
            ans[j] = (ans[j] + (w % MOD) * (tmp % MOD)) % MOD;
        }
        dsu[ru].cnt += dsu[rv].cnt;
        dsu[ru].sum = (dsu[ru].sum + dsu[rv].sum + dsu[rv].cnt * delta);
        dsu[ru].sumSq = (dsu[ru].sumSq + dsu[rv].sumSq + 2 * dsu[rv].sum * delta + dsu[rv].cnt * (delta * delta));
        for (auto j : dsu[rv].comp)
            dsu[ru].comp.push_back(j);
        dsu[rv].comp.clear();
        dsu[rv].parent = ru;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ((ans[i] % MOD) + MOD) % MOD << "\n";
    }
    return 0;
}