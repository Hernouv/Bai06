#include <bits/stdc++.h>
using namespace std;

#define int long long

#define REP(i, n) for (int i = 1, _n = (n); i <= _n; i++)

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<char> proc;
    for (int i = 0; i < n; i++)
    {
        proc.push_back(s[i]);

        if (proc.back() == t.back() and proc.size() >= m)
        {
            bool ok = true;
            int cur = m - 1;
            for (int j = proc.size() - 1; j > proc.size() - 1 - m; j--)
            {
                if (proc[j] != t[cur--])
                {
                    ok = false;
                    break;
                }
                if (!ok)
                    break;
            }

            if (ok)
            {
                REP(_, m)
                proc.pop_back();
            }
        }
    }

    if (proc.empty())
    {
        cout << "EMPTY";
    }
    else
        for (char ch : proc)
            cout << ch;
}