#include <bits/stdc++.h>
using namespace std;

int n, k;
bitset<4001> s1[4001];

void not_main()
{
    cin >> n >> k;
    int a, b;
    if (n <= 4000)
    {
        for (int i = 1; i <= n; ++i)
            s1[i][i] = true;
        char query_type;
        for (int i = 1; i < n + k; ++i)
        {
            cin >> query_type;
            if (query_type == 'S')
            {
                cin >> a >> b;
                s1[a] |= s1[b];
                s1[b] = s1[a];
            }
            else if (query_type == 'C')
            {
                cin >> a;
                int cnt = 0;
                for (int j = 1; j <= n; ++j)
                    if (s1[j][a])
                        ++cnt;
                cout << cnt << '\n';
            }
            else if (query_type == 'Q')
            {
                cin >> a >> b;
                if (s1[a][b])
                    cout << "yes" << '\n';
                else
                    cout << "no" << '\n';
            }
        }
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("WSHARE.INP", "r"))
    {
        freopen("WSHARE.INP", "r", stdin);
        freopen("WSHARE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}