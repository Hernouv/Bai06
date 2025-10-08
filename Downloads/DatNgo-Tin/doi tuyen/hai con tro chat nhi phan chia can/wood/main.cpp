#include <bits/stdc++.h>
using namespace std;

int tree[1000001];
int cnt, height, wood, it;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(tree, 0, sizeof(tree));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> tree[i];
    sort(tree + 1, tree + n + 1, greater<int>());
    cnt = 0, wood = 0, height = tree[1], it = 1;
    do
    {
        height--;
        while (tree[it] > height) it++, cnt++;
        wood += cnt;
    } while (wood <= m);
    cout << height;
    return 0;
}
