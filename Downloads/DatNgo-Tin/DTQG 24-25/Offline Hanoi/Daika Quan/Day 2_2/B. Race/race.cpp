// IOI 2011 - Race
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 2e5 + 10;
const int MAXK = 1e6 + 10;

#define F first
#define S second

int N, K, global_answer;
int split_node, current_max;
int book_keeping;

int H[MAXN][2];
int L[MAXN];

int processed[MAXN];
int sz[MAXN];
int achievable[MAXK];
int minimum_paths[MAXK];

vector<pii> neighbors[MAXN];

void calc_size(int current, int parent)
{
    sz[current] = 0;

    int i;
    for (i = 0; i < (int)neighbors[current].size(); i++)
        if (!processed[neighbors[current][i].F] && neighbors[current][i].F != parent)
        {
            calc_size(neighbors[current][i].F, current);
            sz[current] += 1 + sz[neighbors[current][i].F];
        }
}

void select_split_node(int current, int parent, int total)
{
    int node_max = (total - sz[current] - 1);

    int i;
    for (i = 0; i < (int)neighbors[current].size(); i++)
        if (!processed[neighbors[current][i].F] && neighbors[current][i].F != parent)
        {
            select_split_node(neighbors[current][i].F, current, total);
            node_max = max(node_max, 1 + sz[neighbors[current][i].F]);
        }

    if (node_max < current_max)
    {
        split_node = current;
        current_max = node_max;
    }
}

void dfs_from_node(int current, int parent, int current_cost, int current_length, int fill)
{
    if (current_cost > K)
        return;

    if (!fill)
    {
        if (achievable[K - current_cost] == book_keeping)
            if (current_length + minimum_paths[K - current_cost] < global_answer || global_answer == -1)
                global_answer = current_length + minimum_paths[K - current_cost];

        if (current_cost == K)
            if (current_length < global_answer || global_answer == -1)
                global_answer = current_length;
    }
    else
    {
        if (achievable[current_cost] < book_keeping)
        {
            achievable[current_cost] = book_keeping;
            minimum_paths[current_cost] = current_length;
        }
        else if (current_length < minimum_paths[current_cost])
        {
            achievable[current_cost] = book_keeping;
            minimum_paths[current_cost] = current_length;
        }
    }

    int i;
    for (i = 0; i < (int)neighbors[current].size(); i++)
        if (!processed[neighbors[current][i].F] && neighbors[current][i].F != parent)
            dfs_from_node(neighbors[current][i].F, current, current_cost + neighbors[current][i].S, current_length + 1, fill);
}

void process(int current)
{
    calc_size(current, -1);

    if (sz[current] <= 1)
        return;

    split_node = -1;
    current_max = sz[current] + 3;
    select_split_node(current, -1, sz[current] + 1);

    book_keeping++;
    int i;
    for (i = 0; i < (int)neighbors[split_node].size(); i++)
        if (!processed[neighbors[split_node][i].F])
        {
            dfs_from_node(neighbors[split_node][i].F, split_node, neighbors[split_node][i].S, 1, 0);
            dfs_from_node(neighbors[split_node][i].F, split_node, neighbors[split_node][i].S, 1, 1);
        }

    int local_split_node = split_node;
    processed[split_node] = 1;

    for (i = 0; i < (int)neighbors[local_split_node].size(); i++)
        if (!processed[neighbors[local_split_node][i].F])
            process(neighbors[local_split_node][i].F);
}

int best_path(int _N, int _K, int H[][2], int L[])
{
    memset(processed, 0, sizeof processed);
    memset(achievable, 0, sizeof achievable);
    memset(minimum_paths, 0, sizeof minimum_paths);
    N = _N;
    K = _K;
    book_keeping = 0;

    int i;
    for (i = 0; i < N - 1; i++)
    {
        neighbors[H[i][0]].push_back(pii(H[i][1], L[i]));
        neighbors[H[i][1]].push_back(pii(H[i][0], L[i]));
    }

    global_answer = -1;

    process(0);

    return global_answer;
}

void read_input()
{
    cin >> N >> K;
    int i;
    for (i = 0; i < N - 1; i++)
        cin >> H[i][0] >> H[i][1] >> L[i];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    int ans;
    read_input();
    ans = best_path(N, K, H, L);
    cout << ans;

    return 0;
}