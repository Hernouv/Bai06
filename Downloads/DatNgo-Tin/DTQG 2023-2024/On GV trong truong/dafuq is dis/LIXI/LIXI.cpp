#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;
long long arr[nmax];
int n, k, q;

void not_main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> q;
    int query_type, t, l, r, m;
    for (int i = 1; i <= q; ++i)
    {
        cin >> query_type;
        if (query_type == 1)
        {
            vector<int> pos;
            for (int j = 1; j <= k; ++j)
            {
                cin >> t;
                pos.push_back(t);
            }
            long long temp_val = arr[pos[0]];
            for (int j = 0; j < pos.size() - 1; ++j)
                arr[pos[j]] = arr[pos[j + 1]];
            arr[pos[pos.size() - 1]] = temp_val;
        }
        else
        {
            cin >> l >> r >> m;
            long long out = 0, tsum = 0;
            for (int j = l; j < l + m; ++j)
                tsum += arr[j];
            out += tsum;
            int iter = l + m;
            while (iter <= r)
            {
                tsum = tsum + arr[iter] - arr[iter - m];
                out += tsum;
                ++iter;
            }
            cout << out << '\n';
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("LIXI.INP", "r"))
    {
        freopen("LIXI.INP", "r", stdin);
        freopen("LIXI.OUT", "w", stdout);
    }
    not_main();
    return 0;
}