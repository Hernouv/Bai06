#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int n, k;
vector<int> graph[nmax];

void not_main()
{
    cin >> n >> k;
    int tu, tv;
    for (int i = 1; i < n; ++i)
    {
        cin >> tu >> tv;
        graph[tu].push_back(tv);
        graph[tv].push_back(tu);
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}