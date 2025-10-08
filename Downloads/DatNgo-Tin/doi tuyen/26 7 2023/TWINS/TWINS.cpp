#include <bits/stdc++.h>
using namespace std;

bool erastos[2000010];
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
    freopen("TWINS.INP", "r", stdin);
    freopen("TWINS.OUT", "w", stdout);
    sieve();
    int n, k;
    cin >> n >> k;
    if (k & 1)
    {
        if (erastos[k + 2])
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        int cnt = 0;
        for (int i = 3; i <= n - k; i += 2)
            if (erastos[i] and erastos[i + k])
                cnt++;
        cout << cnt;
    }
    return 0;
}