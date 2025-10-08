#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 5e4 + 10;
const double dzero = 1e-12;

#define fi first
#define se second

int n, k;
ll p, q;
ll val[nmax], wt[nmax];

ll find_gcd(ll a, ll b)
{
    while (a and b)
    {
        if (a < b)
            swap(a, b);
        a %= b;
    }
    return max(a, b);
}

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> val[i] >> wt[i];

    double lo_res = 0, hi_res = 1000000;
    for (int i = 1; i <= 100; ++i)
    {
        double mid = (double)(lo_res + hi_res) / 2.0;
        vector<pair<double, int>> proc;
        for (int i = 1; i <= n; ++i)
            proc.emplace_back((double)val[i] - mid * wt[i], i);
        sort(proc.begin(), proc.end());

        double sum = 0;
        for (int i = n - k; i < n; ++i)
            sum = (double)sum + proc[i].fi;
        if (sum > -dzero)
        {
            p = 0, q = 0;
            for (int i = n - k; i < n; ++i)
                p += val[proc[i].se], q += wt[proc[i].se];
            lo_res = mid;
        }
        else
            hi_res = mid;
    }

    ll g = find_gcd(p, q);
    cout << p / g << ' ' << q / g;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DIAMOND.INP", "r"))
    {
        freopen("DIAMOND.INP", "r", stdin);
        freopen("DIAMOND.OUT", "w", stdout);
    }
    not_main();
    return 0;
}