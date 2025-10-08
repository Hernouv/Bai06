#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    long long n;
    cin >> n;
    if (n % 400 == 0)
        cout << "nhuan";
    else if (n % 4 == 0)
    {
        if (n % 100 != 0)
            cout << "nhuan";
        else
            cout << "khong nhuan";
    }
    else
        cout << "khong nhuan";
    return 0;
}
