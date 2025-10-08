#include <bits/stdc++.h>
using namespace std;

bool erastos[2000010];
int n, arr[100];

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
    freopen("PRISUM.INP", "r", stdin);
    freopen("PRISUM.OUT", "w", stdout);
    sieve();
    cin >> n;
    int cnt = 0;
    int wayofselect = pow(2, n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < wayofselect; ++i)
    {
        int sum = 0;
        for (int j = 0; j <= n; ++j)
            sum += ((i >> j) & 1 ? arr[j] : 0);
        if (erastos[sum])
            cnt++;
    }
    cout << cnt;
    return 0;
}