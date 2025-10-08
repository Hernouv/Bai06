#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long t, n;
long long divCnt[75][110];
long long dp[156][110];

void setVal()
{
    for (int i = 0; i < 75; ++i)
        for (int j = 0; j < 110; ++j)
            divCnt[i][j] = 0;
}

long long pwrmod(long long base, long long expo)
{
    if (!expo)
        return 1;
    long long t = pwrmod(base, expo >> 1);
    t = (t * t) % mod;
    if (expo & 1)
        t = (t * base) % mod;
    return t;
}

void process()
{
    long long res = 0;
    cin >> n;
    long long num;
    long long tmax = -1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        tmax = max(tmax, num);
        for (int j = 1; j * j <= num; ++j)
            if (num % j == 0)
            {
                ++divCnt[j][t];
                if (j != num / j)
                    ++divCnt[num / j][t];
            }
    }

    for (int i = tmax; i >= 1; --i)
    {
        if (divCnt[i][t])
            dp[i][t] = (pwrmod(2, divCnt[i][t]) + mod - 1) % mod;
        for (int j = 2 * i; j <= tmax; j += i)
            dp[i][t] -= dp[j][t];
    }

    for (int i = 1; i <= tmax; ++i)
        res = (res + i * dp[i][t]) % mod;
    cout << res << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    setVal();
    cin >> t;
    while (t--)
        process();
    return 0;
}