#include <bits/stdc++.h>
using namespace std;

int a[100010], b[100010], n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("horse.inp", "r", stdin);
    // freopen("horse.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int i = 1, j = 1, cnt = 0;
    while (i <= n and j <= n)
    {
        if (a[i] > b[j])
        {
            cnt++;
            j++;
        }
        i++;
    }
    cout << cnt;
    return 0;
}