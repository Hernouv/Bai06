#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[100010];
vector<pair<int, int>> sort_out;
int n;

inline bool byFirst(pair<int, int> &a, pair<int, int> &b)
{
    return (a.first < b.first);
}

inline bool bySecond(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("del.inp", "r", stdin);
    // freopen("del.out", "w", stdout);
    cin >> n;
    int num;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr + 1, arr + n + 1, byFirst);
    int freq = 1;
    arr[n + 1] = {INT_MAX, n + 1};
    for (int i = 2; i <= n + 1; ++i)
    {
        if (arr[i].first == arr[i - 1].first)
            freq++;
        else
        {
            if (freq == 1)
                sort_out.emplace_back(arr[i - 1]);
            freq = 1;
        }
    }
    sort(sort_out.begin(), sort_out.end(), bySecond);
    cout << sort_out.size() << '\n';
    for (auto x : sort_out)
        cout << x.first << ' ';
    return 0;
}