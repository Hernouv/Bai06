#include <bits/stdc++.h>
using namespace std;

int a[5000010], b[5000010];
int accum[1010];
int m, n;
long long res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("bangso.inp", "r", stdin);
    // freopen("bangso.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    accum[0] = 0;
    for (int i = 1; i <= m; ++i)
        accum[i] = accum[i - 1] + a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (a[i] == b[j] and a[i])
            {
                int t_i = i + 1, t_j = j + 1;
                while (t_i <= m and t_j <= n)
                {
                    if ((a[t_i] == b[t_j]) and a[t_i])
                    {
                        if (accum[t_i] == accum[i - 1])
                            res++;
                        t_i++;
                        t_j++;
                    }
                    else
                        break;
                }
            }
        }
    cout << res;
    return 0;
}