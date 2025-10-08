#include <bits/stdc++.h>
using namespace std;

long long r[1000001];
const long long mod = 2023;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("MULTIPLE.INP", "r", stdin);
    freopen("MULTIPLE.OUT", "w", stdout);
    r[1] = 1;
    long long n, incr;
    cin >> n >> incr;
    for (int i = 2; i <= n; ++i)
    {
        r[i] = (r[i - 1] * incr) % mod;
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + r[i]) % mod;
    cout << res;
    return 0;
}