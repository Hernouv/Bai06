#include <bits/stdc++.h>
using namespace std;

long long h[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("OPTGAME.INP", "r", stdin);
    freopen("OPTGAME.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    int m, pos, length;
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        long long score = 0;
        cin >> pos >> length;
        for (int j = pos + 1; j <= pos + length; ++j)
            if (h[j] > h[pos])
            {
                score += (h[j] - h[pos]);
                h[j] = h[pos];
            }
        cout << score << '\n';
    }
    return 0;
}