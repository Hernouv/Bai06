#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define fi first
#define se second

const int MAXR = 2e3 + 5;
const int MAXS = 2e3 + 5;
const int INF = 1e6 + 5;
const int DX[] = {0, 0, -1, 1};
const int DY[] = {-1, 1, 0, 0};
const char DISCOUNT[] = "<>^v";
const char OPPOSITE[] = "><v^";

int r, s;
vector<string> mat(MAXR);
vector<vector<int>> dist(MAXR, vector<int>(MAXS, INF));
vector<vector<bool>> visited(MAXR, vector<bool>(MAXS, false));

bool valid(ii p)
{
    return 0 <= p.fi and p.fi < r and 0 <= p.se and p.se < s;
}

void ins_proc(ii start)
{
    deque<ii> to_visit;
    for (int i = 0; i < r; i++)
    {
        fill(dist[i].begin(), dist[i].begin() + s, INF);
    }

    dist[start.fi][start.se] = 0;
    to_visit.push_back(start);
    while (!to_visit.empty())
    {
        ii curr = to_visit.front();
        to_visit.pop_front();
        if (mat[curr.fi][curr.se] == 'x')
            continue;
        for (int i = 0; i < 4; i++)
        {
            ii nxt(curr.fi + DX[i], curr.se + DY[i]);
            if (valid(nxt))
            {
                int cost = 1;
                if (mat[curr.fi][curr.se] == 'o')
                    cost = 0;
                if (DISCOUNT[i] == mat[curr.fi][curr.se])
                    cost = 0;
                if (dist[nxt.fi][nxt.se] > dist[curr.fi][curr.se] + cost)
                {
                    dist[nxt.fi][nxt.se] = dist[curr.fi][curr.se] + cost;
                    if (cost == 1)
                        to_visit.push_back(nxt);
                    else
                        to_visit.push_front(nxt);
                }
            }
        }
    }
}

bool dfs(ii pos)
{
    visited[pos.fi][pos.se] = true;
    for (int i = 0; i < 4; i++)
    {
        ii nxt(pos.fi + DX[i], pos.se + DY[i]);
        if (valid(nxt) and !visited[nxt.fi][nxt.se])
        {
            if (mat[nxt.fi][nxt.se] == 'o')
                return true;
            int cost = 1;
            if (mat[nxt.fi][nxt.se] == OPPOSITE[i])
                cost = 0;
            if (dist[pos.fi][pos.se] == dist[nxt.fi][nxt.se] + cost)
            {
                if (dfs(nxt))
                {
                    mat[nxt.fi][nxt.se] = OPPOSITE[i];
                    return true;
                }
            }
        }
    }
    return false;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> r >> s;
    for (int i = 0; i < r; i++)
        cin >> mat[i];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
            if (mat[i][j] == 'o')
            {
                ins_proc(ii(i, j));
            }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < s; j++)
            if (mat[i][j] == 'x')
            {
                cout << dist[i][j] << '\n';
                dfs(ii(i, j));
            }

    for (int i = 0; i < r; i++)
        cout << mat[i] << '\n';

    return 0;
}
