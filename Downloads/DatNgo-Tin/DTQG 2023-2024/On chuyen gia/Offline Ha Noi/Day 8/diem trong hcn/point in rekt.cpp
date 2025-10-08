
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define ii pair<int, int>
#define pb push_back
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

const int N = 1e6 + 7;

struct event
{
    int x, low, high, t;

    event() = default;
    event(int x, int low, int high, int t) : x(x), low(low), high(high), t(t) {}
};

int n;
vector<event> ev;
struct IT
{
    int segTree[N << 2], lazy[N << 2];

    void push(int id, int l, int r)
    {
        if (l == r or lazy[id] == 0)
            return;
        int lChild = id * 2, rChild = id * 2 + 1;
        segTree[lChild] += lazy[id];
        segTree[rChild] += lazy[id];
        lazy[lChild] += lazy[id];
        lazy[rChild] += lazy[id];
        lazy[id] = 0;
    }

    void update(int u, int v, int val, int id = 1, int l = 0, int r = N - 1)
    {
        push(id, l, r);
        if (l > v or u > r)
            return;
        if (u <= l and r <= v)
        {
            segTree[id] += val;
            lazy[id] += val;
            push(id, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(u, v, val, id * 2, l, mid);
        update(u, v, val, id * 2 + 1, mid + 1, r);
        segTree[id] = max(segTree[id * 2], segTree[id * 2 + 1]);
    }

    int get(int u, int v, int id = 1, int l = 0, int r = N - 1)
    {
        push(id, l, r);
        if (l > v or u > r)
            return 0;
        if (u <= l and r <= v)
            return segTree[id];
        int mid = (l + r) >> 1;
        return max(get(u, v, id * 2, l, mid), get(u, v, id * 2 + 1, mid + 1, r));
    }
} segTree;

vector<pair<int, ii>> stt;

void not_main()
{
    cin >> n;
    For(i, 1, n + 1)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ev.pb(event(x1, y2, y1, 1));
        ev.pb(event(x2, y2, y1, -1));
    }
    sort(ev.begin(), ev.end(), [](event &A, event &B)
         { return (A.x == B.x ? A.t > B.t : A.x < B.x); });
    for (event e : ev)
    {
        segTree.update(e.low, e.high, e.t);
        if (segTree.get(e.low, e.high) >= n)
        {
            int y = 0, l = 0, r = e.high;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (segTree.get(0, mid) >= n)
                {
                    y = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            stt.pb({e.x * e.x + y * y, {e.x, y}});
        }
    }
    sort(stt.begin(), stt.end());
    if (stt.empty())
    {
        cout << -1;
        return;
    }
    cout << stt[0].second.first << ' ' << stt[0].second.second;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
