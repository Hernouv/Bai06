#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, K;
    cin >> m >> n >> K;
    vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> h(m + 1, vector<int>(n + 1, 0)), v(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == 1 && grid[i][j + 1] == 1)
                h[i][j] = 1;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i][j] == 1 && grid[i + 1][j] == 1)
                v[i][j] = 1;
        }
    }

    vector<vector<int>> H(m + 1, vector<int>(n + 1, 0)), V(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            H[i][j] = H[i - 1][j] + H[i][j - 1] - H[i - 1][j - 1] + (j < n ? h[i][j] : 0);
            V[i][j] = V[i - 1][j] + V[i][j - 1] - V[i - 1][j - 1] + (i < m ? v[i][j] : 0);
        }
    }

    auto sumH = [&](int r1, int c1, int r2, int c2)
    {
        if (r1 > r2 || c1 > c2)
            return 0;
        return H[r2][c2] - H[r1 - 1][c2] - H[r2][c1 - 1] + H[r1 - 1][c1 - 1];
    };

    auto sumV = [&](int r1, int c1, int r2, int c2)
    {
        if (r1 > r2 || c1 > c2)
            return 0;
        return V[r2][c2] - V[r1 - 1][c2] - V[r2][c1 - 1] + V[r1 - 1][c1 - 1];
    };

    auto check = [&](int d) -> tuple<bool, int, int>
    {
        if (d == 0)
        {
            for (int i = 1 + d; i <= m - d; i++)
            {
                for (int j = 1 + d; j <= n - d; j++)
                {
                    if (0 <= K)
                        return {true, i, j};
                }
            }
            return {false, -1, -1};
        }

        for (int i = 1 + d; i <= m - d; i++)
        {

            for (int j = 1 + d; j <= n - d; j++)
            {
                int total_edges = 0;
                for (int o = -d; o <= d; o++)
                {
                    int r = i + o;
                    int len = d - abs(o);
                    int c1 = j - len;
                    int c2 = j + len;
                    if (c1 < c2)
                    {
                        total_edges += sumH(r, c1, r, c2 - 1);
                        if (total_edges > K)
                            goto cont_check;
                    }
                }

                for (int o = -d; o < d; o++)
                {
                    int r = i + o;
                    int len1 = d - abs(o);
                    int c1_1 = j - len1;
                    int c2_1 = j + len1;

                    int o2 = o + 1;
                    int len2 = d - abs(o2);
                    int c1_2 = j - len2;
                    int c2_2 = j + len2;

                    int cc1 = max(c1_1, c1_2);
                    int cc2 = min(c2_1, c2_2);

                    if (cc1 <= cc2)
                    {
                        total_edges += sumV(r, cc1, r, cc2);
                        if (total_edges > K)
                            goto cont_check;
                    }
                }

                if (total_edges <= K)
                {
                    return {true, i, j};
                }

            cont_check:;
            }
        }
        return {false, -1, -1};
    };

    int low = 0, high = min(m, n), ans_d = 0, ans_i = 1, ans_j = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        auto [ok, ci, cj] = check(mid);
        if (ok)
        {
            ans_d = mid;
            ans_i = ci;
            ans_j = cj;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans_d << "\n"
         << ans_i << " " << ans_j << "\n";

    return 0;
}
