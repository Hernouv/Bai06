#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    unsigned long long n;
    cin >> n;
    if (n < 5)
        cout << n * 12000;
    else
        cout << n * 10000;
    return 0;
}
