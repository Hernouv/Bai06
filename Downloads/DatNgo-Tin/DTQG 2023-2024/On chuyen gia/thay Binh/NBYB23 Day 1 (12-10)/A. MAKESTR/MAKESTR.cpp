#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;
bool grid[310][310];
bool directly_visitable[310][310];
bool avail_sol = true;
int dp[310][310];
vector<int> reachable[310];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen;
    cin >> n >> m;
    cin >> s;
    cin >> t;

    string inv_s = s;
    reverse(inv_s.begin(), inv_s.end());

    if (s == t or inv_s == t)
        cout << t.size() - 1;
    else
    {
        s = ' ' + s;
        t = ' ' + t;

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                if (t[i] == s[j])
                {
                    grid[i][j] = true;
                    reachable[i].push_back(j);
                }

        if (t.size() == 1 and !reachable[1].empty())
            cout << 0;
        else
        {
            for (int i = 0; i <= m + 1; ++i)
                for (int j = 0; j <= n + 1; ++j)
                    dp[i][j] = 1e9;
            for (auto x : reachable[1])
                dp[1][x] = 0;

            for (int i = 1; i < m; ++i)
            {
                // cout << i << '\n';
                int next = 0;
                for (auto x : reachable[i])
                {
                    if (dp[i][x] != 1e9)
                    {
                        if (x != 1)
                            if (grid[i + 1][x - 1])
                            {
                                next++;
                                directly_visitable[i + 1][x - 1] = true;
                                dp[i + 1][x - 1] = min(dp[i + 1][x - 1], dp[i][x] + 1);
                                for (auto y : reachable[i + 1])
                                    dp[i + 1][y] = min(dp[i + 1][y], dp[i + 1][x - 1] + abs(x - 1 - y));
                            }

                        if (x != n)
                            if (grid[i + 1][x + 1])
                            {
                                next++;
                                directly_visitable[i + 1][x + 1] = true;
                                dp[i + 1][x + 1] = min(dp[i + 1][x + 1], dp[i][x] + 1);
                                for (auto y : reachable[i + 1])
                                    dp[i + 1][y] = min(dp[i + 1][y], dp[i + 1][x + 1] + abs(x + 1 - y));
                            }
                    }
                }

                if (next == 0)
                {
                    avail_sol = false;
                    break;
                }
            }

            if (!avail_sol)
                cout << -1;
            else
            {
                int res = 1e9;
                for (auto x : reachable[m])
                    res = min(res, dp[m][x]);
                if (res == 1e9)
                    cout << -1;
                else
                    cout << res;
            }
        }
    }
    return 0;
}