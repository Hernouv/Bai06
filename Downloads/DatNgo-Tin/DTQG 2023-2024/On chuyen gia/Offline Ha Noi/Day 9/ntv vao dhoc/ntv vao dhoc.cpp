#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int, int>

#define sz(s) (int)s.size()
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

const int mx = 1e6 + 7;
int n, k, c[mx];
ll skill[mx], ans;
bool hoc[mx];
priority_queue<ii, vector<ii>, greater<ii>> lis[mx];
queue<int> WAIT;

void not_main()
{
    cin >> n >> k;
    ii a[n + 3][k + 3];
    memset(a, 0, sizeof a);
    For(i, 1, n)
    {
        bool check = 0;
        For(j, 1, k)
        {
            cin >> a[i][j].first;
            if (a[i][j].first)
                check = 1;
            lis[j].push({a[i][j].first, i});
        }
        if (!check)
        {
            WAIT.push(i);
            hoc[i] = 1;
        }
    }
    For(i, 1, n) For(j, 1, k) cin >> a[i][j].second;

    while (sz(WAIT))
    {
        int i = WAIT.front();
        For(j, 1, k) skill[j] += a[i][j].second;
        For(j, 1, k)
        {
            while (sz(lis[j]) and skill[j] >= lis[j].top().first)
            {
                int id = lis[j].top().second;
                c[id]++;
                if (c[id] == k and !hoc[id])
                {
                    WAIT.push(id);
                    hoc[id] = 1;
                }
                lis[j].pop();
            }
        }
        ans++;
        WAIT.pop();
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}