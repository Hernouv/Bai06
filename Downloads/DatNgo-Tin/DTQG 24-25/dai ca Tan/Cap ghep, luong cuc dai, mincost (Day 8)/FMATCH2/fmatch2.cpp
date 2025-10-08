#include <bits/stdc++.h>
using namespace std;

class MinCostPerfectMatching
{
private:
    int n;
    vector<vector<int>> cost;
    vector<int> u, v;
    vector<int> p, way;
    vector<bool> used;
    vector<int> minv;

public:
    MinCostPerfectMatching(int size, vector<vector<int>> &costMatrix)
        : n(size), cost(costMatrix), u(size + 1), v(size + 1), p(size + 1), way(size + 1), used(size + 1), minv(size + 1) {}

    pair<int, vector<pair<int, int>>> solve()
    {
        for (int i = 1; i <= n; ++i)
        {
            p[0] = i;
            int j0 = 0;
            fill(used.begin(), used.end(), false);
            fill(minv.begin(), minv.end(), INT_MAX);
            do
            {
                used[j0] = true;
                int i0 = p[j0], delta = INT_MAX, j1;
                for (int j = 1; j <= n; ++j)
                {
                    if (!used[j])
                    {
                        int cur = cost[i0 - 1][j - 1] - u[i0] - v[j];
                        if (cur < minv[j])
                        {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta)
                        {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }
                for (int j = 0; j <= n; ++j)
                {
                    if (used[j])
                    {
                        u[p[j]] += delta;
                        v[j] -= delta;
                    }
                    else
                    {
                        minv[j] -= delta;
                    }
                }
                j0 = j1;
            } while (p[j0] != 0);

            do
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0 != 0);
        }

        vector<pair<int, int>> result;
        for (int j = 1; j <= n; ++j)
        {
            if (p[j] > 0)
                result.emplace_back(p[j], j);
        }
        return {v[0], result};
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n, 1e7));

    int tu, tv, tc;
    while (cin >> tu >> tv >> tc)
    {
        cost[tu - 1][tv - 1] = tc;
    }

    MinCostPerfectMatching mcp(n, cost);
    auto [minCost, matching] = mcp.solve();

    cout << -minCost << "\n";

    auto cond = [&](pair<int, int> &x, pair<int, int> &y)
    {
        if (x.first == y.first)
            return x.second < y.second;
        return (x.first < y.first);
    };

    sort(matching.begin(), matching.end(), cond);
    for (pair<int, int> edge : matching)
    {
        cout << edge.first << ' ' << edge.second << '\n';
    }

    return 0;
}
