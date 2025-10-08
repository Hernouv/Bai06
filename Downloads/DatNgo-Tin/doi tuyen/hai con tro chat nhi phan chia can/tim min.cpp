#include <bits/stdc++.h>
using namespace std;

int divsq[1000];
int a[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(divsq, 0x3f, sizeof(divsq));
    memset(a, 0x3f, sizeof(a));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    const int basis = sqrt(n);
    for (int i = 1; i <= ceil(n / basis); ++i)
    {
        int tstart = (i - 1) * basis + 1;
        for (int j = tstart; j <= min(i * basis, n); ++j)
            divsq[i] = min(divsq[i], a[j]);
    }

    for (int i = 1; i <= m; ++i)
    {
        int type, xl, yr;
        cin >> type >> xl >> yr;
        if (type == 1)
        {
            a[xl] = yr;
            int it = ceil(xl / basis);
            divsq[it] = min(divsq[it], yr);
        }
        else if (type == 2)
        {
            int loblock = ceil((xl - 1) / basis);
            int hiblock = floor(yr / basis);
            int tmin = a[xl];
            for (int j = xl; j <= loblock * basis; ++j) tmin = min(tmin,a[j]);
            for (int j = loblock + 1; j <= hiblock; ++j) tmin = min(tmin, divsq[j]);
            for (int j = hiblock * basis + 1; j <= yr; ++j) tmin = min(tmin, a[j]);
            cout << tmin << '\n';
        }
    }
    return 0;
}
