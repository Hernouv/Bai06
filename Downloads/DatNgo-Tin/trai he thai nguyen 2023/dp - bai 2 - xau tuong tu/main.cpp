#include <bits/stdc++.h>
using namespace std;

string inp;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> inp;
    int sz = inp.size();
    int ans = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (inp[0] == inp[sz - 1 - i])
        {
            ans = sz - 1 - i;
            cout << 1 << ' ' << ans << ' ' << 2 << ' ' << ans + 1;
            break;
        }
        if (inp[i] == inp[sz - 1])
        {
            ans = sz - 1 - i;
            cout << sz - ans << ' ' << ans + i << ' ' << sz - ans + 1 << ' ' << sz;
            break;
        }
    }
    return 0;
}
