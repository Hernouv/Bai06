#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 3e5 + 10;
const int base = 311;
const ll mod = 1e9 + 7;
const int outbound = 1e6;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

ll hashLR[nmax], hashRL[nmax], H[nmax];
string inp;
int inp_sz;
int cen1 = -1, cen2 = -1;
int res_cen1 = -1, res_cen2 = -1;

ll get_hashLR(int l, int r)
{
    return (hashLR[r] - hashLR[l - 1] * H[r - l + 1] + mod * mod) % mod;
}

ll get_hashRL(int l, int r)
{
    return (hashRL[l] - hashRL[r + 1] * H[r - l + 1] + mod * mod) % mod;
}

void not_main()
{
    cin >> inp;
    inp_sz = inp.size();
    if (inp_sz == 1)
    {
        cout << inp;
        return;
    }

    inp = ' ' + inp;
    H[0] = 1;
    for (int i = 1; i <= inp_sz + 1; ++i)
        H[i] = 1LL * (H[i - 1] * base) % mod;

    for (int i = 1; i <= inp_sz; ++i)
        hashLR[i] = 1LL * (hashLR[i - 1] * base + inp[i]) % mod;
    for (int i = inp_sz; i >= 1; --i)
        hashRL[i] = 1LL * (hashRL[i + 1] * base + inp[i]) % mod;

    for (int i = 1; i <= inp_sz; ++i)
    {
        int Ld = i - 1, Rd = inp_sz - i;
        int d = min(Ld, Rd);
        if (get_hashLR(i - d, i) == get_hashRL(i, i + d))
        {
            if (maximize(res_cen1, d))
                cen1 = i;
            else
                break;
        }
    }

    for (int i = 1; i < inp_sz; ++i)
    {
        int Ld = i - 1, Rd = inp_sz - i - 1;
        int d = min(Ld, Rd);
        if (get_hashLR(i - d, i) == get_hashRL(i + 1, i + d + 1))
        {
            if (maximize(res_cen2, d))
                cen2 = i;
            else
                break;
        }
    }

    if (2 * res_cen2 > 2 * res_cen1 - 1)
    {
        if (cen2 - 1 > inp_sz - (cen2 + 1))
        {
            for (int i = 1; i <= inp_sz; ++i)
                cout << inp[i];
            for (int i = cen2 - res_cen2 - 1; i >= 1; --i)
                cout << inp[i];
        }
        else
        {
            for (int i = inp_sz; i > cen2 * 2; --i)
                cout << inp[i];
            for (int i = 1; i <= inp_sz; ++i)
                cout << inp[i];
        }
    }
    else
    {
        if (cen1 - 1 > inp_sz - cen1)
        {
            for (int i = 1; i <= inp_sz; ++i)
                cout << inp[i];
            for (int i = cen1 - res_cen1 - 1; i >= 1; --i)
                cout << inp[i];
        }
        else
        {
            for (int i = inp_sz; i >= cen1 * 2; --i)
                cout << inp[i];
            for (int i = 1; i <= inp_sz; ++i)
                cout << inp[i];
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("parole.inp", "r"))
    {
        freopen("parole.inp", "r", stdin);
        freopen("parole.out", "w", stdout);
    }
    not_main();
    return 0;
}