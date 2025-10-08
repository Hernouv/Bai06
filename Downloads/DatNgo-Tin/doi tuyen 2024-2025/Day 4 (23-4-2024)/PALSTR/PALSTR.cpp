#include <bits/stdc++.h>
using namespace std;

bool dp[5005][5005];
char str[5005];
int N, T;

void not_main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> str[i];

    for (int i = 1; i <= N; ++i)
        dp[i][i] = true;
    for (int i = 1; i < N; ++i)
        if (str[i] == str[i + 1])
            dp[i][i + 1] = true;

    for (int i = 2; i < N; ++i)
    {
        int l = i - 1, r = i + 1;
        while (l >= 1 and r <= N)
        {
            if (str[l] == str[r] and dp[l + 1][r - 1])
            {
                dp[l][r] = true;
                --l, ++r;
            }
            else
                break;
        }
    }

    for (int i = 2; i < N - 1; ++i)
    {
        int l = i - 1, r = i + 2;
        while (l >= 1 and r <= N)
        {
            if (str[l] == str[r] and dp[l + 1][r - 1])
            {
                dp[l][r] = true;
                --l, ++r;
            }
            else
                break;
        }
    }

    int rq_l, rq_r;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        cin >> rq_l >> rq_r;
        cout << (dp[rq_l][rq_r] ? "YES" : "NO") << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PALSTR.INP", "r"))
    {
        freopen("PALSTR.INP", "r", stdin);
        freopen("PALSTR.OUT", "w", stdout);
    }
    not_main();
    return 0;
}