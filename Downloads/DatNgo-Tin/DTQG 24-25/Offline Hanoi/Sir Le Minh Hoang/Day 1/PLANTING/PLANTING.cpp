#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, ll> ill;
#define fi first
#define se second
#define eb emplace_back

const int nmax = 1e5 + 10;

int n;
ll L;
vector<ill> graph[nmax];

void not_main()
{
    cin >> n >> L;
    int tu, tv;
    ll tw;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv >> tw;
        graph[tu].eb(tv, tw);
        graph[tv].eb(tu, tw);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PLANTING.INP", "r"))
    {
        freopen("PLANTING.INP", "r", stdin);
        freopen("PLANTING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}