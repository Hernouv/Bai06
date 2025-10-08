#include <bits/stdc++.h>
using namespace std;

unsigned long long f[100001];
unsigned long long mod = 1000000007;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    f[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        f[i] = (26 * f[i - 1] - f[i / 2 + i % 2] + mod) % mod;
    cout << f[n];
    return 0;
}
