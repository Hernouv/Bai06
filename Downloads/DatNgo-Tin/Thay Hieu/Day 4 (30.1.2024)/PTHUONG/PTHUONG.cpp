#include <bits/stdc++.h>
using namespace std;

const int nmax = 25010;
int a[nmax];
int dp[nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; ++i)
        dp[i] = max({dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]});

    cout << dp[n] << '\n';

    int track_id = n;
    stack<int> chosen;
    while (track_id > 0)
    {
        if (dp[track_id] == dp[track_id - 1])
            --track_id;
        else if (dp[track_id] == dp[track_id - 2] + a[track_id])
        {
            chosen.push(track_id);
            track_id -= 2;
        }
        else if (dp[track_id] == dp[track_id - 3] + a[track_id - 1] + a[track_id])
        {
            chosen.push(track_id);
            chosen.push(track_id - 1);
            track_id -= 3;
        }
    }

    int cnt_perLine = 0;
    while (!chosen.empty())
    {
        cout << chosen.top() << ' ';
        chosen.pop();
        ++cnt_perLine;
        if (cnt_perLine == 10)
        {
            cout << '\n';
            cnt_perLine = 0;
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PTHUONG.INP", "r"))
    {
        freopen("PTHUONG.INP", "r", stdin);
        freopen("PTHUONG.OUT", "w", stdout);
    }
    not_main();
    return 0;
}