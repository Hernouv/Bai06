#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

const int outbound = 1e9 + 10;

int n;
string s;
int initial_state, state_all;
int cost[(1 << 22)];

priority_queue<ii, vector<ii>, greater<ii>> pq;
void xuly()
{
    pq.emplace(0, initial_state);
    while (!pq.empty())
    {
        ii S = pq.top();
        pq.pop();

        if (cost[S.se] < S.fi)
            continue;

        for (int it = 1; it < n; ++it)
        {
            int t1 = (1 << (it + 1)) - 1;
            int t2 = (1 << (it - 1)) - 1;
            int new_state = S.se ^ (t1 - t2);
            if (minimize(cost[new_state], S.fi + 1))
            {
                if (new_state != 0 and new_state != state_all)
                    pq.emplace(cost[new_state], new_state);
            }
        }
        for (int it = 2; it < n; ++it)
        {
            int t1 = (1 << (it + 1)) - 1;
            int t2 = (1 << (it - 2)) - 1;
            int new_state = S.se ^ (t1 - t2);
            if (minimize(cost[new_state], S.fi + 1))
            {
                if (new_state != 0 and new_state != state_all)
                    pq.emplace(cost[new_state], new_state);
            }
        }
    }
}

void not_main()
{
    cin >> n;
    state_all = (1 << n) - 1;
    cin >> s;
    if (n == 2)
    {
        cout << 0;
        exit(0);
    }
    reverse(whole(s));
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'B')
            initial_state += (1 << i);
    }
    if (!initial_state or initial_state == state_all)
    {
        cout << 0;
        exit(0);
    }

    for (int i = 0; i < (1 << n); ++i)
        cost[i] = outbound;
    cost[initial_state] = 0;
    xuly();

    cout << min(cost[0], cost[state_all]);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}