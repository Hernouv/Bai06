#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int s[100001];
int n;

void dfs(int indx)
{
    s[indx] = 1;
    for (auto v : graph[indx])
    {
        dfs(v);
        s[u] += s[v];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(s, 0, sizeof(s));
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int par;
        cin >> par;
        graph[par].push_back(i);
    }
    for (int i = 1; i <= n; ++i)d
}
