#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100010];
pair<int, int> pseudo_map[100010];
int res = 0;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);
    arr[0] = -1;
    int it = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] == arr[i - 1])
            ++pseudo_map[it].second;
        else
            pseudo_map[++it] = {arr[i], 1};
    }

    for (int i = 2; i <= it; ++i)
    {
        if (pseudo_map[i].first - pseudo_map[i - 1].first == 1)
        {
            int upd = min(pseudo_map[i].second, pseudo_map[i - 1].second);
            res += upd;
            pseudo_map[i].second -= upd;
            res += (pseudo_map[i].second / 2);
            pseudo_map[i].second %= 2;
            pseudo_map[i - 1].second -= upd;
        }
    }

    cout << res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}