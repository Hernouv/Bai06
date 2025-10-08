#include <bits/stdc++.h>
using namespace std;

long long arr[1001], sumsecondhalf = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("CHIAMANG.INP", "r", stdin);
    freopen("CHIAMANG.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        sumsecondhalf += arr[i];
    }
    bool available = false;
    long long sumfirsthalf = 0;
    for (int i = 1; i < n; ++i)
    {
        sumfirsthalf += arr[i];
        sumsecondhalf -= arr[i];
        if (sumfirsthalf == sumsecondhalf)
        {
            cout << i;
            available = true;
            break;
        }
    }
    if (!available)
        cout << 0;
    return 0;
}