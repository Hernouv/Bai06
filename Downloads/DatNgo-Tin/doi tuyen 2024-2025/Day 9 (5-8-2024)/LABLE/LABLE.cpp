#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<bool> loop(n, false);
    for (int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        if (u == v)
        {
            loop[u] = true;
        }
    }
    vector<int> own(n, -1);
    vector<bool> dagloop;
    vector<int> dagcnt;
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
                dagcnt.push_back(0);
                dagloop.push_back(false);
                while (true)
                {
                    int v = st.top();
                    st.pop();
                    own[v] = comps;
                    dagcnt.back()++;
                    dagloop.back() = dagloop.back() || loop[v] || (dagcnt.back() > 1);
                    if (v == u)
                    {
                        break;
                    }
                }
                ++comps;
            }
        };
        dfs(0);
    }
    vector<vector<int>> ee(comps);
    vector<int> dagdeg(comps, 0);
    for (int u = 0; u < n; ++u)
    {
        for (auto v : e[u])
        {
            if (own[u] != -1 && own[v] != -1 && own[u] != own[v])
            {
                ++dagdeg[own[v]];
                ee[own[u]].push_back(own[v]);
            }
        }
    }
    assert(dagdeg[own[0]] == 0);
    vector<int> dp(comps, 0);
    dp[own[0]] = 1;
    queue<int> q;
    q.push(own[0]);
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        for (auto v : ee[u])
        {
            --dagdeg[v];
            dagloop[v] = dagloop[v] || dagloop[u];
            dp[v] = min(dp[v] + dp[u], 2);
            if (dagdeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (own[i] == -1)
        {
            cout << "0 ";
            continue;
        }
        if (dagloop[own[i]])
        {
            cout << "-1 ";
            continue;
        }
        cout << dp[own[i]] << " ";
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("LABLE.INP", "r"))
    {
        freopen("LABLE.INP", "r", stdin);
        freopen("LABLE.OUT", "w", stdout);
    }
    solve();
    return 0;
}