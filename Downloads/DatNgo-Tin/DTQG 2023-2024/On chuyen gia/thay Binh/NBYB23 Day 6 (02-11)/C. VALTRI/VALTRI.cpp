#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>

int n;
ii A[510];
int bot[510];
int d[510][510];
int ans[510];

bool ccw(ii p, ii q, ii r)
{
    ii u = {p.first - q.first, p.second - q.second},
       v = {q.first - r.first, q.second - r.second};

    return ((u.first * v.second - u.second * v.first) > 0);
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i].first >> A[i].second;

    sort(A + 1, A + n + 1);
    memset(d, 0, sizeof d);
    memset(bot, 0, sizeof bot);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (A[i].first == A[j].first and A[i].second > A[j].second)
                bot[i]++;
        for (int j = i + 1; j <= n; j++)
        {
            if (A[i].first >= A[j].first)
                continue;
            d[i][j] = 0;
            for (int k = 1; k <= n; k++)
                if (i != k and j != k and A[i].first <= A[k].first and A[k].first <= A[j].first)
                {
                    if (ccw(A[j], A[i], A[k]))
                        d[i][j]++;
                }

            d[j][i] = d[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (A[i].first >= A[j].first)
                continue;
            for (int k = 1; k <= n; k++)
            {
                if (k == i or k == j)
                    continue;
                if (ccw(A[j], A[i], A[k]) && (A[i].first <= A[k].first && A[k].first <= A[j].first))
                    ans[d[i][j] - d[i][k] - d[k][j] + bot[k] - 1]++;
                if (!ccw(A[j], A[i], A[k]) && (A[i].first < A[k].first && A[k].first < A[j].first))
                    ans[d[i][k] + d[k][j] - d[i][j] - bot[k]]++;
            }
        }
    }

    for (int i = 0; i <= n - 3; i++)
        cout << ans[i] << '\n';

    return 0;
}
