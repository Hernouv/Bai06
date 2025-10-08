#include <bits/stdc++.h>
using namespace std;

int n, res = 0, lowest;
stack<int> proc;

void not_main()
{
    cin >> n;
    int tnum;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tnum;
        if (!proc.empty())
        {
            while (!proc.empty())
            {
                if (proc.top() >= tnum)
                    proc.pop();
                else
                    break;
            }
            if (proc.empty())
                lowest = tnum;
            else
                res = max(res, tnum - lowest);
            proc.push(tnum);
        }
        else
        {
            proc.push(tnum);
            lowest = tnum;
        }
    }
    cout << res;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}