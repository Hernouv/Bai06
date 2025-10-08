#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

vector<int> A;
vector<vector<int>> A_exponents;

// Sieve of Eratosthenes to find all primes up to 500
vector<int> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

vector<int> primes = sieve(500);
int P = primes.size();

// Precompute p^e % MOD for each prime and e up to 10
vector<vector<long long>> pow_p_e;
void precompute_powers()
{
    pow_p_e.resize(P);
    for (int i = 0; i < P; ++i)
    {
        int p = primes[i];
        vector<long long> tmp(10, 1);
        long long val = 1;
        for (int e = 1; e < 10; ++e)
        {
            val = (val * p) % MOD;
            tmp[e] = val;
        }
        pow_p_e[i] = tmp;
    }
}

// Function to compute LCM mod MOD from exponents
long long compute_lcm_mod(const vector<int> &exponents)
{
    long long res = 1;
    for (int i = 0; i < P; ++i)
    {
        if (exponents[i] > 0)
        {
            res = (res * pow_p_e[i][exponents[i]]) % MOD;
        }
    }
    return res;
}

// Function to get prime exponents of a number
vector<int> get_prime_exponents(int a)
{
    vector<int> exponents(P, 0);
    for (int i = 0; i < P; ++i)
    {
        int p = primes[i];
        while (a % p == 0)
        {
            exponents[i]++;
            a /= p;
        }
        if (a == 1)
            break;
    }
    return exponents;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        A.resize(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> A[i];
        }

        A_exponents.resize(N);
        for (int i = 0; i < N; ++i)
        {
            A_exponents[i] = get_prime_exponents(A[i]);
        }

        map<vector<int>, long long> dp;
        for (const auto &a_exp : A_exponents)
        {
            map<vector<int>, long long> dp_new;
            for (const auto &[l_exp, cnt] : dp)
            {
                vector<int> new_l_exp(P);
                for (int i = 0; i < P; ++i)
                {
                    new_l_exp[i] = max(l_exp[i], a_exp[i]);
                }
                dp_new[new_l_exp] = (dp_new[new_l_exp] + cnt) % MOD;
            }
            dp_new[a_exp] = (dp_new[a_exp] + 1) % MOD;
            for (const auto &[l_exp, cnt] : dp_new)
            {
                dp[l_exp] = (dp[l_exp] + cnt) % MOD;
            }
        }

        long long total = 0;
        for (const auto &[l_exp, cnt] : dp)
        {
            long long l_mod = compute_lcm_mod(l_exp);
            total = (total + l_mod * cnt) % MOD;
        }
        cout << total << "\n";
    }
}

int main()
{
    precompute_powers();
    solve();
    return 0;
}
