#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX / 4;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen("road.inp", "r"))
    {
        freopen("road.inp", "r", stdin);
        freopen("road.out", "w", stdout);
    }

    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<vector<long long>> A(N + 1, vector<long long>(M + 1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }

    auto computeDP = [&](const vector<vector<long long>> &A_mat)
    {
        vector<long long> distRow(M + 1, 0LL);
        vector<long long> distNext(M + 1, 0LL);

        for (int j = 1; j <= M; j++)
        {
            distRow[j] = 0LL;
        }

        for (int i = 1; i <= N; i++)
        {
            long long best = INF;
            for (int c = 1; c <= M; c++)
            {
                best = min(best, distRow[c] - K * c);
                distNext[c] = best + K * c;
            }
            best = INF;
            for (int c = M; c >= 1; c--)
            {
                best = min(best, distRow[c] + K * c);
                distNext[c] = min(distNext[c], best - K * c);
            }
            for (int c = 1; c <= M; c++)
            {
                if (distNext[c] >= INF || A_mat[i][c] >= INF)
                {
                    distNext[c] = INF;
                }
                else
                {
                    distNext[c] += A_mat[i][c];
                }
            }
            distRow = distNext;
        }

        long long ans = *min_element(distRow.begin() + 1, distRow.end());
        return ans;
    };

    long long baseCost = computeDP(A);

    int Q;
    cin >> Q;

    cout << baseCost << "\n";

    for (int _q = 0; _q < Q; _q++)
    {
        int x, y;
        cin >> x >> y;

        long long oldVal = A[x][y];
        A[x][y] = INF;

        long long costWithBlock = computeDP(A);
        cout << costWithBlock << "\n";

        A[x][y] = oldVal;
    }

    return 0;
}
