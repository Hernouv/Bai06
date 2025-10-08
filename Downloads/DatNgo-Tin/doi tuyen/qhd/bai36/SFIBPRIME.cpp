#include <bits/stdc++.h>
using namespace std;

bool erastos[1000010];
int fib[35];
int primefib[9], id = 0;
map<int, int> cnt;

void sieve()
{
    memset(erastos, true, sizeof(erastos));
    erastos[0] = erastos[1] = false;
    for (int i = 2; i <= 1000; ++i)
        if (erastos[i])
            for (int j = i * i; j <= 1000000; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("SFIBPRIME.INP", "r", stdin);
    freopen("SFIBPRIME.OUT", "w", stdout);
    sieve();
    fib[1] = fib[2] = 1;
    for (int i = 3; i <= 30; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (erastos[fib[i]])
            primefib[id++] = fib[i];
    }
    for (int i = 1; i < 512; ++i)
    {
        int s = 0;
        for (int j = 0; j < 9; ++j)
            if ((i >> j) & 1)
                s += primefib[j];
        if (s <= 1000000)
            cnt[s]++;
    }
    int n;
    cin >> n;
    if (cnt[n])
        cout << cnt[n];
    else
        cout << -1;
    return 0;
}