#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n, k, q;
ii actlist[100010];
ii actlist_compressed[100010];
ii seq[100010];

inline bool bySecond(const ii &a, const ii &b)
{
    return (a.second < b.second);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    // if (fopen("ROTGAME.INP", "r"))
    // {
    //     freopen("ROTGAME.INP", "r", stdin);
    //     freopen("ROTGAME.OUT", "w", stdout);
    // }

    cin >> n >> k >> q;
    int partition = n / k;
    for (int i = 1; i <= q; ++i)
        cin >> actlist[i].first >> actlist[i].second;

    int top_pos = 1;
    actlist_compressed[1] = {1, 0};
    for (int i = 1; i <= q; ++i)
    {
        if (actlist[i].first == actlist_compressed[top_pos].first)
            actlist_compressed[top_pos].second += actlist[i].second;
        else
            actlist_compressed[++top_pos] = actlist[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> seq[i].first;
        seq[i].second = i;
    }

    for (int i = 1; i <= top_pos; ++i)
        cout << actlist_compressed[i].first << ' ' << actlist_compressed[i].second << '\n';

    cout << '\n';
    for (int i = 1; i <= n; ++i)
        cout << seq[i].first << ' ' << seq[i].second << '\n';
    // for (int i = 1; i <= top_pos; ++i)
    // {
    //     if (actlist_compressed[i].first == 1)
    //     {
    //         for (int j = 1; j <= n; ++j)
    //             seq[j].second = (seq[j].second + actlist_compressed[i].second) % n + 1;
    //         sort(seq + 1, seq + n + 1, bySecond);
    //     }
    //     else
    //     {
    //         for (int j = 0; j < partition; ++j)
    //         {
    //             for (int t = j * k + 1; t <= j * (k + 1); ++t)
    //             {
    //                 int move_t = actlist_compressed[i].second % k;
    //                 seq[t].second += move_t;
    //                 if (seq[t].second > j * (k + 1))
    //                     seq[t].second -= k;
    //             }
    //             sort(seq + j * k + 2, seq + j * (k + 1) + 1, bySecond);
    //         }
    //     }
    // }

    // for (int i = 1; i <= n; ++i)
    //     cout << seq[i].first << ' ';
    return 0;
}