#include <bits/stdc++.h>
using namespace std;

string a, res;
int b;

string mul(string a, int b)
{
    string ret = "";
    long long t_mul, comp = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        t_mul = b * (a[i] - '0') + comp;
        comp = t_mul / 10;
        int add = t_mul % 10;
        ret = char(add + '0') + ret;
    }
    if (comp > 0)
        ret = to_string(comp) + ret;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("mulof2.inp", "r", stdin);
    // freopen("mulof2.out", "w", stdout);
    cin >> a >> b;
    res = mul(a, b);
    cout << res;
    return 0;
}