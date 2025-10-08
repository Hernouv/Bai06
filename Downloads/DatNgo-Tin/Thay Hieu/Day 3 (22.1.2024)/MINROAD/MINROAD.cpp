#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

const int nmax = 3e5 + 10;

struct TungTruc
{
    int dist;
    int type;
    bool operator<(const TungTruc &x) const { return dist < x.dist; }
} trees[nmax];

int n, a, b, res = 2e9;

void not_main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> trees[i].dist >> trees[i].type;
    sort(trees + 1, trees + n + 1);
    int l = 1, r = 1, cnt[3] = {0, 0, 0};
    while (r <= n)
    {
        if (r == n + 1)
            break;
        while (cnt[1] < a or cnt[2] < b)
        {
            if (r == n + 1)
            {
                break;
            }
            ++cnt[trees[r].type];
            ++r;
        }
        --r;
        if (r == n + 1 and (cnt[1] < a or cnt[2] < b))
            break;
        while (cnt[1] >= a and cnt[2] >= b)
        {
            --cnt[trees[l].type];
            ++l;
        }
        --l;
        ++cnt[trees[l].type];
        minimize(res, trees[r].dist - trees[l].dist);
        --cnt[trees[l].type];
        ++l, ++r;
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("MINROAD.INP", "r"))
    {
        freopen("MINROAD.INP", "r", stdin);
        freopen("MINROAD.OUT", "w", stdout);
    }
    not_main();
    return 0;
}