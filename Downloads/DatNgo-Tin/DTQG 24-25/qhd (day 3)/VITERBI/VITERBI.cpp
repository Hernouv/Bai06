#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 210;
const int outbound = 2e9;

int n, m, t;
int machine_id[nmax];
int switch_time[nmax][nmax];
int craft_time[nmax][nmax];
int parent_tool[nmax][nmax];
int dp[nmax][nmax];

void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                minimize(switch_time[i][j], switch_time[i][k] + switch_time[k][j]);
}

void not_main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= t; ++i)
        cin >> machine_id[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> switch_time[i][j];
    floyd();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> craft_time[i][j];

    for (int i = 1; i <= n; ++i)
        dp[i][1] = craft_time[i][1];

    for (int i = 2; i <= t; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int tmp = outbound;
            for (int k = 1; k <= n; ++k)
                if (minimize(tmp, dp[k][i - 1] + switch_time[k][j]))
                    parent_tool[j][i] = k;
            dp[j][i] = tmp + craft_time[j][machine_id[i]];
        }

    int res = outbound, last_tool = 0;
    for (int i = 1; i <= n; ++i)
        if (minimize(res, dp[i][t]))
            last_tool = i;
    cout << res << '\n';
    int it = t;
    stack<int> st;
    while (last_tool)
    {
        st.push(last_tool);
        last_tool = parent_tool[last_tool][it];
        it -= 1;
    }
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("VITERBI.INP", "r"))
    {
        freopen("VITERBI.INP", "r", stdin);
        freopen("VITERBI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}