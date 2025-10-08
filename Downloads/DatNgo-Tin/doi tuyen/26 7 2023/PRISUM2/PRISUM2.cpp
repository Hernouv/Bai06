#include <bits/stdc++.h>
using namespace std;

bool erastos[2000010];
int n, k, arr[21];

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= 2000010; ++i)
        if (erastos[i])
            for (int j = i * i; j <= 2000010; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PRISUM2.INP", "r", stdin);
    freopen("PRISUM2.OUT", "w", stdout);
    sieve();
    cin >> n >> k;
    int cnt = 0;
    int wayofselect = pow(2, n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = pow(2, k) - 1; i < wayofselect; ++i)
    {
        int sum = 0, kcnt = 0;
        for (int j = 0; j <= k; ++j)
            if ((i >> j) & 1)
                sum += arr[j], kcnt++;
        if (erastos[sum] and kcnt == k)
            cnt++;
    }
    cout << cnt;
    return 0;
}