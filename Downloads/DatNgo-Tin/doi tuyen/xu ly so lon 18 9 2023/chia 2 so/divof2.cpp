#include <bits/stdc++.h>
using namespace std;

string a, res;
int b;

string div(string a, int b)
{
    string ret = "";
    int t, d;
    for (int i = 0; i < a.size(); ++i)
    {
        t = t * 10 + (a[i] - '0');
        d = t / b;
        t = t % b;
        ret += char(d + '0');
    }
    while (ret.size() > 1 and ret[0] == '0')
        ret.erase(0, 1);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("divof2.inp", "r", stdin);
    // freopen("divof2.out", "w", stdout);
    cin >> a >> b;
    res = div(a, b);
    cout << res;
    return 0;
}