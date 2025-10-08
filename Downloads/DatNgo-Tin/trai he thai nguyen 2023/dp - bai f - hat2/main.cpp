#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;
ll factmod[1000001];
ll combmod[1000001];
ll res = 1;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    factmod[0] = factmod[1] = 1;
    for (int i = 2; i <= 1000000; ++i) factmod[i] = (factmod[i - 1] * i + mod) % mod;

    ll n, m;
    cin >> n >> m;
    combmod[n] = combmod[0] = 1;
    for (int i = 1; i <= n / 2; ++i)
    {
        combmod[i] = (combmod[i - 1] * (n - i + 1) / i + mod) % mod;
        combmod[n - i] = combmod[i];
    }
    for (ll i = 2; i <= n; ++i)
        res = (res * i) % mod;
    if (m < n) res = (res + mod - 1) % mod;
    for (int i = 2; i <= n - m - 1; ++i)
    {
        ll mul = combmod[i] * factmod[i - 1];
        mul %= mod;
        res = (res + mod - mul) % mod;
    }
    cout << res;
    return 0;
}
