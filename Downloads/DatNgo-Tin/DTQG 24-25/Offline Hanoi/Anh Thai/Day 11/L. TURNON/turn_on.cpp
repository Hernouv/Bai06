#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2")
using namespace std;

const int nmax = 1e5 + 5;
int n, q, k, l[nmax], r[nmax], cnt[nmax], prexor[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    while (q--)
    {
        cin >> k;
        vector<int> sw(k);
        fill(cnt, cnt + n + 2, 0);
        for (int i = 0; i < k; ++i)
        {
            cin >> sw[i];
            cnt[sw[i]] ^= 1;
        }
        prexor[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            prexor[i] = prexor[i - 1] ^ cnt[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            int p = prexor[r[i]] ^ prexor[l[i] - 1];
            if (p == 1)
            {
                res++;
            }
        }
        cout << res << '\n';
    }
    return 0;
}