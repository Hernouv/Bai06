#include <bits/stdc++.h>
using namespace std;

int freq[1000002];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i <= n + 1; ++i)
        freq[i] = 0;

    int color_code;
    for (int i = 1; i <= n; ++i)
    {
        cin >> color_code;
        freq[color_code]++;
    }
    int res = 0;
    for (int i = 1; i <= 1000000; ++i)
        res = max(res, freq[i]);
    cout << res;
    return 0;
}