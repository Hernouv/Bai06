#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int nmax = 1e6 + 5;
ll sum[nmax];
ll f[nmax];
ll a[nmax];
int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    k--;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    deque<ll> q;
    q.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (q.size() and i - q.front() > k + 1)
            q.pop_front();

        if (q.size())
            f[i] = f[q.front()] + sum[i - 1] - sum[q.front()];
        while (q.size() and f[q.back()] - sum[q.back()] <= f[i] - sum[i])
            q.pop_back();
        q.push_back(i);
    }

    if (q.size() and n - q.front() > k)
        q.pop_front();
    cout << f[q.front()] + sum[n] - sum[q.front()];
    return 0;
}