#include <bits/stdc++.h>
using namespace std;

bool erastos[10000001];

void sieve()
{
    erastos[0] = erastos[1] = false;
    for (int i = 2; i <= 1000; ++i)
        if (erastos[i])
            for (int j = i * i; j <= 1000000; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("ARR2DPRI.INP", "r", stdin);
    freopen("ARR2DPRI.OUT", "w", stdout);
    memset(erastos, true, sizeof(erastos));
    sieve();
    int m, n;
    bool prime_exist = false;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
        {
            int num;
            cin >> num;
            if (erastos[num])
            {
                cout << i << ' ' << j << '\n';
                prime_exist = true;
            }
        }
    if (!prime_exist)
        cout << -1;
    return 0;
}