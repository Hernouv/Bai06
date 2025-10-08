#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll res = 0, lo;
stack<int> proc;

void not_main()
{
    cin >> n;
    ll tnum;
    ll tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> tnum;
        if (!proc.empty())
        {
            if (proc.top() < tnum)
            {
                tmp = max(tmp, tnum - lo);
                if (i == n)
                {
                    res += tmp;
                    break;
                }

                proc.push(tnum);
            }
            else
            {
                res += tmp;
                tmp = 0;
                while (!proc.empty())
                {
                    if (proc.top() >= tnum)
                        proc.pop();
                    else
                        break;
                }
                lo = tnum;
                proc.push(tnum);
            }
        }
        else
        {
            proc.push(tnum);
            lo = tnum;
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