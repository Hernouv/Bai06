#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        arr.clear();
        int sz, k;
        cin >> sz >> k;
        int ans = 0;
        for (int j = 1; j <= sz; ++j)
        {
            int t;
            cin >> t;
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i = 0; i < k; ++i) if (arr[i] == arr[i + k]) ans++;
        for (int i = 2 * k; i < sz; ++i) ans += arr[i];
        cout << ans << '\n';
    }
    return 0;
}
