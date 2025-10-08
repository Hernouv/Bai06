#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct prop
{
    ll event_time;
    int st_en;
    int off_online;
};
vector<prop> timeline;

inline bool customSort(prop &a, prop b)
{
    if (a.event_time != b.event_time)
        return a.event_time < b.event_time;
    if (a.st_en != b.st_en)
        return a.st_en > b.st_en;
    return (a.off_online < b.off_online);
}

int n;
ll d, t, time_at_home = 0;

void not_main()
{
    cin >> n >> d >> t;
    ll L, R;
    bool class_type;
    for (int i = 1; i <= n; ++i)
    {
        cin >> L >> R >> class_type;
        timeline.push_back({L, 0, class_type});
        timeline.push_back({R, 1, class_type});
        if (class_type == 0)
        {
            timeline.push_back({L - t, 0, -1});
            timeline.push_back({R, 1, 2});
        }
    }
    sort(timeline.begin(), timeline.end(), customSort);
    timeline.push_back({d, 0, 0});

    int sz = timeline.size();
    for (int it = 0; it < sz; ++it)
    {
        if (timeline[it].off_online == -1)
        {
            if (it > 0 and timeline[it - 1].st_en == 0 and timeline[it - 1].off_online == 1)
                timeline[it - 1].off_online = 0;
            int it_2 = it + 1;
            while (timeline[it].off_online != 2 and it < sz)
            {
                if (timeline[it].off_online == 1)
                    timeline[it].off_online = 0;
                ++it;
            }
        }
    }

    ll last_class_end = 0;
    for (prop x : timeline)
    {
        if (x.st_en == 0 and x.off_online == 0)
        {
            ll tmp = x.event_time - last_class_end - t;
            if (tmp > 0)
                time_at_home += tmp;
            continue;
        }
        if (x.st_en == 1 and x.off_online == 0)
        {
            last_class_end = x.event_time + t;
            continue;
        }
    }

    cout << '\n';
    cout << time_at_home;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("null.inp", "r"))
    {
        freopen("null.inp", "r", stdin);
        freopen("null.out", "w", stdout);
    }
    not_main();
    return 0;
}