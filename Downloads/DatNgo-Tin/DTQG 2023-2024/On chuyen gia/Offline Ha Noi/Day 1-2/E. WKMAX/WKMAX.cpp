#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
int n, k;
long long a[100010];

long long res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        multiset<long long> findMin;
        long long sumRange = 0;
        for (int j = i; j <= min(i + k - 1, n); ++j)
        {
            sumRange = (sumRange + a[j]) % mod;
            res = (res + sumRange) % mod;
            findMin.insert(a[j]);
        }

        for (int j = i + k; j <= n; ++j)
        {
            findMin.insert(a[j]);
            sumRange = (sumRange + a[j] - *findMin.begin()) % mod;
            res = (res + sumRange) % mod;
            findMin.erase(findMin.begin());
        }
    }
    cout << res;
    return 0;
}