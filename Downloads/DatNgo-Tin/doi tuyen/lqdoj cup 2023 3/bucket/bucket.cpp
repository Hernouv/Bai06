#include <bits/stdc++.h>
using namespace std;

pair<int, int> lid_et_bucket[300010];
int lid[300010];
inline bool bySecond(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}
int n;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    freopen("bucket.inp", "r", stdin);
    freopen("bucket.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> lid_et_bucket[i].first >> lid_et_bucket[i].second;
    sort(lid_et_bucket + 1, lid_et_bucket + n + 1, bySecond);
    bool all = true;
    for (int i = 1; i <= n; ++i)
        if (lid_et_bucket[i].first < lid_et_bucket[i].second)
        {
            all = false;
            break;
        }
    if (all)
        cout << n;
    else
    {
        for (int i = 1; i <= n; ++i)
            lid[i] = lid_et_bucket[i].first;
        sort(lid + 1, lid + n + 1);
        bool avail = true;
        for (int i = 1; i <= n; ++i)
            if (lid[i] < lid_et_bucket[i].second)
            {
                avail = false;
                break;
            }
        if (!avail)
            cout << -1;
        else
        {
            int res = 0;
            for (int i = pow(2, n) - 1; i >= 0; --i)
            {
                bool check = true;
                for (int j = 0; j < n; ++j)
                    if ((i >> j) & 1)
                    {
                        if (lid_et_bucket[j].first < lid_et_bucket[j].second)
                        {
                            check = false;
                            break;
                        }
                    }
                if (check)
                {
                    vector<int> lid, bucket;
                    for (int j = 0; j < n; ++j)
                        if ((i >> j) & 1 == 0)
                        {
                            lid.push_back(lid_et_bucket[i].first);
                            bucket.push_back(lid_et_bucket[i].second);
                        }
                    sort(lid.begin(), lid.end());
                    bool possible = true;
                    for (int j = 0, sz = lid.size(); j < sz; ++j)
                        if (lid[j] < bucket[j])
                        {
                            possible = false;
                            break;
                        }
                    if (possible)
                    {
                        cout << __builtin_popcount(i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}