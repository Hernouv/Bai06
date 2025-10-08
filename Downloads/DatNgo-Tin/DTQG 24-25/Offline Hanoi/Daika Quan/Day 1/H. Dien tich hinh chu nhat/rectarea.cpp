#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 3e4 + 10;

int n, res;
struct Event
{
    int x, low, high, t;
    bool operator<(Event &a)
    {
        return (x < a.x) or ((x == a.x) and t < a.t);
    }
};

struct Node
{
    int cnt, cover;
} ST[16 * maxn];

void update(int id, int L, int R, int u, int v, int val)
{
    if (v <= L or R <= u)
        return;
    if (u <= L and R <= v)
    {
        ST[id].cnt += val;
        if (ST[id].cnt == 0)
            ST[id].cover = ST[2 * id].cover + ST[2 * id + 1].cover;
        else
            ST[id].cover = R - L;
        return;
    }
    int mid = (L + R) / 2;
    update(2 * id, L, mid, u, v, val);
    update(2 * id + 1, mid, R, u, v, val);
    if (ST[id].cnt == 0)
        ST[id].cover = ST[2 * id].cover + ST[2 * id + 1].cover;
}
vector<Event> E;

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        E.push_back({x1, y1, y2, 1});
        E.push_back({x2, y1, y2, -1});
    }
    E.push_back({0, 0, 0, -1});
    sort(E.begin(), E.end());
    for (int i = 1; i < E.size(); i++)
    {
        res = res + ST[1].cover * (E[i].x - E[i - 1].x);
        update(1, 0, maxn, E[i].low, E[i].high, E[i].t);
    }
    cout << res;
}