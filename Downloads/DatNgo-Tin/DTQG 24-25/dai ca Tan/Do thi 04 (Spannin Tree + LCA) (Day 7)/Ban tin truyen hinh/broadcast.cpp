#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<string> strings(N);
    for (int i = 0; i < N; i++)
        cin >> strings[i];

    vector<vector<char>> chars(N, vector<char>(K));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            chars[i][j] = strings[i][j];

    vector<int> min_cost(N, K);
    vector<bool> visited_flag(N, false);
    long long total_cost = 0;

    for (int i = 0; i < N; i++)
    {
        int u = -1;
        int current_min = INT32_MAX;
        for (int j = 0; j < N; j++)
        {
            if (!visited_flag[j] and min_cost[j] < current_min)
            {
                current_min = min_cost[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        total_cost += current_min;
        visited_flag[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (!visited_flag[v])
            {
                int m = 0;
                for (int pos = 0; pos < K; pos++)
                {
                    if (chars[u][pos] != chars[v][pos])
                        m++;
                }
                int send_cost = 2 * m;
                if (send_cost < min_cost[v])
                    min_cost[v] = send_cost;
            }
        }
    }

    cout << total_cost;
}
