// Code mau check AC, dung phan xet =((

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 200005;

int n;
vector<int> adj[N];
ll a[N];
ll ans = 0;
unordered_map<ll, int> *freq[N];

void dfs(int u, int p)
{
    freq[u] = new unordered_map<ll, int>();

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(v, u);

        for (auto &it_v : *freq[v])
        {
            ll val_v = it_v.first;
            int cnt_v = it_v.second;
            ll required = 0;
            if (a[u] % val_v == 0)
            {
                required = a[u] / val_v;
                if (freq[u]->count(required) and a[u] % val_v == 0)
                {
                    ans += ll(cnt_v) * freq[u]->at(required);
                }
            }
        }

        for (auto &it_v : *freq[v])
        {
            (*freq[u])[it_v.first] += it_v.second;
        }

        delete freq[v];
    }

    (*freq[u])[a[u]]++;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    dfs(1, 0);

    printf("%lld\n", ans);

    return 0;
}
