#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef unsigned long long ull;
ull n, k, res = 1e18;

bool prime[33000];

void erastos()
{
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 33000; ++i)
        if (prime[i])
            for (int j = i * i; j < 33000; j += i)
                prime[j] = false;
}

vector<pair<ull, ull>> fprimes;
vector<ull> cmp;

void factorization(ull inp)
{
    int it = -1;
    for (ull i = 2; i * i <= inp; ++i)
        if (prime[(int)i])
            if (inp % i == 0)
            {
                ++it;
                fprimes.emplace_back(i, 0);
                while (inp % i == 0)
                {
                    ++fprimes[it].se;
                    inp /= i;
                }
            }
    if (inp > 1)
        fprimes.emplace_back(inp, 1);
}

void not_main()
{
    cin >> n >> k;

    erastos();
    factorization(k);
    for (pair<ull, int> x : fprimes)
    {
        ull t_cnt = 0;
        ull t = n;
        while (t >= x.fi)
        {
            t_cnt += (t / x.fi);
            t /= x.fi;
        }
        cmp.push_back(t_cnt);
    }

    for (int i = 0; i < cmp.size(); ++i)
        minimize(res, cmp[i] / fprimes[i].se);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BASEK.INP", "r"))
    {
        freopen("BASEK.INP", "r", stdin);
        freopen("BASEK.OUT", "w", stdout);
    }
    not_main();
    return 0;
}