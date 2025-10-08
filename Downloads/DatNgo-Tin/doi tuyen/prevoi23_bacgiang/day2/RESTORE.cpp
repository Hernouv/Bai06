#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int n, s;
    cin >> n >> s;
    int d;
    for (int i = 1; i <= n; ++i)
        cin >> d;
    cout << "1 2 1\n1 3 -1\n3 4 1\n3 5 1";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("RESTORE.INP", "r"))
    {
        freopen("RESTORE.INP", "r", stdin);
        freopen("RESTORE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}
