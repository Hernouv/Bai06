#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    vector<int> bit;
    int n;
    BIT(int n) : n(n + 1), bit(n + 1) {}
    int sum(int r)
    {
        r++;
        int ret = 0;
        while (r > 0)
        {
            ret += bit[r];
            r -= r & -r;
        }
        return ret;
    }

    void update(int idx, int v)
    {
        idx++;
        while (idx < n)
        {
            bit[idx] += v;
            idx += idx & -idx;
        }
    }
};

const int MAXN = 2e5 + 10;

int tour[MAXN], color[MAXN], answer[MAXN], L_end[MAXN];

vector<int> graph[MAXN];
int idx = 0;

void dfs(int u, int par = 0)
{
    L_end[u] = idx;
    for (int v : graph[u])
    {
        if (v != par)
            dfs(v, u);
    }
    tour[idx] = u;
    idx++;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N, u, v;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> color[i];

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    BIT bit(N);

    map<int, int> last;
    for (int i = 0; i < N; i++)
    {
        if (last.count(color[tour[i]]))
            bit.update(last[color[tour[i]]], -1);

        last[color[tour[i]]] = i;
        bit.update(i, 1);
        answer[tour[i]] = bit.sum(i) - bit.sum(L_end[tour[i]] - 1);
    }

    for (int i = 1; i <= N; i++)
        cout << answer[i] << " ";
}