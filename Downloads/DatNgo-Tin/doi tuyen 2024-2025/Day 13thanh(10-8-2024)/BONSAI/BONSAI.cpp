#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 1e6 + 10;

int arr[nmax];
int accum_L[nmax], accum_R[nmax];
int min_R[nmax];
int n, k;
int res = 0;

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    accum_L[0] = 0;
    for (int i = 1; i <= n; ++i)
        accum_L[i] = accum_L[i - 1] + arr[i];

    accum_R[n + 1] = 0;
    for (int i = n; i >= 1; --i)
        accum_R[i] = accum_R[i + 1] + arr[i];

    for (int i = 1; i <= n; ++i)
        cout << accum_L[i] << ' ';
    cout << '\n';
    for (int i = 1; i <= n; ++i)
        cout << accum_R[i] << ' ';
    cout << '\n';

    min_R[n] = accum_R[n];
    for (int i = n - 1; i >= 1; --i)
        min_R[i] = min(min_R[i + 1], accum_R[i]);

    for (int i = 0; i + k <= n; ++i)
    {
        minimize(res, accum_L[i] + min_R[i + k + 1]);
    }

    cout << accum_L[n] - res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("BONSAI.INP", "r"))
    {
        freopen("BONSAI.INP", "r", stdin);
        freopen("BONSAI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}