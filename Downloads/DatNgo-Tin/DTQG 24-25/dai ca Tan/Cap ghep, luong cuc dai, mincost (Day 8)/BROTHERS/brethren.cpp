#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }
    A[1][1] = 0;
    A[N][M] = 0;

    vector<vector<int>> prev(N + 1, vector<int>(N + 1, -INF));
    vector<vector<int>> curr(N + 1, vector<int>(N + 1, -INF));

    prev[1][1] = A[1][1];

    int k_final = N + M - 2;

    for (int k = 1; k <= k_final; k++)
    {
        for (int r1 = 1; r1 <= N; r1++)
        {
            for (int r2 = 1; r2 <= N; r2++)
            {
                curr[r1][r2] = -INF;
            }
        }
        int r1_min = max(1, k + 2 - M);
        int r1_max = min(N, k + 1);
        int r2_min = r1_min;
        int r2_max = r1_max;
        for (int r1 = r1_min; r1 <= r1_max; r1++)
        {
            int c1 = k + 2 - r1;
            if (c1 < 1 or c1 > M)
                continue;
            for (int r2 = r2_min; r2 <= r2_max; r2++)
            {
                int c2 = k + 2 - r2;
                if (c2 < 1 or c2 > M)
                    continue;
                if (r1 == r2 and c1 == c2 and k != 0 and k != k_final)
                {
                    continue;
                }
                int max_prev = -INF;
                if (r1 > 1 and r2 > 1)
                {
                    if (prev[r1 - 1][r2 - 1] != -INF)
                    {
                        max_prev = max(max_prev, prev[r1 - 1][r2 - 1]);
                    }
                }
                if (r1 > 1 and c2 > 1)
                {
                    if (prev[r1 - 1][r2] != -INF)
                    {
                        max_prev = max(max_prev, prev[r1 - 1][r2]);
                    }
                }
                if (c1 > 1 and r2 > 1)
                {
                    if (prev[r1][r2 - 1] != -INF)
                    {
                        max_prev = max(max_prev, prev[r1][r2 - 1]);
                    }
                }
                if (c1 > 1 and c2 > 1)
                {
                    if (prev[r1][r2] != -INF)
                    {
                        max_prev = max(max_prev, prev[r1][r2]);
                    }
                }
                if (max_prev == -INF)
                {
                    continue;
                }
                int temp_sum = 0;
                if (r1 == r2 and c1 == c2)
                {
                    temp_sum = max_prev + A[r1][c1];
                }
                else
                {
                    temp_sum = max_prev + A[r1][c1] + A[r2][c2];
                }
                curr[r1][r2] = max(curr[r1][r2], temp_sum);
            }
        }
        prev.swap(curr);
    }

    cout << prev[N][N];
}
