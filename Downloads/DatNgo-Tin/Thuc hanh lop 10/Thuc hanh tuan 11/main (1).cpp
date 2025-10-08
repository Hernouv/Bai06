#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    unsigned long long n;
    cin >> n;
    if (n <= 50)
        cout << n * 1.678;
    else
        if (n <= 100)
            cout << 50 * 1.678 + (n - 50) * 1.734;
        else
            cout << 50 * 1.678 + 50 * 1.734 + (n - 100) * 2.014;
 return 0;
}
