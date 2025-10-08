#include <bits/stdc++.h>
using namespace std;

int tree[400010];
int n, q;

void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
        return;

    if (l == r)
    {
        tree[id] = v;
        return ;
    }

    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    tree[id] = tree[id*2] | tree[id*2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
        return 0;

    if (u <= l && r <= v)
        return tree[id];

    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) | get(id*2 + 1, mid+1, r, u, v);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        int temp;
        cin >> temp;
        update(1, 1, n, i, temp);
    }
    for (int i = 1; i <= q; ++i)
    {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n';
    }
}
