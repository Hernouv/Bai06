#include <iostream>
using namespace std;

#define ll long long
#define cnst 1000000007

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return (res + p) % p;
}

ll modinv(ll x)
{
    return power(x, cnst - 2, cnst);
}

ll sum(ll n)
{
    ll retval = ((((n % cnst) * ((n + 1) % cnst)) % cnst) * modinv(2)) % cnst;
    return retval;
}

ll divisorSum(ll n)
{
    ll l = 1;
    ll ans = 0;

    while (l <= n)
    {
        ll k = n / l;
        ll r = n / k;
        k %= cnst;
        ans += ((sum(r) - sum(l - 1) %
            cnst) * k) % cnst;

        //ans %= cnst;
        l = r + 1;
    }
    //ans = ans % cnst;
    //if (ans * 1 < 0) return cnst + ans;
    return ans;
}

int main()
{
    freopen("divsum.inp", "r", stdin);
    freopen("divsum.out", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll res = (divisorSum(b) - divisorSum(a - 1)) % cnst;
    if (res < 0) res = cnst + res;
    cout << res;
    return 0;
}