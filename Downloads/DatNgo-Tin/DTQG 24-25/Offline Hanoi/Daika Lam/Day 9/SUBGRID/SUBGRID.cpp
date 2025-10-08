#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int long long

const int nmax = 2005;

int n;
bitset<nmax> a[nmax];

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    auto nC2 = [](int x)
    {
        return x * (x - 1) / 2;
    };

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            auto cur = a[i] & a[j];
            int cnt = cur.count();
            ans += nC2(cnt);
        }

    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}