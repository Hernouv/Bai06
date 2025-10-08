#include <bits/stdc++.h>
using namespace std;

map<int, int> ability_cnt;
int n, k, arr[100010];
long long res = 0;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("TERACING.INP", "r", stdin);
    freopen("TERACING.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
        ability_cnt[arr[i]]++;
    }
    sort(arr + 1, arr + n + 1);
    int track = arr[1];
    for (int i = 2; i <= n; ++i)
    {
        if (arr[i] != track)
            res += ability_cnt[track] * ability_cnt[track + k];
        track = arr[i];
    }
    cout << res;
    return 0;
}