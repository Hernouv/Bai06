#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

const int nmax = 1e5 + 10;

ll deli[nmax];
ll accum[nmax];
ll res = 0;
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> deli[i];
    sort(deli + 1, deli + n + 1);
    int pos = lower_bound(deli + 1, deli + n + 1, 0) - deli;

    if (pos == n + 1)
    {
        cout << 0;
        return;
    }

    for (int i = n; i >= 1; --i)
        accum[i] = accum[i + 1] + deli[i];

    for (int i = pos; i <= n; ++i)
        res += 1LL * deli[i] * (i - pos + 1);
    for (int i = pos - 1; i >= 1; --i)
        if (accum[i] > 0)
            res += accum[i];
        else
            break;
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}