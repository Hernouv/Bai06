#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

#define all(x) (x).begin(), (x).end()

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;
const int oo = 1e7 + 7;

int n, m;
int mx = 0, mn = oo;
vector<vector<int>> a;
vector<vector<bool>> used;
vector<int> st;

bool check(int mxdist)
{
    vector<int> msk1(m + 1, 1);
    vector<int> msk2(m + 1, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j <= m; ++j)
            msk2[j] = 0;

        for (int j = 0; j < a[i].size(); ++j)
        {
            if (!msk1[j])
                continue;
            int L = lower_bound(all(a[i + 1]), a[i][j] - mxdist) - a[i + 1].begin();
            int R = upper_bound(all(a[i + 1]), a[i][j] + mxdist) - a[i + 1].begin();
            if (a[i + 1][L] - mxdist > a[i][j] || L >= m)
                continue;
            ++msk2[L];
            --msk2[R];
        }
        for (int j = 1; j <= m; ++j)
            msk2[j] += msk2[j - 1];
        swap(msk1, msk2);
    }
    for (int i = 0; i < m; ++i)
        if (msk1[i] > 0)
            return true;
    return false;
}

void not_main()
{
    cin >> n >> m;
    a.resize(n, vector<int>(m));
    used.resize(n, vector<bool>(m));
    for (vector<int> &x : a)
    {
        for (int &y : x)
        {
            cin >> y;
            minimize(mn, y);
            maximize(mx, y);
        }
        sort(all(x));
    }

    int ans = oo;
    int l = 0, r = mx - mn + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}