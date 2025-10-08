#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    long long ans = 0;
    // Tính f(l,r) = max(0, sum_{i=l}^{r} t_i * a_i * (i-l+1))
    // O(n^2) giải cho n=7 là được

    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            long long val = 0;
            for (int i = l; i <= r; i++)
            {
                val += t[i] * a[i] * (i - l + 1);
            }
            if (val < 0)
                val = 0;
            ans += val;
        }
    }

    cout << ans << "\n";

    return 0;
}
