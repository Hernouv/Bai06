#include <bits/stdc++.h>
using namespace std;

int arr[10000010];
string inp;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);
    cin >> inp;
    int sz = inp.size();
    for (int i = 0; i < sz; ++i)
        arr[i] = inp[i] - '0';
    sort(arr, arr + sz, greater<int>());
    int sumd = 0;
    for (int i = 0; i < sz; ++i)
        sumd += arr[i];
    if (sumd % 3 == 0 and arr[sz - 1] == 0)
        for (int i = 0; i < sz; ++i)
            cout << arr[i];
    else
        cout << -1;
    return 0;
}