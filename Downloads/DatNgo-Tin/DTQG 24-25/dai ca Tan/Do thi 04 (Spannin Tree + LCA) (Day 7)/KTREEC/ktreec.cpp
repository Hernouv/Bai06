#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, C, q;
vector<vector<int>> adj;
vector<int> color_node;
vector<int> size_subtree;
vector<int> centroid_parent_node;
vector<bool> removed_centroid;
vector<vector<pair<int, int>>> centroid_ancestors_list;
vector<vector<pair<int, int>>> min_distance;

void calculate_size(int u, int p)
{
    size_subtree[u] = 1;
    for (auto &v : adj[u])
    {
        if (v != p && !removed_centroid[v])
        {
            calculate_size(v, u);
            size_subtree[u] += size_subtree[v];
        }
    }
}

int get_centroid(int u, int p, int total_size)
{
    for (auto &v : adj[u])
    {
        if (v != p && !removed_centroid[v] && size_subtree[v] > total_size / 2)
        {
            return get_centroid(v, u, total_size);
        }
    }
    return u;
}

void assign_distance(int u, int p, int centroid, int depth, vector<pair<int, int>> &current_list)
{
    centroid_ancestors_list[u].emplace_back(centroid, depth);
    for (auto &v : adj[u])
    {
        if (v != p && !removed_centroid[v])
        {
            assign_distance(v, u, centroid, depth + 1, current_list);
        }
    }
}

void build_centroid(int u, int p)
{
    calculate_size(u, -1);
    int centroid = get_centroid(u, -1, size_subtree[u]);
    centroid_parent_node[centroid] = p;
    vector<pair<int, int>> current_list;
    assign_distance(centroid, -1, centroid, 0, current_list);
    removed_centroid[centroid] = true;
    for (auto &v : adj[centroid])
    {
        if (!removed_centroid[v])
        {
            build_centroid(v, centroid);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> C;
    color_node.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> color_node[i];
    }
    size_subtree.assign(n + 1, 0);
    centroid_parent_node.assign(n + 1, -1);
    removed_centroid.assign(n + 1, false);
    centroid_ancestors_list.assign(n + 1, vector<pair<int, int>>());
    build_centroid(1, -1);
    min_distance.assign(C + 1, vector<pair<int, int>>());
    for (int u = 1; u <= n; ++u)
    {
        int c = color_node[u];
        for (auto &[centroid, dist] : centroid_ancestors_list[u])
        {
            min_distance[c].emplace_back(centroid, dist);
        }
    }
    for (int c = 1; c <= C; ++c)
    {
        if (min_distance[c].empty())
            continue;
        // Sort by centroid id
        sort(min_distance[c].begin(), min_distance[c].end());
        vector<pair<int, int>> tmp;
        int last_centroid = -1;
        int min_d = INF;
        for (auto &[x, d] : min_distance[c])
        {
            if (x != last_centroid)
            {
                if (last_centroid != -1)
                {
                    tmp.emplace_back(last_centroid, min_d);
                }
                last_centroid = x;
                min_d = d;
            }
            else
            {
                if (d < min_d)
                {
                    min_d = d;
                }
            }
        }
        if (last_centroid != -1)
        {
            tmp.emplace_back(last_centroid, min_d);
        }
        min_distance[c] = move(tmp);
    }

    cin >> q;
    while (q--)
    {
        int v, c;
        cin >> v >> c;
        if (c < 1 || c > C || min_distance[c].empty())
        {
            cout << "-1\n";
            continue;
        }
        int answer = INF;
        for (auto &[centroid, dist_v] : centroid_ancestors_list[v])
        {
            int left = 0, right = min_distance[c].size() - 1;
            int found_dist = INF;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (min_distance[c][mid].first == centroid)
                {
                    found_dist = min_distance[c][mid].second;
                    break;
                }
                else if (min_distance[c][mid].first < centroid)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            if (found_dist != INF)
            {
                answer = min(answer, dist_v + found_dist);
            }
        }
        if (answer != INF)
        {
            cout << answer << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }
}
