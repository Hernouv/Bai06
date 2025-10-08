#include <bits/stdc++.h>
using namespace std;
string s, t;
const int N = 1e3 + 7;
int d[N][N];
int main()
{
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = " " + s;
    t = " " + t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i] == t[j])
                d[i][j] = max(d[i - 1][j - 1] + 1, d[i][j]);
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    if (d[n][m] >= max((n + 1) / 2, (m + 1) / 2))
        cout << 1;
    else
        cout << 2;
    return 0;
}