#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e6 + 10;

int n;
int dp[nmax];

int proc(int inp)
{
    int t1 = inp;
    int max_digit = 0;
    while (t1)
    {
        maximize(max_digit, t1 % 10);
        t1 /= 10;
    }
    return inp - max_digit;
}

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        dp[i] = proc(i);

    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = dp[n];
    }

    cout << cnt;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}