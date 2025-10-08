#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define Pii pair<int, int>
#define fi first
#define se second

const int mx = 1e6 + 6;
int n, used[mx];
Pii job[mx];
ll ans;

struct SMT
{
    int smt[4 * mx];

    void update(int u, int v, int val, int id = 1, int l = 1, int r = n)
    {
        if (v < l or u > r)
            return;
        if (l >= u and r <= v)
        {
            smt[id]++;
            return;
        }

        int mid = (l + r) >> 1;
        update(u, v, val, id << 1, l, mid);
        update(u, v, val, id << 1 | 1, mid + 1, r);
        smt[id] = smt[id << 1] + smt[id << 1 | 1];
    }

    int get(int u, int v, int id = 1, int l = 1, int r = n)
    {
        if (v < l or u > r)
            return 0;
        if (l >= u and r <= v)
            return smt[id];
        int mid = (l + r) >> 1;
        return get(u, v, id << 1, l, mid) + get(u, v, id << 1 | 1, mid + 1, r);
    }
} smt;

void Process()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> job[i].se >> job[i].fi;
    }

    sort(job + 1, job + 1 + n, greater<Pii>());

    for (int i = 1; i <= n; ++i)
    {
        if (smt.get(1, job[i].se) < job[i].se)
        {
            ans += job[i].fi;
            int l = 1, r = job[i].se, pos = -1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                int tmp = smt.get(mid, r);
                if (tmp < r - mid + 1 or !tmp)
                    pos = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            smt.update(pos, pos, 1);
        }
    }
    std::cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    Process();
    return 0;
}