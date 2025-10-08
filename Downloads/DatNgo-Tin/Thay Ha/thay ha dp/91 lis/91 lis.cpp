#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll maxn = 1e6 + 10;
vector<ll> a, dp, trace, end_pos, elements;

void print_result(ll n, vector<ll>& a, vector<ll>& dp, vector<ll>& trace)
{
    ll best = 1;
    for (ll i = 2; i <= n; ++i)
        if (dp[i] > dp[best])
            best = i;

    cout << dp[best] << endl;

    while (best)
    {
        elements.push_back(a[best]);
        best = trace[best];
    }

    ll it = 0;
    reverse(elements.begin(), elements.end());
    for (auto x : elements)
    {
        while (a[it] != x) it++;
        cout << it << ' ';
    }

}

ll binary_searching(ll max_length, vector <ll>& a, vector <ll>& end_pos, ll val)
{
    ll p = 0;

    ll l = 1, r = max_length;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;

        if (a[end_pos[mid]] < val)
        {
            p = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return p;
}

void solution(ll n, vector<ll>& a)
{
    dp.resize(n + 1, 0);
    end_pos.resize(n + 1, 0);
    trace.resize(n + 1, 0);

    ll res = 1;
    end_pos[1] = 1;

    for (ll i = 1; i <= n; ++i)
    {
        ll p = binary_searching(res, a, end_pos, a[i]);
        ll k = p + 1;

        if (k > res)
        {
            res = k;
            end_pos[k] = i;
        }
        else if (a[end_pos[k]] > a[i])
            end_pos[k] = i;

        dp[i] = k;
        trace[i] = end_pos[p];
    }

    print_result(n, a, dp, trace);
}

int main()
{
    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(false);

    ll n;
    cin >> n;
    a.resize(n + 1, 0);
    for (ll i = 1; i <= n; ++i)
        cin >> a[i];

    solution(n, a);
    return 0;
}

