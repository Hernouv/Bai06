#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, int> mp, cntleft;
bool red[1000010];
set<int> second;
pair<int, int> query[1000010];

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        mp[i] = 1;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        query[i] = {x, y};
        cntleft[x]++;
    }
    red[1] = true;
    if (cntleft[1] == 0)
        second.insert(1);
    for (int i = 1; i <= m; ++i)
    {
        int x = query[i].first, y = query[i].second;
        cntleft[x]--;
        if (mp[x] >= 1)
        {
            mp[x]--;
            mp[y]++;
            if (red[x])
            {
                red[y] = true;
            }
            if (mp[x] == 0)
                red[x] = false;
            if (red[y])
                if (cntleft[y] < mp[y])
                    second.insert(y);
        }
    }
    cout << second.size();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}