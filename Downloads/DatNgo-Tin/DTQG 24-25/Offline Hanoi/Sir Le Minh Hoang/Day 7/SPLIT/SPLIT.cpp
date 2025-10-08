#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

#define fi first
#define se second

const int nmax = 5e3 + 5;

pair<string, int> dp[nmax];
int n;
string s;

bool comp(string a, string b)
{
    if (a.size() > b.size())
        b.insert(b.size(), a.size() - b.size(), '0');
    else
        a.insert(a.size(), b.size() - a.size(), '0');
    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }
    return false;
}

void not_main()
{
    cin >> n;
    cin >> s;
    s = ' ' + s;
    string ini = "";
    ini += s[1];
    dp[1] = {ini, 1};
    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        string ts = "";
        for (int j = i; j > 0; --j)
        {
            if (j < dp[i].se)
                break;
            ts += s[j];
            if (comp(ts, dp[j - 1].fi))
                if (maximize(dp[i].se, dp[j - 1].se + 1))
                    dp[i].fi = ts;
        }
    }

    cout << dp[n].se;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("SPLIT.INP", "r"))
    {
        freopen("SPLIT.INP", "r", stdin);
        freopen("SPLIT.OUT", "w", stdout);
    }
    not_main();
    return 0;
}