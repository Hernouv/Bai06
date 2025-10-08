#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

vector<long long> factorial;
vector<long long> mod_inverse;

long long pwrmod(long long base, long long expo)
{
    if (!expo)
        return 1;

    long long result = 1;
    while (expo > 0)
    {
        if (expo % 2 == 1)
            result = result * base % MOD;
        base = base * base % MOD;
        expo /= 2;
    }
    return result;
}

void precompute_factorials(int max_n)
{
    factorial.resize(max_n + 1);
    mod_inverse.resize(max_n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= max_n; ++i)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
    mod_inverse[max_n] = pwrmod(factorial[max_n], MOD - 2);
    for (int i = max_n - 1; i >= 1; --i)
    {
        mod_inverse[i] = mod_inverse[i + 1] * i % MOD;
    }
}

long long calculate_result(int n, int m, const vector<int> &a)
{
    long long result = 0;

    for (int mask = 0; mask < (1 << n); ++mask)
    {
        int t_cnt = __builtin_popcount(mask);
        long long sign = (t_cnt % 2 == 0) ? -1 : 1;
        int total_boxes = m;
        int total_placed = 0;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                total_boxes -= a[i];
            }
            else
            {
                total_placed += a[i];
            }
        }

        if (total_boxes < 0)
        {
            continue;
        }

        long long ways = factorial[total_boxes] * mod_inverse[total_boxes - total_placed] % MOD;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                ways = ways * mod_inverse[a[i]] % MOD;
            }
        }

        result = (result + sign * ways) % MOD;
    }

    return (result + MOD) % MOD;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int t;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        a[i] = t;
    }

    precompute_factorials(m);
    cout << calculate_result(n, m, a);
    cerr << factorial[9] * mod_inverse[3];
    return 0;
}
