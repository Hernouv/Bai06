#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 5;
const int Tmax = 105;

int n, T, k;
int L[Tmax], R[Tmax];
bool c[nmax][nmax];

void proc1()
{
    vector<int> res;
    for (int i = 1; i <= T; ++i)
    {
        res.clear();
        res.push_back(L[i]);
        int cnt = 1;
        for (int t = L[i] + 1; t <= R[i]; ++t)
        {
            res.push_back(t);
            int tcnt = cnt;
            while (tcnt >= 1 and c[t][res[tcnt - 1]])
            {
                swap(res[tcnt - 1], res[tcnt]);
                tcnt--;
            }
            cnt++;
        }

        cout << res.size() << ' ';
        for (int x : res)
            cout << x << ' ';
        cout << '\n';
    }
}

struct node
{
    int depth;
    int id;
};
queue<node> q;

int curr_minsize;
int cycle[nmax];
int par[nmax];

void cycle_insert(int u)
{
    for (int i = 3; i >= 1; --i)
    {
        cycle[i] = u;
        u = par[u];
    }
}

vector<int> graph[nmax];
bool find_cycle(int u, int l, int r)
{
    while (!q.empty())
        q.pop();

    q.push({1, u});
    while (!q.empty())
    {
        node V = q.front();
        q.pop();
        if (V.depth == 3)
            return false;
        for (int v : graph[V.id])
        {
            if (v < l or v > r)
                continue;
            par[v] = V.id;
            if (c[v][u])
            {
                cycle_insert(v);
                return true;
            }
            else
                q.push({V.depth + 1, v});
        }
    }
    return false;
}

void proc2()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (c[i][j])
                graph[i].push_back(j);

    for (int i = 1; i <= T; ++i)
    {
        for (int t = L[i]; t <= R[i]; ++t)
        {
            if (find_cycle(t, L[i], R[i]))
            {
                cout << 3 << ' ';
                for (int i = 1; i <= 3; ++i)
                    cout << cycle[i] << ' ';
                cout << '\n';
                break;
            }
            else if (t == R[i])
                cout << -1 << '\n';
        }
    }
}

void not_main()
{
    cin >> n >> T >> k;
    for (int i = 1; i <= T; ++i)
        cin >> L[i] >> R[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> c[i][j];

    if (k == 1)
        proc1();
    else if (k == 2)
        proc2();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}