#include <bits/stdc++.h>
using namespace std;

int arr[200001], cnt[200001], n, num;

void proc()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        arr[i] = cnt[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> num;
        if (num <= n)
            cnt[num]++;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; j += i)
            arr[j] += cnt[i];

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, arr[i]);

    cout << res << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("JUMPTEST.INP", "r", stdin);
    freopen("JUMPTEST.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        proc();
    return 0;
}