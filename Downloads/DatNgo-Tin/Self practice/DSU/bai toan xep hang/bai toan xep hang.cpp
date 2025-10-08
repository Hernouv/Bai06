#include <bits/stdc++.h>
using namespace std;

int n, rq, leave, nearestRight;
int parent[10];
int sz[10];
int mx[10];

void setDefault()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        mx[i] = i;
        sz[i] = 1;
    }
}

int find_set(int v)
{
    if (parent[v] == v)
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mx[a] = max(mx[a], mx[b]);
    }
}

int find_nearestRight(int nearestRight)
{
    nearestRight = find_set(nearestRight);
    return mx[nearestRight];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("task.inp", "r"))
    {
        freopen("task.inp", "r", stdin);
        freopen("task.out", "w", stdout);
    }
    cin >> n >> rq;
    setDefault();
    for (int i = 1; i <= rq; ++i)
    {
        cin >> leave >> nearestRight;
        union_sets(leave, leave + 1);
        cout << find_nearestRight(nearestRight) << '\n';
    }
}