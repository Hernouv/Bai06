#include <bits/stdc++.h>
using namespace std;

string a, b, subtr;
string subtract(string a, string b)
{
    int aLen = a.size(), bLen = b.size();
    bool neg = false;
    if (aLen < bLen)
    {
        neg = true;
        swap(a, b);
    }
    else if (aLen == bLen)
    {
        bool greater = true;
        int it = 0;
        while (it < aLen and a[it] == b[it])
        {
            it++;
        }
        if (it == aLen)
            return "0";
        else if (a[it] < b[it])
            greater = false;
        if (!greater)
        {
            neg = true;
            swap(a, b);
        }
    }
    b.insert(0, a.size() - b.size(), '0');
    int t, comp = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        t = (a[i] - '0') - (b[i] - '0') - comp;
        if (t < 0)
        {
            t += 10;
            comp = 1;
        }
        else
            comp = 0;
        subtr = char(t + '0') + subtr;
    }
    while (subtr.size() > 1 and subtr[0] == '0')
        subtr.erase(0, 1);
    if (neg)
        subtr.insert(0, 1, '-');
    return subtr;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("sub2.inp","r",stdin);
    // freopen("sub2.out", "w", stdout);
    cin >> a >> b;
    subtr = subtract(a, b);
    cout << subtr;
    return 0;
}