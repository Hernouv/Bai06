#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("MAC2.INP", "r", stdin);
    freopen("MAC2.OUT", "w", stdout);
    int q, vmax = 0;
    cin >> q;
    vector<int> arr(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> arr[i];
        vmax = max(vmax, arr[i]);
    }
    vector<int> seq(vmax + 1, 0);
    for (int i = 1; i <= vmax; ++i)
        for (int j = i; j <= vmax; j += i)
            seq[j] += i;

    for (int i = 0; i < q; ++i)
        cout << seq[arr[i]] << '\n';
    return 0;
}
// dme qiqi