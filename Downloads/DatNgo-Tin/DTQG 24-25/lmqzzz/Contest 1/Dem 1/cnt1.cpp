#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, N;

void not_main(int id)
{
    cin >> A >> B >> N;
    --A;

    vector<ll> pdiv;
    for (int i = 2; i * i <= N; ++i)
        if (N % i == 0)
        {
            pdiv.push_back(i);
            while (N % i == 0)
                N /= i;
        }
    if (N > 1)
        pdiv.push_back(N);

    int sz = pdiv.size();
    ll resA = 0, resB = 0;
    for (int msk = 1; msk < (1 << sz); ++msk)
    {
        ll tmul = 1;
        for (int it = 0; it < sz; ++it)
            if ((msk >> it) & 1)
                tmul *= pdiv[it];

        int bitcnt = __builtin_popcount(msk);
        if (bitcnt % 2)
        {
            resA += 1LL * A / tmul;
            resB += 1LL * B / tmul;
        }
        else
        {
            resA -= 1LL * A / tmul;
            resB -= 1LL * B / tmul;
        }
    }

    cout << "Case #" << id << ": " << (B - A) - (resB - resA) << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        not_main(i);
    return 0;
}