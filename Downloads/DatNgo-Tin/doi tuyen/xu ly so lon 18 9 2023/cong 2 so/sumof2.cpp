#include <bits/stdc++.h>
using namespace std;

string a, b, sum;
string addition(string a, string b)
{
    int aLen = a.size(), bLen = b.size();
    if (aLen > bLen)
        b.insert(0, aLen - bLen, '0');
    else
        a.insert(0, bLen - aLen, '0');

    string c = "";
    int sumd, complement = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        sumd = (a[i] - '0') + (b[i] - '0') + complement;
        complement = sumd / 10;
        c = char(sumd % 10 + '0') + c;
    }
    if (a[0] - '0' + b[0] - '0' >= 10)
        c = '1' + c;
    return c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("sumof2.inp","r",stdin);
    // freopen("sumof2.out","w",stdout);
    cin >> a >> b;
    string sum = addition(a, b);
    cout << sum;
    return 0;
}