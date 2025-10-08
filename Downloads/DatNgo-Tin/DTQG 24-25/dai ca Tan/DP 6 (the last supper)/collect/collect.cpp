#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> m(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> m[i];
    vector<ll> d(n, 0);
    for (int i = 1; i < n; i++)
        cin >> d[i];
    vector<ll> g(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> g[i];

    vector<ll> S_m(n + 1, 0);
    for (int i = 1; i <= n; i++)
        S_m[i] = S_m[i - 1] + m[i];
    vector<ll> S_d(n + 1, 0);
    for (int i = 1; i < n; i++)
        S_d[i + 1] = S_d[i] + d[i];

    int Q;
    cin >> Q;
    while (Q--)
    {
        ll W;
        cin >> W;
        vector<ll> DP(n + 1, 0);
        DP[0] = 0;
        deque<int> dq;
        vector<int> l_i(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            ll target = S_m[i] - W;
            if (target < 0)
                target = 0;
            int j = lower_bound(S_m.begin(), S_m.begin() + i, target) - S_m.begin();
            l_i[i] = j;
        }
        dq.clear();
        for (int i = 1; i <= n; i++)
        {
            while (!dq.empty() and dq.front() < l_i[i])
            {
                dq.pop_front();
            }
            if (i - 1 >= 0)
            {
                ll val = DP[i - 1] + g[i] - S_d[i];
                while (!dq.empty())
                {
                    int last = dq.back();
                    ll last_val = DP[last] + g[last + 1] - S_d[last + 1];
                    if (val <= last_val)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
                dq.push_back(i - 1);
            }
            if (!dq.empty())
            {
                int best_j = dq.front();
                DP[i] = g[i] + S_d[i] + (DP[best_j] + g[best_j + 1] - S_d[best_j + 1]);
            }
            else
            {
                DP[i] = LLONG_MAX;
            }
        }
        cout << DP[n] << "\n";
    }
}
