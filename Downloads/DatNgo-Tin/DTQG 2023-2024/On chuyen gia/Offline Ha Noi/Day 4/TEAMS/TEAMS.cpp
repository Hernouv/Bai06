#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n;
ii a[1000010];
vector<int> teamlist[1000010];
int minsize[1000010];

inline bool byFirst(const ii &a, const ii &b)
{
    return (a.first > b.first);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("TEAMS.INP", "r"))
    {
        freopen("TEAMS.INP", "r", stdin);
        freopen("TEAMS.OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, byFirst);

    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << a[i].first << ' ' << a[i].second << '\n';
    // }

    int teamNo = 1;
    minsize[1] = a[1].first;
    for (int i = 1; i <= n; ++i)
    {
        if (teamlist[teamNo].size() < minsize[teamNo])
            teamlist[teamNo].push_back(a[i].second);
        else
        {
            if (a[i].first <= n - i + 1)
            {
                ++teamNo;
                teamlist[teamNo].push_back(a[i].second);
                minsize[teamNo] = a[i].second;
            }
            else
            {
                teamlist[teamNo].push_back(a[i].second);
            }
        }
    }
    cout << teamNo << '\n';
    for (int i = 1; i <= teamNo; ++i)
    {
        cout << teamlist[i].size() << ' ';
        for (auto x : teamlist[i])
            cout << x << ' ';
        cout << '\n';
    }
    return 0;
}