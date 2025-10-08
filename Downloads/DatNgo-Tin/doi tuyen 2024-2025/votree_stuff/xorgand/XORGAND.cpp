#include "bits/stdc++.h"
using namespace std;
using ll = long long int;

auto get_val = [](ll x)
{
    for (int bit = 31; bit >= 0; --bit)
    {
        if (x & (1LL << bit))
            return bit;
    }
    return 32;
};

void not_main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &x : a)
        cin >> x;

    vector<array<ll, 33>> bit_array(n);
    for (int i = 0; i < n; ++i)
    {
        if (i)
            bit_array[i] = bit_array[i - 1];
        ++bit_array[i][get_val(a[i])];
    }
    auto get = [&](int L, int R, int b)
    {
        int ret = bit_array[R][b];
        if (L)
            ret -= bit_array[L - 1][b];
        return ret;
    };

    int q;
    cin >> q;
    int L, R, x;
    for (int i = 1; i <= q; ++i)
    {
        cin >> L >> R >> x;
        cout << R - L + 1 - get(L - 1, R - 1, get_val(x)) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("XORGAND.INP", "r"))
    {
        freopen("XORGAND.INP", "r", stdin);
        freopen("XORGAND.OUT", "w", stdout);
    }
    not_main();
    return 0;
}