#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e3 + 10;

string s;
int sz;
bool f[nmax][nmax];
int cnt[nmax][nmax];

void not_main()
{
    cin >> s;
    int sz = s.size();
    s = ' ' + s;
    for (int i = 1; i <= sz; ++i)
    {
        cnt[i][i] = 1;
        f[i][i] = 1;
    }

    for (int i = 1; i < sz; ++i)
    {
        if (s[i] == s[i + 1])
        {
            cnt[i][i + 1] = 3;
            f[i][i + 1] = 1;
        }
        else
            cnt[i][i + 1] = 2;
    }

    for (int len = 3; len <= sz; ++len)
    {
        for (int i = 1; i + len - 1 <= sz; ++i)
        {
            if (s[i] - s[i + len - 1] == 0 and f[i - 1][i + len - 2])
                f[i][i + len - 1] = true;
            cnt[i][i + len - 1] = cnt[i][i + len - 2] + cnt[i + 1][i + len - 1] - cnt[i + 1][i + len - 2] + f[i][i + len - 1];
        }
    }

    for (int i = 1; i <= sz; ++i)
    {
        for (int j = 1; j <= sz; ++j)
            cout << i << ' ' << j << ' ' << cnt[i][j] << ' ' << f[i][j] << '\n';
    }

    cout << s[1] << ' ' << s[3];
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}