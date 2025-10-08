#include <bits/stdc++.h>
using namespace std;

bool erastos[1000010];
int factcnt[1000010];

void sieve(int vmax)
{
    memset(erastos, true, sizeof(erastos));
    for (int i = 2; i * i <= vmax; ++i)
        if (erastos[i])
            for (int j = i * i; j <= vmax; j += i)
                erastos[j] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("MAC3.INP", "r", stdin);
    freopen("MAC3.OUT", "w", stdout);
    int q, vmax = 0;
    cin >> q;
    vector<int> arr(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> arr[i];
        vmax = max(vmax, arr[i]);
    }
    sieve(vmax);
    vector<int> sumfact(vmax + 1, 0);
    for (int i = 2; i <= vmax; ++i)
        if (!erastos[i])
            for (int j = i; j <= vmax; j += i)
                sumfact[j] += i;
    for (int i = 0; i < q; ++i)
        cout << sumfact[arr[i]] << '\n';
    return 0;
}