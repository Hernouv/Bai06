#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int cur = 1, n, q;
vector<int> ver;
const int mxN = 2e5;
struct node
{
    int left, right, sum;
} segTree[mxN * 40];

void update(int &root, int idx, int val, int l = 0, int h = n - 1)
{
    segTree[cur].left = segTree[root].left;
    segTree[cur].right = segTree[root].right;
    segTree[cur].sum = segTree[root].sum + val;
    root = cur;
    cur++;
    int mid = (l + h) / 2;
    if (l == h)
        return;
    if (idx <= mid)
        update(segTree[root].left, idx, val, l, mid);
    else
        update(segTree[root].right, idx, val, mid + 1, h);
}

int query(int root, int a, int b, int l = 0, int h = n - 1)
{
    if (a <= l && h <= b)
        return segTree[root].sum;
    int mid = (l + h) / 2;
    return (a <= mid ? query(segTree[root].left, a, b, l, mid) : 0) +
           (mid < b ? query(segTree[root].right, a, b, mid + 1, h) : 0);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    ver.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        update(ver[0], i, x);
    }
    while (q--)
    {
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int k, a, x;
            cin >> k >> a >> x;
            k--, a--;
            update(ver[k], a, x - query(ver[k], a, a));
        }
        else if (ch == 2)
        {
            int k, a, b;
            cin >> k >> a >> b;
            k--, a--, b--;
            cout << query(ver[k], a, b) << endl;
        }
        else
        {
            int k;
            cin >> k;
            ver.push_back(ver[k - 1]);
        }
    }
}