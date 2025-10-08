#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += 1LL * a[i];

    cout << ans;
}

int32_t main(void)
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("demo.inp", "r"))
    {
        freopen("demo.inp", "r", stdin);
        freopen("demo.ans", "w", stdout);
    }
    not_main();
}