#include <bits/stdc++.h>
using namespace std;

pair<int, int> tree[300001];
int cnttype[3];

inline bool byFirst(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first < b.first);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("ROAD.INP", "r", stdin);
    freopen("ROAD.OUT", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> tree[i].first >> tree[i].second;
    sort(tree + 1, tree + n + 1, byFirst);
    int start = 1, finish = 0, dist_res = 1e9 + 10;
    cnttype[1] = cnttype[2] = 0;
    bool outofbound = false;
    while (finish <= n)
    {
        while (cnttype[1] < a or cnttype[2] < b)
        {
            if (finish == n + 1)
            {
                outofbound = true;
                break;
            }
            finish++;
            cnttype[tree[finish].second]++;
        }
        if (outofbound)
            break;
        while (cnttype[1] >= a and cnttype[2] >= b)
        {
            cnttype[tree[start].second]--;
            start++;
        }
        dist_res = min(dist_res, tree[finish].first - tree[start - 1].first);
    }
    cout << dist_res;
    return 0;
}