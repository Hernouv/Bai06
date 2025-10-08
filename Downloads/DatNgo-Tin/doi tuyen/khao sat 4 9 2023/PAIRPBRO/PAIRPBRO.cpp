#include <bits/stdc++.h>
using namespace std;

bool erastos[1000010];
int n, k, cnt = 0;

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (erastos[i])
            for (int j = i * i; j <= n; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("PAIRPBRO.INP", "r", stdin);
    freopen("PAIRPBRO.OUT", "w", stdout);
    cin >> n >> k;
    sieve();
    if (k % 2 == 1)
    {
        if (erastos[2 + k])
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        for (int i = 3; i <= n - k; i += 2)
            if (erastos[i] and erastos[i + k])
            {
                cnt++;
            }
        cout << cnt;
    }
    return 0;
}