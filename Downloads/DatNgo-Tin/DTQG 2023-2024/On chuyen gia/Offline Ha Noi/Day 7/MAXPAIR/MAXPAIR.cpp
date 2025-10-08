#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n;
ll L[100010], R[100010];
ll a[1000010];

void sub1()
{
    ll res = 0;
    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            res = max(res, 1LL * (a[i] + a[j]) * (j - i));

    cout << res;
    return;
}

void sub2()
{
    ll res = 0;
    for (int i = 1; i < n; ++i)
        res = max(res, 1LL * (a[n] + a[i]) * (n - i));

    cout << res;
    return;
}

void sub3()
{
    for (int i = 1; i <= n; ++i)
        L[i] = 1e7, R[i] = -1;

    for (ll i = 1; i <= n; ++i)
    {
        L[a[i]] = min(L[a[i]], i);
        R[a[i]] = max(R[a[i]], i);
    }

    ll res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            res = max(res, 1LL * (i + j) * max(R[j] - L[i], R[i] - L[j]));

    cout << res;
    return;
}

void finalBoss_uh_IMean_lastSub()
{
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    bool s2 = true;
    for (int i = 2; i <= n; ++i)
        if (a[i] < a[i - 1])
        {
            s2 = false;
            break;
        }
    if (s2)
    {
        sub2();
        return;
    }
    ll a_max = -1;
    for (int i = 1; i <= n; ++i)
        a_max = max(a_max, a[i]);
    if (a_max <= 5000)
    {
        sub3();
        return;
    }
    sub1();
    // finalBoss_uh_IMean_lastSub();
    return;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}