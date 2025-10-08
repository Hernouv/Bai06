#include <bits/stdc++.h>
using namespace std;

bool erastos[1000001];
vector<int> beauty;
map<int, int> sumsq;

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
    freopen("BEAUTY2.INP", "r", stdin);
    freopen("BEAUTY2.OUT", "w", stdout);
    sieve();
    for (int i = 0; i <= 9; ++i)
        sumsq[i] = i * i;
    int scan = 10;
    int sz = 10000;
    while (sz)
    {
        int digit = scan % 10;
        sumsq[scan] = sumsq[scan / 10] + digit * digit;
        if (erastos[sumsq[scan]])
            beauty.push_back(scan), sz--;
        scan++;
    }
    int n;
    cin >> n;
    cout << beauty[n - 1];
}