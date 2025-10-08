#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

int n, k;
vector<int> h, d;
int ans = (int)2e9;

void sub1()
{
    int n1 = n - 1;
    for (int i = (1 << k) - 1; i < (1 << n1); ++i)
    {
        if (__builtin_popcount(i) != k)
            continue;
        vector<int> pos;
        bool nxt = true;
        for (int it = 0; it < n1; ++it)
            if ((i >> it) & 1)
            {
                if (!pos.empty() and pos.back() == it)
                {
                    nxt = false;
                    break;
                }
                pos.push_back(it + 1);
            }
        if (!nxt)
            continue;
        int tmp = 0;
        for (int x : pos)
            tmp += d[x];
        minimize(ans, tmp);
    }
    cout << ans;
    return;
}

vector<vector<int>> dp;

void sub2()
{
    dp.resize(n + 5, vector<int>(k + 5, 2e9));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for (int i = 2; i <= n; ++i)
        for (int cnt = 1; cnt <= min(n / 2, k); ++cnt)
        {
            minimize(dp[i][cnt], dp[i - 2][cnt - 1] + d[i]);
            minimize(dp[i][cnt], dp[i - 1][cnt]);
        }

    cout << dp[n][k];
    return;
}

void not_main()
{
    cin >> n >> k;
    h.resize(n + 5);
    d.resize(n + 5);

    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    sort(h.begin() + 1, h.begin() + n + 1);

    if (k == 1)
    {
        for (int i = 2; i <= n; ++i)
            minimize(ans, h[i] - h[i - 1]);
        cout << ans;
        return;
    }

    if (2 * k == n)
    {
        ans = 0;
        for (int i = 2; i <= n; i += 2)
            ans += (h[i] - h[i - 1]);
        cout << ans;
        return;
    }

    if (2 * k == n - 1)
    {
        ans = 0;
        int p = 2;
        for (int i = 2; i <= n; ++i)
            if (maximize(ans, h[i] - h[i - 1]))
                p = i;
        ans = 0;
        for (int i = 2; i <= n;)
        {
            if (i != p)
            {
                ans += (h[i] - h[i - 1]);
                i += 2;
            }
            else
                i++;
        }
        cout << ans;
        return;
    }

    for (int i = 1; i < n; ++i)
        d[i] = h[i + 1] - h[i];

    if (n <= 20)
    {
        sub1();
        return;
    }

    // if (n <= 2000)
    {
        d.insert(d.begin(), 0);
        sub2();
        return;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DAN.INP", "r"))
    {
        freopen("DAN.INP", "r", stdin);
        freopen("DAN.OUT", "w", stdout);
    }
    not_main();
    return 0;
}