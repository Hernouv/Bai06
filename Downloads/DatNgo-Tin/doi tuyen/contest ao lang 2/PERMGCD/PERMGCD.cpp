#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long n, vmax = 0, test[1001], factmod[1000001];

void setVal(long long lim)
{
    factmod[0] = 1;
    for (long long i = 1; i <= lim; ++i)
        factmod[i] = (factmod[i - 1] * i) % mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("PERMGCD.INP", "r", stdin);
    // freopen("PERMGCD.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> test[i];
        vmax = max(vmax, test[i]);
    }
    setVal(vmax);
    for (int i = 1; i <= n; ++i)
    {
        if (test[i] & 1)
            cout << 0 << '\n';
        else
        {
            test[i] >>= 1;
            cout << factmod[test[i]] * factmod[test[i]] % mod << '\n';
        }
    }
    return 0;
}