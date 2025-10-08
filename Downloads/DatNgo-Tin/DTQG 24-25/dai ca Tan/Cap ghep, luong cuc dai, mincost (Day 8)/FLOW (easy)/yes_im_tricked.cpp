#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    long long n;
    cin >> n;
    long long a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    long long b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    long long wins = min(a1, b2) + min(a2, b3) + min(a3, b1);
    cout << wins;
    return 0;
}
