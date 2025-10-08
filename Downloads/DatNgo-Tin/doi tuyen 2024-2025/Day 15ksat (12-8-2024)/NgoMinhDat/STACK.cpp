#include <bits/stdc++.h>
using namespace std;

const int nmax = 2510;

struct node
{
    int w;
    int c;
} boxes[nmax];

inline bool customSort(node &a, node &b)
{
    return (a.w + a.c > b.w + b.c);
}

int n, res = 0;
int wlist[nmax];
int clist[nmax];
int dp[nmax], remain_w[nmax];

void not_main()
{
    cin >> n;
    int t_w, t_c;
    for (int i = 1; i <= n; ++i)
        cin >> wlist[i];
    for (int i = 1; i <= n; ++i)
        cin >> clist[i];
    for (int i = 1; i <= n; ++i)
        boxes[i] = {wlist[i], clist[i]};
    sort(boxes + 1, boxes + n + 1, customSort);

    dp[1] = 1, remain_w[1] = boxes[1].c;
    for (int i = 2; i <= n; ++i)
        for (int j = i - 1; j >= 1; --j)
            if (dp[i] < dp[j] + 1 and boxes[i].w <= boxes[j].c and remain_w[j] >= boxes[i].w)
            {
                dp[i] = dp[j] + 1;
                remain_w[i] = remain_w[j] - boxes[i].w;
            }

    for (int i = 1; i <= n; ++i)
        res = max(res, dp[i]);
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("STACK.INP", "r"))
    {
        freopen("STACK.INP", "r", stdin);
        freopen("STACK.OUT", "w", stdout);
    }
    not_main();
    return 0;
}