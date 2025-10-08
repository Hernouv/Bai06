#include <bits/stdc++.h>
using namespace std;

int solve(string s, string t)
{
    int n = s.size();

    vector<int> prev(n + 1);
    vector<int> curr(n + 1);

    int r = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            curr[j] = 0;
            if (i > 0)
                curr[j] = max(prev[j], curr[j]);

            if (s[i] == t[j])
            {

                int ans = 1;
                if (i > 0 and j > 0)
                    ans = 1 + prev[j - 1];

                curr[j] = max(curr[j], ans);
                r = max(r, curr[j]);
            }
        }
        prev = curr;
    }
    return (n - r);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("ANAGRAM.INP", "r"))
    {
        freopen("ANAGRAM.INP", "r", stdin);
        freopen("ANAGRAM.OUT", "w", stdout);
    }
    string s, t;
    cin >> t >> s;
    // length - lcs of contiguous substring of t and norm substr of s
    cout << solve(s, t);
    return 0;
}
