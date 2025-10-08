#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define ii pair<int, int>
#define int ll

bool check(const vector<ll> &t, ll val, int k)
{
    int cnt = 1;
    ll sum = 0;
    for (ll it : t)
    {
        if (it > val)
            return false;
        if (sum + it > val)
        {
            cnt++;
            sum = it;
            if (cnt > k)
                return false;
        }
        else
            sum += it;
    }
    return true;
}

int n, k;

void not_main()
{
    cin >> n >> k;
    vector<ll> t(n);
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        l = max(l, t[i]);
        r += t[i];
    }
    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(t, mid, k))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}