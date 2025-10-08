#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
char buf[MAXN];

int modpow(int a, int b, int mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (long long)res * a % mod;
        }
        a = (long long)a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> g[MAXN];
vector<int> graph[MAXN];
int visited[MAXN];
int comp;

void myDfs(int from, int par)
{
    visited[from] = true;
    for (int i = 0; i < g[from].size(); i++)
    {
        int to = g[from][i];
        if (to != par)
        {
            myDfs(to, from);
        }
        else
        {
            assert(visited[to] == true);
        }
    }
}

void addEdge(int from, int to)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(int from)
{
    visited[from] = comp;
    for (int i = 0; i < graph[from].size(); i++)
    {
        int to = graph[from][i];
        if (!visited[to])
        {
            dfs(to);
        }
    }
}

int main()
{
    int T, sumN = 0, sumQ = 0;
    scanf("%d", &T);
    assert(T >= 1 && T <= 100000);
    while (T--)
    {
        int n, Q;
        scanf("%d %d", &n, &Q);
        assert(n >= 1 && n <= 100000);
        assert(Q >= 0 && Q <= 100000);
        sumN += n;
        sumQ += Q;
        set<pair<int, int>> st;
        for (int i = 0; i + 1 < n; i++)
        {
            int from, to;
            scanf("%d %d", &from, &to);
            assert(from >= 1 && from <= n);
            assert(to >= 1 && to <= n);
            from--;
            to--;
            g[from].push_back(to);
            g[to].push_back(from);
            if (from > to)
            {
                swap(from, to);
            }
            st.insert(make_pair(from, to));
        }
        assert(st.size() == n - 1);
        for (int i = 0; i < Q; i++)
        {
            int u, v, parity;
            scanf("%d %d %d", &u, &v, &parity);
            assert(u >= 1 && u <= n);
            assert(v >= 1 && v <= n);
            assert(parity >= 0 && parity <= 1);
            u--;
            v--;
            if (parity == 0)
            {
                addEdge(2 * u, 2 * v);
                addEdge(2 * u + 1, 2 * v + 1);
            }
            else
            {
                addEdge(2 * u, 2 * v + 1);
                addEdge(2 * u + 1, 2 * v);
            }
        }
        comp = 1;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 2 * n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                comp++;
            }
        }
        int ok = true;
        for (int i = 0; i < n; i++)
        {
            if (visited[2 * i] == visited[2 * i + 1])
            {
                ok = false;
            }
        }
        int ans = ok ? modpow(2, comp / 2 - 1, mod) : 0;
        printf("%d\n", ans);
        for (int i = 0; i < 2 * n; i++)
        {
            g[i].clear();
            graph[i].clear();
        }
    }
    assert(sumN <= 1000000);
    assert(sumQ <= 1000000);
    scanf("%s", buf);
    assert(strlen(buf) == 0);
    return 0;
}