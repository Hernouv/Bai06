#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

const int N = 1e6 + 7;

struct dat
{
    int x, t, c;
    dat() = default;
    dat(int x, int t, int c) : x(x), t(t), c(c) {}
    friend istream &operator>>(istream &inp, dat &it)
    {
        inp >> it.x >> it.t >> it.c;
        return inp;
    }
} a[N];
int n, dist, p, w;
priority_queue<ii, vector<ii>, greater<ii>> q;

int cal(int mxtime)
{
    int lst = p;
    int cost = 0;
    for (; q.size(); q.pop())
        ;
    For(i, 1, n + 1)
    {
        while (q.size() and lst < a[i].x)
        {
            ii tmp = q.top();
            q.pop();
            int cnt = min(tmp.S, a[i].x - lst);
            if (tmp.S == -1)
                cnt = a[i].x - lst;
            lst += cnt;
            cost += cnt * tmp.F;
            if (tmp.S > cnt)
                q.push({tmp.F, tmp.S - cnt});
            if (tmp.S == -1)
                q.push(tmp);
        }

        if (lst < a[i].x)
            return LLONG_MAX;
        q.push({a[i].c, (a[i].t == 0 ? -1 : mxtime / a[i].t)});
    }
    return cost;
}

void not_main()
{
    cin >> n >> dist >> p >> w;
    For(i, 1, n) cin >> a[i];
    a[n + 1] = dat(dist, 1, (int)1e15);

    ii ans = {-1, -1};
    int l = 0, r = (int)1e15;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int costt = cal(mid);
        if (costt <= w)
        {
            ans = {mid, costt};
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans.F << ' ' << ans.S;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}