#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int nmax = 1e6 + 10;

int n, m;
ll cnt, subcnt;
vector<int> graph[nmax];
int evenodd[nmax];
bool invalid;
ll res = 1;

queue<int> q;
void bfs(int u)
{
    q.push(u);
    evenodd[u] = 1;
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        ++cnt;
        if (evenodd[fr] == 1)
            ++subcnt;
        for (int v : graph[fr])
        {
            if (!evenodd[v])
            {
                evenodd[v] = 3 - evenodd[fr];
                q.push(v);
            }
            else if (evenodd[v] == evenodd[fr])
                invalid = true;
        }
    }
}

ll pwrmod(ll base, ll expo)
{
    if (!expo)
        return 1;
    ll t = pwrmod(base, expo / 2);
    t = (t * t) % mod;
    if (expo % 2 == 1)
        t = (t * base) % mod;
    return t;
}

void not_main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!evenodd[i])
        {
            cnt = 0, subcnt = 0;
            invalid = false;
            bfs(i);
            cerr << cnt << ' ' << subcnt << '\n';
            if (!invalid and cnt > 1)
            {
                ll tmpval = (pwrmod(2, subcnt) + pwrmod(2, cnt - subcnt)) % mod;
                res = res * tmpval % mod;
            }
            else if (invalid)
            {
                cout << 0;
                return;
            }
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BGRAPH.INP", "r"))
    {
        freopen("BGRAPH.INP", "r", stdin);
        freopen("BGRAPH.OUT", "w", stdout);
    }
    not_main();
    return 0;
}