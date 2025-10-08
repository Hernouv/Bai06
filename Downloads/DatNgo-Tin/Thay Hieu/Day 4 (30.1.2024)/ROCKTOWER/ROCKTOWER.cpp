#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 5e3 + 10;
int n;

struct rect_prism
{
    int id;
    int L;
    int W;
    int H;
} prisms[nmax];

bool cmp(rect_prism a, rect_prism b)
{
    return (a.L * a.W < b.L * b.W);
}

bool great(rect_prism a, rect_prism b)
{
    return (a.L >= b.L and a.W >= b.W);
}

int dp[nmax], prev_prism[nmax], prism_cnt[nmax];
int res, res_cnt, backtrack;

void not_main()
{
    cin >> n;
    int tmp[3];
    for (int i = 1; i <= n; ++i)
    {
        prisms[i].id = i;
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        sort(tmp, tmp + 3, greater<int>());
        prisms[i].L = tmp[0], prisms[i].W = tmp[1], prisms[i].H = tmp[2];
    }

    sort(prisms + 1, prisms + n + 1, cmp);

    // for (int i = 1; i <= n; ++i)
    //     cout << prisms[i].id << ' ' << prisms[i].L << ' ' << prisms[i].W << ' ' << prisms[i].H << '\n';

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (great(prisms[i], prisms[j]))
                if (maximize(dp[i], dp[j] + prisms[i].H))
                {
                    prev_prism[i] = j;
                    prism_cnt[i] = prism_cnt[j] + 1;
                }

    for (int i = 1; i <= n; ++i)
        if (maximize(res, dp[i]))
        {
            res_cnt = prism_cnt[i];
            backtrack = i;
        }

    cout << res << '\n';
    cout << res_cnt << '\n';

    queue<int> chosen_prisms;
    while (backtrack)
    {
        chosen_prisms.push(backtrack);
        backtrack = prev_prism[backtrack];
    }

    while (!chosen_prisms.empty())
    {
        int it = chosen_prisms.front();
        chosen_prisms.pop();
        cout << prisms[it].id << ' ' << prisms[it].W << ' ' << prisms[it].L << ' ' << prisms[it].H << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ROCKTOWER.INP", "r"))
    {
        freopen("ROCKTOWER.INP", "r", stdin);
        freopen("ROCKTOWER.OUT", "w", stdout);
    }
    not_main();
    return 0;
}