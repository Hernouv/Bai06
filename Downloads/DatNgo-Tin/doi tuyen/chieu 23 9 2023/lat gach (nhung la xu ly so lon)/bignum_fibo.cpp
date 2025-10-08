#include <bits/stdc++.h>
using namespace std;

string f[110];
int t, n;

string add(string a, string b)
{
    string ret = "";
    int sz_a = a.length(), sz_b = b.length();
    if (sz_a > sz_b)
        b.insert(0, sz_a - sz_b, '0');
    else
        a.insert(0, sz_b - sz_a, '0');
    int comp = 0, t_s;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        t_s = (a[i] - '0') + (b[i] - '0') + comp;
        if (t_s >= 10)
        {
            comp = 1;
            t_s -= 10;
        }
        else
            comp = 0;
        ret = char(t_s + '0') + ret;
    }
    if (comp)
        ret = '1' + ret;
    return ret;
}

void setVal()
{
    f[0] = '1';
    f[1] = '1';
    for (int i = 2; i <= 100; ++i)
        f[i] = add(f[i - 1], f[i - 2]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen
    setVal();
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}