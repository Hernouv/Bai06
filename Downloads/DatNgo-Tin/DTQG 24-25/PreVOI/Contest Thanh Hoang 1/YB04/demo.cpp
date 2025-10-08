#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int a, b;
    cin >> a >> b;
    cout << a + b;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("DEMO.INP", "r"))
    {
        freopen("DEMO.INP", "r", stdin);
        freopen("DEMO.OUT", "w", stdout);
    }
    not_main();
    return 0;
}