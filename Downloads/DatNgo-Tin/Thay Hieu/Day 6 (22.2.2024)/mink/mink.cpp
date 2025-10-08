#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int nmax = 1e6 + 10;

int n, k;
int a[nmax];
deque<ii> proc;

void process()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i < k; ++i)
    {
        while (!proc.empty() and proc.back().fi >= a[i])
            proc.pop_back();
        proc.emplace_back(a[i], i);
    }
    for (int i = k; i <= n; ++i)
    {
        while (!proc.empty() and proc.front().se < i - k + 1)
            proc.pop_front();
        while (!proc.empty() and proc.back().fi >= a[i])
            proc.pop_back();
        proc.emplace_back(a[i], i);
        cout << proc.front().fi << ' ';
    }
}

void not_main()
{
    int t;
    cin >> t;
    while (t--)
    {
        process();
        cout << '\n';
        proc.clear();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mink.inp", "r"))
    {
        freopen("mink.inp", "r", stdin);
        freopen("mink.out", "w", stdout);
    }
    not_main();
    return 0;
}