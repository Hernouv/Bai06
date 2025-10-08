#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
typedef long long ll;

int erastos[nmax];
int mul_prime[nmax];
ll cnt[nmax], res = 0;
vector<int> val_list;
int L, R;

void sieve(int lim)
{
    for (int i = 1; i <= lim; ++i)
    {
        erastos[i] = i;
        mul_prime[i] = 1;
    }

    for (int i = 2; i <= lim; ++i)
        if (erastos[i] == i)
            for (int j = i; j <= lim; j += i)
            {
                erastos[j] = i;
                mul_prime[j] *= i;
            }
}

void not_main()
{
    cin >> L >> R;
    sieve(R);

    for (int i = L; i <= R; ++i)
    {
        if (!cnt[mul_prime[i]])
            val_list.push_back(mul_prime[i]);
        ++cnt[mul_prime[i]];
    }

    for (int x : val_list)
    {
        ll t1 = cnt[x], t2 = cnt[x] - 1;
        res += (1LL * (t1 * t2) / 2);
    }

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SAMEPAIR.INP", "r"))
    {
        freopen("SAMEPAIR.INP", "r", stdin);
        freopen("SAMEPAIR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}