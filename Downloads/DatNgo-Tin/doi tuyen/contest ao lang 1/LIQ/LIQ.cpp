#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int l[1001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("LIQ.INP", "r", stdin);
    freopen("LIQ.OUT", "w", stdout);
    memset(l, false, sizeof(l));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    l[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int cmp = arr[i], it = i - 1;
        while (cmp < arr[it] and it > 1)
            it--;
        if (arr[it] > arr[i])
            it++;
        l[i] = l[it] + 1;
    }
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res = max(res, l[i]);
    cout << res;
    return 0;
}