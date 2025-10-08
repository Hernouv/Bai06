#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("FOODS.INP", "r"))
    {
        freopen("FOODS.INP", "r", stdin);
        freopen("FOODS.OUT", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
    }
    vector<int> own(n, -1);
    vector<long long> cnt;
    int comps = 0;
    {
        int timer = 0;
        vector<int> num(n, -1);
        vector<int> low(n, -1);
        stack<int> st;
        function<void(int)> dfs = [&](int u)
        {
            num[u] = low[u] = timer++;
            st.push(u);
            for (auto v : e[u])
            {
                if (own[v] != -1)
                {
                    continue;
                }
                if (num[v] != -1)
                {
                    low[u] = min(low[u], num[v]);
                }
                else
                {
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                }
            }
            if (num[u] == low[u])
            {
                cnt.push_back(0);
                while (true)
                {
                    int v = st.top();
                    st.pop();
                    own[v] = comps;
                    cnt.back() += c[v];
                    if (v == u)
                    {
                        break;
                    }
                }
                ++comps;
            }
        };
        for (int i = 0; i < n; ++i)
        {
            if (own[i] == -1)
            {
                dfs(i);
            }
        }
    }
    vector<vector<int>> ee(comps);
    vector<int> deg(comps, 0);
    for (int u = 0; u < n; ++u)
    {
        for (auto v : e[u])
        {
            if (own[u] != own[v])
            {
                ++deg[own[u]];
                ee[own[v]].push_back(own[u]);
            }
        }
    }
    queue<int> q;
    vector<long long> dp(comps, 0);
    for (int u = 0; u < comps; ++u)
    {
        if (deg[u] == 0)
        {
            q.push(u);
            dp[u] = cnt[u];
        }
    }
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto v : ee[u])
        {
            --deg[v];
            dp[v] = max(dp[v], dp[u] + cnt[v]);
            if (deg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << dp[own[i]] << " ";
    }
    return 0;
}
