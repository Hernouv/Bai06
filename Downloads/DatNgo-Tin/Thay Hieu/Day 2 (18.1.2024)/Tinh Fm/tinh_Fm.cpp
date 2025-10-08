#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e6 + 10;

int n, m;
int a[nmax];
long long res = 0;

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        res += ll(upper_bound(a + 1, a + n + 1, m - a[i]) - a - 1);

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}