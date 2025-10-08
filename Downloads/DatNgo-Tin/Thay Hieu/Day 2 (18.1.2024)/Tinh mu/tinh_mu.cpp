#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull mod = 1e9 + 7;

ull a;
string b;

ull pwrmod(ull base, ull expo)
{
    if (!expo)
        return 1;
    ull t = pwrmod(base, expo >> 1);
    t = (t * t) % mod;
    if (expo & 1)
        t = (t * base) % mod;
    return t;
}

ull expo_proc(ull base, string expo)
{
    ull ret = 1;
    for (int i = 0; i < expo.size(); ++i)
    {
        ret = pwrmod(ret, 10);
        ull temp_digit = expo[i] - '0';
        ret = (ret * pwrmod(a, temp_digit)) % mod;
    }
    return ret;
}

void not_main()
{
    cin >> a >> b;
    cout << expo_proc(a, b);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}