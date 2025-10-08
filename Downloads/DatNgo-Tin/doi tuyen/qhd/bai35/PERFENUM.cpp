#include <bits/stdc++.h>
using namespace std;

set<int> fact = {1};
int perfenum[5] = {6, 28, 496, 8128, 33550336};
map<int, bool> possible;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PERFENUM.INP", "r", stdin);
    freopen("PERFENUM.OUT", "w", stdout);
    int n;
    for (int i = 1; i < 64; ++i)
    {
        int s = 0;
        for (int j = 0; j < 6; ++j)
            if ((i >> j) & 1)
                s += perfenum[j];
        possible[s] = true;
    }
    cin >> n;
    if (possible[n])
        cout << 1;
    else
        cout << -1;
    return 0;
}
