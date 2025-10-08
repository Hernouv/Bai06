#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define whole(_name) _name.begin(), _name.end()

struct node
{
    char h;
    ll d;
    ll c;
    ll k;
    bool active;
};

struct Event
{
    ll t;
    ll p;
    int dir;
    Event(ll t, ll p, int dir) : t(t), p(p), dir(dir) {}
    bool operator<(const Event &other) const
    {
        return t < other.t;
    }
};

void not_main()
{
    int n, q;
    cin >> n >> q;
    vector<node> mirrorSets(n);
    for (int i = 0; i < n; ++i)
    {
        string h;
        ll d, c;
        cin >> h >> d >> c;
        mirrorSets[i] = {h[0], d, c, 1, true};
    }

    vector<ll> queryT(q);
    ll T_max = 0;
    for (int i = 0; i < q; ++i)
    {
        cin >> queryT[i];
        T_max = max(T_max, queryT[i]);
    }

    vector<Event> events;
    ll t0 = 0;
    ll p0 = 0;
    int dir = 1;

    while (true)
    {
        ll next_t = -1;
        ll next_p = 0;
        int next_dir = dir;
        int mirrorSetId = -1;

        for (int i = 0; i < n; ++i)
        {
            if (!mirrorSets[i].active)
                continue;
            if ((dir == 1 and mirrorSets[i].h != 'R') or (dir == -1 and mirrorSets[i].h != 'L'))
                continue;

            ll d = mirrorSets[i].d;
            ll c = mirrorSets[i].c;
            ll p = 0;
            if (dir == 1)
            {
                ll k = max((p0 + d - 1) / d, 1LL);
                if (k > c)
                    continue;
                p = k * d;
            }
            else
            {
                ll k = max(((-p0) + d - 1) / d, 1LL);
                if (k > c)
                    continue;
                p = -k * d;
            }
            ll t = t0 + abs(p - p0);
            if (next_t == -1 or t < next_t or (t == next_t and p * dir < next_p * dir))
            {
                next_t = t;
                next_p = p;
                mirrorSetId = i;
            }
        }

        if (next_t == -1 or next_t > T_max)
        {
            break;
        }

        events.emplace_back(next_t, next_p, -dir);
        t0 = next_t;
        p0 = next_p;
        dir = -dir;

        node &ms = mirrorSets[mirrorSetId];
        if (dir == -1 and ms.h == 'R')
        {
            ll k = (p0) / ms.d;
            ms.k = k + 1;
            if (ms.k > ms.c)
                ms.active = false;
        }
        else if (dir == 1 and ms.h == 'L')
        {
            ll k = (-p0) / ms.d;
            ms.k = k + 1;
            if (ms.k > ms.c)
                ms.active = false;
        }
        else
        {
            ms.k++;
            if (ms.k > ms.c)
                ms.active = false;
        }
    }

    sort(whole(events), [](const Event &a, const Event &b)
         { return a.t < b.t; });

    vector<ll> ans(q);

    for (int i = 0; i < q; ++i)
    {
        ll T = queryT[i];
        int l = 0, r = events.size() - 1;
        int idx = -1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (events[m].t <= T)
            {
                idx = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        ll pos;
        int curr_dir;
        ll t0_local;
        ll p0_local;
        if (idx == -1)
        {
            pos = 0 + T;
        }
        else
        {
            Event &e = events[idx];
            t0_local = e.t;
            p0_local = e.p;
            curr_dir = e.dir;
            pos = p0_local + curr_dir * (T - t0_local);
        }
        ans[i] = pos;
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("mirror.inp", "r"))
    {
        freopen("mirror.inp", "r", stdin);
        freopen("mirror.out", "w", stdout);
    }
    not_main();
    return 0;
}
