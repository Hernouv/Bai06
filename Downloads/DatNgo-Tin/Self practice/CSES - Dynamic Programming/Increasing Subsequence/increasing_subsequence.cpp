#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 10;
const long long outbound = 1e9 + 7;
vector<long long> lis(nmax, outbound);
int a[nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int pos = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        lis[pos] = a[i];
    }
    int sz = 0;
    while (lis[sz] != outbound)
        ++sz;
    cout << sz;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}