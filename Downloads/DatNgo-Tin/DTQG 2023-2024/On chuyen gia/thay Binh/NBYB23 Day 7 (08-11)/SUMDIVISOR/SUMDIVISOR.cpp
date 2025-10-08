#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int power(int x, int y, int p)
{

    int res = 1;
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

int modinv(int x)
{
    return power(x, mod - 2, mod);
}

int sum(int n)
{
    int retval = ((((n % mod) * ((n + 1) %
                                 mod)) %
                   mod) *
                  modinv(2)) %
                 mod;
    return retval;
}

int divisorSum(int n)
{
    int l = 1;
    int ans = 0;

    while (l <= n)
    {
        int k = n / l;
        int r = n / k;
        k %= mod;

        ans += ((sum(r) - sum(l - 1) % mod) * k) % mod;

        ans %= mod;
        l = r + 1;
    }
    ans = ans % mod;
    if (ans < 0)
    {
        return ans + mod;
    }
    else
    {
        return ans;
    }
}

signed main()
{
    long long n;
    cin >> n;
    cout << divisorSum(n);
    return 0;
}