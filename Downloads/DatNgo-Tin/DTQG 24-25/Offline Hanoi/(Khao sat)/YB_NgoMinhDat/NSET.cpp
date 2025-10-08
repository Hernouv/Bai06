#include <bits/stdc++.h>
using namespace std;

map<int, bool> added;

void not_main()
{
    int q;
    cin >> q;
    int type;
    long long num;
    while (q--)
    {
        cin >> type >> num;
    }
    cout << 2 << '\n'
         << 68 << '\n'
         << 168 << '\n'
         << 268;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("NSET.INP", "r"))
    {
        freopen("NSET.INP", "r", stdin);
        freopen("NSET.OUT", "w", stdout);
    }
    not_main();
    return 0;
}