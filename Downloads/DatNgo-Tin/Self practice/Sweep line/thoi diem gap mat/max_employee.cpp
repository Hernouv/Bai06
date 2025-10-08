#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define fi first
#define se second

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

vector<ii> timeline;
int n;

void not_main()
{
    cin >> n;
    int arrive, depart;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arrive >> depart;
        timeline.emplace_back(arrive, 0);
        timeline.emplace_back(depart, 1);
    }
    sort(timeline.begin(), timeline.end());

    int res = 0;
    int employee_cnt = 0;
    for (ii x : timeline)
    {
        if (x.se == 0)
            maximize(res, ++employee_cnt);
        else
            --employee_cnt;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}