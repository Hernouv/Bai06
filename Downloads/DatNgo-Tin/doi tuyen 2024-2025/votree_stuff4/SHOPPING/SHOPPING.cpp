#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int nmax = 2e5 + 10;
const int outbound = 1e9 + 7;

int nearestR_smaller[nmax];
ll price[nmax], budget;
int n, m, l, r;

ll spTable[18][nmax];
void construct()
{
    for (int i = 1; i <= n; ++i)
        spTable[0][i] = price[i];
    for (int i = 1; (1 << i) <= n; ++i)
        for (int j = 1; j <= n - (1 << i) + 1; ++j)
            spTable[i][j] = min(spTable[i - 1][j], spTable[i - 1][j + (1 << (i - 1))]);
}

int find_first(ll val, int L, int R)
{
    while (L < R)
    {
        int mid = (L + R) / 2;
        int chunk = __lg(mid - L + 1);
        ll tmp = min(spTable[chunk][L], spTable[chunk][mid - (1 << chunk) + 1]);
        if (tmp <= val)
            R = mid;
        else
            L = mid + 1;
    }
    if (price[L] > val)
        return outbound;
    else
        return L;
}

void not_main()
{
    memset(nearestR_smaller, outbound, sizeof nearestR_smaller);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> price[i];
    construct();

    for (int i = 1; i < n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (price[j] < price[i])
            {
                nearestR_smaller[i] = j;
                break;
            }

    for (int i = 1; i <= m; ++i)
    {
        cin >> budget >> l >> r;
        int initial_pos = find_first(budget, l, r);

        while (initial_pos <= r and budget)
        {
            budget %= price[initial_pos];
            while (initial_pos <= r and price[initial_pos] > budget)
                initial_pos = nearestR_smaller[initial_pos];
        }
        cout << budget << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SHOPPING.INP", "r"))
    {
        freopen("SHOPPING.INP", "r", stdin);
        freopen("SHOPPING.OUT", "w", stdout);
    }
    not_main();
    return 0;
}