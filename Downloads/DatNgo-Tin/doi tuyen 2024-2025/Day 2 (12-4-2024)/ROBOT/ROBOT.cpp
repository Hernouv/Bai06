#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;

bool que_ue[nmax];
int n, k;

void not_main()
{
    cin >> n;
    int res = n;
    for (int i = n + 1; i <= 2 * n; ++i)
        que_ue[i] = true;
    cin >> k;
    int a, b;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a >> b;
        if (a == b)
            cout << res << '\n';
        if (a > b)
            swap(a, b);
        if (que_ue[a] == que_ue[b])
            cout << res << '\n';
        else if (que_ue[a] == 1 and que_ue[b] == 0)
        {
            if (a <= n and b >= n + 1)
                ++res;
            cout << res << '\n';
            swap(que_ue[a], que_ue[b]);
        }
        else if (que_ue[a] == 0 and que_ue[b] == 1)
        {
            if (a <= n and b >= n + 1)
                --res;
            cout << res << '\n';
            swap(que_ue[a], que_ue[b]);
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ROBOT.inp", "r"))
    {
        freopen("ROBOT.inp", "r", stdin);
        freopen("ROBOT.out", "w", stdout);
    }
    not_main();
    return 0;
}