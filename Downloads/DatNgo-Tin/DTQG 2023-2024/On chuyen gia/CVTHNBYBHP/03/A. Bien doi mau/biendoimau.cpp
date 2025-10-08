#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int row[5000010];
int column[5000010];
int res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;

    char rq;
    int pos;
    for (int i = 1; i <= k; ++i)
    {
        cin >> rq >> pos;
        if (rq == 'C')
            ++column[pos];
        else
            ++row[pos];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if ((row[i] + column[j]) % 2)
                ++res;
    cout << res;
    return 0;
}