#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T &b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e6 + 10;
// const int outbound = 1e9 + 10;

int a[nmax], mincost[nmax];
int n;
long long res = 0;
stack<int> proc;

// void SetDefaultVal()
// {
//     for (int i = 1; i < nmax; ++i)
//         mincost[i] = outbound;
// }

void not_main()
{
    // SetDefaultVal();

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        while (!proc.empty() and proc.top() <= a[i])
            proc.pop();
        if (!proc.empty())
            mincost[i] = proc.top();
        proc.push(a[i]);
    }
    while (!proc.empty())
        proc.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!proc.empty() and proc.top() < a[i])
            proc.pop();
        if (!proc.empty())
        {
            if (mincost[i])
                minimize(mincost[i], proc.top());
            else
                mincost[i] = proc.top();
        }
        proc.push(a[i]);
    }
    for (int i = 1; i <= n; ++i)
        res += mincost[i];
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.out", "w", stdout);
    }
    not_main();
    return 0;
}