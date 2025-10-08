#include <bits/stdc++.h>
using namespace std;

int n, k;
string inp;

void not_main()
{
    cin >> n >> k;
    cin >> inp;

    long long res;
    for (int i = 1; i <= 100000000; ++i)
        res += i;

    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RBGAME.INP", "r"))
    {
        freopen("RBGAME.INP", "r", stdin);
        freopen("RBGAME.OUT", "w", stdout);
    }
    clock_t time_req;
    time_req = clock();
    not_main();
    time_req = clock() - time_req;
    cout << '\n';
    cout << "Running time: " << (float)time_req / CLOCKS_PER_SEC * 5 << " sec";
    return 0;
}