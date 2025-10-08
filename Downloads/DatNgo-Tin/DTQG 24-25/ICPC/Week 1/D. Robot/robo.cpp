#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second
#define whole(_name) _name.begin(), _name.end()

int n, m, k, q;
vector<ii> obs;
vector<ii> qry;
ii start;
vector<int> results;
set<ii> obs_ordered;

struct State
{
    int x, y, dir, changes;
};

int proc()
{
    vector<ii> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (ii x : obs)
        obs_ordered.insert(x);
    for (ii &target : qry)
    {
        int xt = target.fi, yt = target.se;

        if (obs_ordered.count(target) or xt < 1 or xt > n or yt < 1 or yt > m)
        {
            results.push_back(-1);
            continue;
        }

        int min_changes = INT_MAX;

        for (int ini_dir = 0; ini_dir < 4; ++ini_dir)
        {
            queue<State> q1;
            set<tuple<int, int, int>> visited;

            q1.push({start.fi, start.se, ini_dir, 0});
            visited.insert({start.fi, start.se, ini_dir});

            while (!q1.empty())
            {
                State curr = q1.front();
                q1.pop();

                if (curr.x == xt and curr.y == yt)
                {
                    min_changes = min(min_changes, curr.changes);
                    break;
                }

                int nx = curr.x + dirs[curr.dir].fi;
                int ny = curr.y + dirs[curr.dir].se;
                if (nx >= 1 and nx <= n and ny >= 1 and ny <= m and !obs_ordered.count({nx, ny}))
                {
                    if (!visited.count({nx, ny, curr.dir}))
                    {
                        visited.insert({nx, ny, curr.dir});
                        q1.push({nx, ny, curr.dir, curr.changes});
                    }
                }

                int L_dir = (curr.dir + 3) % 4;
                if (!visited.count({curr.x, curr.y, L_dir}))
                {
                    visited.insert({curr.x, curr.y, L_dir});
                    q1.push({curr.x, curr.y, L_dir, curr.changes + 1});
                }

                int R_dir = (curr.dir + 1) % 4;
                if (!visited.count({curr.x, curr.y, R_dir}))
                {
                    visited.insert({curr.x, curr.y, R_dir});
                    q1.push({curr.x, curr.y, R_dir, curr.changes + 1});
                }

                int opp_dir = (curr.dir + 2) % 4;
                if (!visited.count({curr.x, curr.y, opp_dir}))
                {
                    visited.insert({curr.x, curr.y, opp_dir});
                    q1.push({curr.x, curr.y, opp_dir, curr.changes + 1});
                }
            }
        }

        results.push_back(min_changes == INT_MAX ? -1 : min_changes);
    }

    for (int x : results)
        cout << x << '\n';

    return 0;
}

void not_main()
{
    cin >> n >> m >> k >> q;
    int tx, ty;
    for (int i = 1; i <= k; ++i)
    {
        cin >> tx >> ty;
        obs.push_back({tx, ty});
    }
    cin >> tx >> ty;
    start = {tx, ty};
    for (int i = 1; i <= q; ++i)
    {
        cin >> tx >> ty;
        qry.push_back({tx, ty});
    }
    proc();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}
