#include <bits/stdc++.h>
using namespace std;

#define task "PALIND"
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

int n;
string s;

bool operator>=(string &a, string &b)
{
    For(i, 1, n)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

void proc()
{
    cin >> s;
    n = s.size();
    s = "*" + s;
    string a = s;
    For(i, 1, (n + 1) / 2) a[n - i + 1] = a[i];
    if (a >= s)
    {
        For(i, 1, n) cout << a[i];
        return;
    }

    int x = a[(n + 1) / 2] - '0';
    x += 1;
    int t = x / 10;
    x %= 10;
    a[(n + 1) / 2] = (char)(x + '0');
    if (t)
    {
        Fod(i, (n + 1) / 2 - 1, 1)
        {
            int x = a[i] - '0';
            x += t;
            t = x / 10;
            x %= 10;
            a[i] = (char)(x + '0');
        }
    }
    For(i, 1, (n + 1) / 2) a[n - i + 1] = a[i];
    For(i, 1, n) cout << a[i];
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    proc();
    return 0;
}