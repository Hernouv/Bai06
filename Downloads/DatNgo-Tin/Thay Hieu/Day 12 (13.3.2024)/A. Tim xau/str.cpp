#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 1e6 + 10;
const ll mod = 1e9 + 7;
const int hashc = 311;

ll hashA[nmax], hashB[nmax], H[nmax];
string a, b;

ll getHash(int l, int r)
{
    return (hashB[r] - hashB[l - 1] * H[r - l + 1] + mod * mod) % mod;
}

void not_main()
{
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    H[0] = 1;
    for (int i = 1; i < b.size(); ++i)
        H[i] = 1LL * (H[i - 1] * hashc) % mod;
    for (int i = 1; i < a.size(); ++i)
        hashA[i] = 1LL * (hashA[i - 1] * hashc + a[i]) % mod;
    for (int i = 1; i < b.size(); ++i)
        hashB[i] = 1LL * (hashB[i - 1] * hashc + b[i]) % mod;

    int a_sz = a.size() - 1;
    int poscnt = 0;
    vector<int> pos;
    for (int i = a.size() - 1; i < b.size(); ++i)
    {
        int L = i - a_sz + 1;
        if (getHash(L, i) == hashA[a_sz])
        {
            ++poscnt;
            pos.push_back(L);
        }
    }
    cout << poscnt << '\n';
    for (int p : pos)
        cout << p << ' ';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DEMO.INP", "r"))
    {
        freopen("DEMO.INP", "r", stdin);
        freopen("DEMO.OUT", "w", stdout);
    }
    not_main();
    return 0;
}