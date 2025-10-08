// doi he nhi phan sang he thap phan
#include <bits/stdc++.h>
using namespace std;
int n, res;
string s;
int main()
{
    cin >> s;
    int n = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
        res += (s[i] - 48) * pow(2, n - i);
    cout << res;
    return 0;
}