#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e3 + 10;

int proc[nmax][nmax];
vector<ii> rq;

void not_main()
{
    int n, k, maxn = 0, maxk = 0;
    while (cin >> n >> k)
    {
        rq.emplace_back(n, k);
        maxn = max(maxn, n);
        maxk = max(maxk, k);
    }

    for (int i = 0; i <= maxn; ++i)
    {
        proc[i][0] = 1;
        proc[i][i] = 1;
    }

    for (int i = 1; i <= maxn; ++i)
        for (int j = 1; j <= maxk; ++j)
            proc[i][j] = proc[i - 1][j - 1] + proc[i - 1][j];

    for (ii t : rq)
    {
        cout << proc[t.fi][t.se] << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MARIO.INP", "r"))
    {
        freopen("MARIO.INP", "r", stdin);
        freopen("MARIO.OUT", "w", stdout);
    }
    not_main();
    return 0;
}