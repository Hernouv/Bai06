#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int c;
};

struct UnionFind
{
    vector<int> parent;
    vector<int> size;
    UnionFind(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find_set(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }
    void union_set(int x, int y)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx == fy)
            return;
        if (size[fx] < size[fy])
        {
            parent[fx] = fy;
            size[fy] += size[fx];
        }
        else
        {
            parent[fy] = fx;
            size[fx] += size[fy];
        }
    }
};

const int MAX_BITS = 200034;
const int BLOCK_SIZE = 64;
const int NUM_BLOCKS = (MAX_BITS + BLOCK_SIZE - 1) / BLOCK_SIZE;

vector<uint64_t> sum_blocks;

void add_contribution(uint64_t a_b, int c)
{
    int block = c / BLOCK_SIZE;
    int offset = c % BLOCK_SIZE;
    uint64_t lower = (a_b << offset);
    uint64_t upper = (offset != 0) ? (a_b >> (BLOCK_SIZE - offset)) : 0;
    while (block >= sum_blocks.size())
    {
        sum_blocks.emplace_back(0);
    }
    uint64_t prev = sum_blocks[block];
    sum_blocks[block] += lower;
    bool carry = sum_blocks[block] < prev;
    if (offset != 0)
    {
        if (block + 1 >= sum_blocks.size())
        {
            sum_blocks.emplace_back(0);
        }
        prev = sum_blocks[block + 1];
        sum_blocks[block + 1] += upper + (carry ? 1 : 0);
        bool carry2 = sum_blocks[block + 1] < (upper + (carry ? 1 : 0));
        if (carry2)
        {
            int k = block + 2;
            while (true)
            {
                if (k >= sum_blocks.size())
                {
                    sum_blocks.emplace_back(0);
                }
                prev = sum_blocks[k];
                sum_blocks[k] += 1;
                if (sum_blocks[k] != 0)
                {
                    break;
                }
                k++;
            }
        }
    }
    else
    {
        if (carry)
        {
            if (block + 1 >= sum_blocks.size())
            {
                sum_blocks.emplace_back(0);
            }
            prev = sum_blocks[block + 1];
            sum_blocks[block + 1] += 1;
            bool carry2 = sum_blocks[block + 1] < (0);
            if (carry2)
            {
                int k = block + 2;
                while (true)
                {
                    if (k >= sum_blocks.size())
                    {
                        sum_blocks.emplace_back(0);
                    }
                    prev = sum_blocks[k];
                    sum_blocks[k] += 1;
                    if (sum_blocks[k] != 0)
                    {
                        break;
                    }
                    k++;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    struct InputEdge
    {
        int u, v, c;
    };
    vector<InputEdge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].c;
    sort(edges.begin(), edges.end(), [&](const InputEdge &a, const InputEdge &b) -> bool
         { return a.c < b.c; });
    UnionFind uf(n);
    vector<vector<Edge>> adj(n + 1, vector<Edge>());
    for (auto &e : edges)
    {
        int u = e.u;
        int v = e.v;
        int c = e.c;
        if (uf.find_set(u) != uf.find_set(v))
        {
            uf.union_set(u, v);
            adj[u].push_back(Edge{v, c});
            adj[v].push_back(Edge{u, c});
        }
    }
    sum_blocks.reserve(NUM_BLOCKS);
    sum_blocks.assign(NUM_BLOCKS, 0);
    vector<pair<int, int>> stack;
    vector<pair<int, int>> traversal_order;
    stack.emplace_back(make_pair(1, 0));
    while (!stack.empty())
    {
        auto [u, parent] = stack.back();
        stack.pop_back();
        traversal_order.emplace_back(u, parent);
        for (auto &e : adj[u])
        {
            if (e.to != parent)
            {
                stack.emplace_back(make_pair(e.to, u));
            }
        }
    }
    vector<long long> subtree_size(n + 1, 0);
    for (int i = traversal_order.size() - 1; i >= 0; i--)
    {
        auto [u, parent] = traversal_order[i];
        subtree_size[u] = 1;
        for (auto &e : adj[u])
        {
            if (e.to != parent)
            {
                subtree_size[u] += subtree_size[e.to];
                long long a_b = subtree_size[e.to] * (long long)(n - subtree_size[e.to]);
                add_contribution(a_b, e.c);
            }
        }
    }
    int highest_bit = -1;
    for (int k = NUM_BLOCKS - 1; k >= 0; k--)
    {
        if (sum_blocks[k] != 0)
        {
            for (int b = 63; b >= 0; b--)
            {
                if (sum_blocks[k] & (1ULL << b))
                {
                    highest_bit = k * 64 + b;
                    break;
                }
            }
            if (highest_bit != -1)
                break;
        }
    }
    if (highest_bit == -1)
    {
        cout << "0\n";
        return 0;
    }
    string binary;
    binary.reserve(highest_bit + 1);
    for (int i = highest_bit; i >= 0; i--)
    {
        int block = i / 64;
        int bit = i % 64;
        binary += ((sum_blocks[block] & (1ULL << bit)) ? '1' : '0');
    }
    cout << binary << '\n';
}
