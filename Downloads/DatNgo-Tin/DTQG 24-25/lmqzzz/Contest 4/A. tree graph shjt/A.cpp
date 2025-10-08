#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;
#define whole(__) __.begin(), __.end()
const int nmax = 1e5 + 10;

int N;
vector<int> child[nmax];
ll W[nmax];
int D[nmax];
ll dp_min[nmax][2];
ll dp_max[nmax][2];

void dfs(int node)
{
    if (child[node].empty())
    {
        dp_min[node][0] = -W[node];
        dp_max[node][0] = -W[node];
        dp_min[node][1] = W[node];
        dp_max[node][1] = W[node];
        return;
    }
    for (int ch : child[node])
        dfs(ch);
    for (int c = 0; c < 2; c++)
    {
        ll y = (c == 1) ? 1 : -1;
        ll base_min = y * W[node];
        ll base_max = y * W[node];
        ll sum_dp_min = 0;
        ll sum_dp_max = 0;
        vector<ll> diffs_min;
        vector<ll> diffs_max;
        for (int ch : child[node])
        {
            sum_dp_min += dp_min[ch][c];
            sum_dp_max += dp_max[ch][c];
            diffs_min.push_back(dp_min[ch][1 - c] - dp_min[ch][c]);
            diffs_max.push_back(dp_max[ch][1 - c] - dp_max[ch][c]);
        }
        base_min += sum_dp_min;
        base_max += sum_dp_max;
        int di = D[node];
        vector<ll> sorted_diffs_min = diffs_min;
        sort(whole(sorted_diffs_min));
        ll sum_diffs_min = 0;
        for (int i = 0; i < di; i++)
            sum_diffs_min += sorted_diffs_min[i];
        ll total_min = base_min + sum_diffs_min;
        dp_min[node][c] = total_min;
        vector<ll> sorted_diffs_max = diffs_max;
        sort(whole(sorted_diffs_max), greater<ll>());
        ll sum_diffs_max = 0;
        for (int i = 0; i < di; i++)
            sum_diffs_max += sorted_diffs_max[i];
        ll total_max = base_max + sum_diffs_max;
        dp_max[node][c] = total_max;
    }
}

void not_main()
{
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        int p;
        cin >> p;
        child[p].push_back(i);
    }
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    for (int i = 1; i <= N; i++)
        cin >> D[i];
    dfs(1);
    ll ans = 0;
    maximize(ans, abs(dp_min[1][0]));
    maximize(ans, abs(dp_max[1][0]));
    maximize(ans, abs(dp_min[1][1]));
    maximize(ans, abs(dp_max[1][1]));
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
