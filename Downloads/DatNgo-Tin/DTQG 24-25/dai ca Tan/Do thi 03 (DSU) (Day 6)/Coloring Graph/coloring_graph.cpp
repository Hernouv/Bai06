#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    int n;
    vector<int> parent;
    vector<int> sz;
    vector<vector<pair<int, int>>> color_count;

    DSU(int size, const vector<int> &colors) : n(size), parent(size + 1), sz(size + 1, 1), color_count(size + 1)
    {
        for (int i = 1; i <= size; ++i)
        {
            color_count[i].emplace_back(colors[i], 1);
            parent[i] = i;
        }
    }

    int find_set(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
};

void not_main()
{
    int n, m;
    cin >> n >> m;
    vector<int> colors_input(n);
    for (auto &c : colors_input)
        cin >> c;
    vector<int> sorted_colors = colors_input;
    sort(sorted_colors.begin(), sorted_colors.end());
    sorted_colors.erase(unique(sorted_colors.begin(), sorted_colors.end()), sorted_colors.end());
    int K = sorted_colors.size();
    unordered_map<int, int> color_map;
    for (int i = 0; i < K; ++i)
    {
        color_map[sorted_colors[i]] = i + 1;
    }
    vector<int> colors(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        colors[i] = color_map[colors_input[i - 1]];
    }
    DSU dsu(n, colors);

    long long total_pairs = 0;
    for (int j = 0; j < m; ++j)
    {
        int u, v;
        cin >> u >> v;
        int fu = dsu.find_set(u);
        int fv = dsu.find_set(v);
        if (fu != fv)
        {
            if (dsu.color_count[fu].size() < dsu.color_count[fv].size())
            {
                swap(fu, fv);
            }
            for (auto &[c, cnt_fv] : dsu.color_count[fv])
            {
                auto it = lower_bound(dsu.color_count[fu].begin(), dsu.color_count[fu].end(), make_pair(c, 0));
                if (it != dsu.color_count[fu].end() && it->first == c)
                {
                    total_pairs += (long long)(it->second) * cnt_fv;
                    it->second += cnt_fv;
                }
                else
                {
                    int pos = distance(dsu.color_count[fu].begin(), lower_bound(dsu.color_count[fu].begin(), dsu.color_count[fu].end(), make_pair(c, 0)));
                    dsu.color_count[fu].emplace(dsu.color_count[fu].begin() + pos, make_pair(c, cnt_fv));
                }
            }
            dsu.parent[fv] = fu;
            dsu.sz[fu] += dsu.sz[fv];
        }
        cout << total_pairs << "\n";
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
