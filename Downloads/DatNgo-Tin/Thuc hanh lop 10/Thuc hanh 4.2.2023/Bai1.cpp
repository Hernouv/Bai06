//ctrinh bien doi so tu nhien n sang he nhi phan
#include <bits/stdc++.h>
using namespace std;
int n;
string s= "";
int main()
{
    cin >> n;
    while (n > 0)
    {
        char c = char(n%2 + 48);
        s = c + s;
        n = n / 2;
    }
    cout << s;
    return 0;
}