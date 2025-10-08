#include <bits/stdc++.h>
using namespace std;

void not_main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    auto b = a;
    sort(b.begin(), b.end());
    for (int &x : a)
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    int cnt = 0, lz = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 != i % 2)
        {
            if (lz)
                --lz;
            else
            {
                ++cnt;
                ++lz;
            }
        }
    cout << cnt;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}