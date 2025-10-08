#include <bits/stdc++.h>
using namespace std;

bool n, s, e, w;
string journey;

void not_main()
{
    cin >> journey;
    for (char ch : journey)
    {
        if (ch == 'N')
            n = true;
        else if (ch == 'S')
            s = true;
        else if (ch == 'E')
            e = true;
        else if (ch == 'W')
            w = true;
    }
    if ((n + s + e + w == 4) or (n + s == 2 and e + w == 0) or (e + w == 2 and n + s == 0))
        cout << "Yes";
    else
        cout << "No";
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}