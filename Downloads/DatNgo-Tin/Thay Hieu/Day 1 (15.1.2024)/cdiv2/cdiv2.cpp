#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int lim = 3e6 + 10;
const int nmax = 1e6 + 10;
const int mod = 123456789;

int largest_prime_div[lim];
long long expo[lim];
int n, a[nmax], maxnum;

void erastos()
{
    for (int i = 2; i <= maxnum; ++i)
        largest_prime_div[i] = i;

    for (int i = 2; i * i <= maxnum; ++i)
        if (largest_prime_div[i] == i)
            for (int j = i * i; j <= maxnum; j += i)
                largest_prime_div[j] = i;
}

void not_main()
{
    cin >> n;
    maxnum = n;
    erastos();

    for (int i = 1; i <= n; ++i)
    {
        if (i % 10 == 4)
            continue;
        int t = i;
        while (t > 1)
        {
            ++expo[largest_prime_div[t]];
            t /= largest_prime_div[t];
        }
    }

    long long res = 1;
    for (int i = 1; i <= maxnum; ++i)
        if (largest_prime_div[i] == i)
            res = res * (expo[i] + 1) % mod;

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("CDIV.INP", "r"))
    {
        freopen("CDIV.OUT", "r", stdin);
        freopen("CDIV.OUT", "w", stdout);
    }
    not_main();
    return 0;
}