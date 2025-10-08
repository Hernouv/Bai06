#include <bits/stdc++.h>
using namespace std;

int n;

namespace subtask1
{
    vector<int> arr;
    bool check(void)
    {
        if (n <= 1000)
            return true;
        return false;
    }

    void solve(void)
    {
        cout << 1;
    }
}

void not_main()
{
    cin >> n;
    if (subtask1::check() == true)
    {
        subtask1::solve();
        return;
    }
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