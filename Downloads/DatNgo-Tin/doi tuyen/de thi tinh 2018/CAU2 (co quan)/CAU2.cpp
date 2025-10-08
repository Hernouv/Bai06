#include <bits/stdc++.h>
using namespace std;

int eff[110][110];
int pos[110];
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> eff[i][j];
    for (int i = 1; i <= n; ++i)
        pos[i] = i;
    long long res = 0;
    while (next_permutation(pos + 1, pos + n + 1))
    {
        long long sum = 0;
        for (int i = 1; i <= n; ++i)
            sum += eff[i][pos[i]];
        res = max(res, sum);
    }
    cout << res;
    return 0;
}