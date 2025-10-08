#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define push_back push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())

template <class T>
inline bool minimize(T &r, T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e5 + 7;
const int base = 41;
const int mod = 1e9 + 7;
const int mm = mod * mod;

int h[N];
map<int, int> cnt;
vector<vector<int>> hashmap;

int get(vector<int> &H, int l, int r)
{
    return (H[r] - H[l - 1] * h[r - l + 1] + mm) % mod;
}

bool check(int len)
{
    cnt.clear();
    int sz = hashmap.size();
    for (vector<int> &a : hashmap)
    {
        int n = a.size() - 1;
        vector<int> sav = vector<int>();
        for (int i = 1; i <= n - len + 1; ++i)
            sav.push_back(get(a, i, i + len - 1));

        uni(sav);
        for (int i : sav)
        {
            if (++cnt[i] == sz)
                return true;
        }
    }
    return false;
}

void not_main()
{
    h[0] = 1;
    for (int i = 1; i < N; ++i)
        h[i] = (h[i - 1] * base) % mod;
    int ans = 0;
    int l = 1, r = mod;
    string a;
    while (cin >> a)
    {
        int m = a.size();
        minimize(r, m);
        a = "*" + a;
        vector<int> b(m + 1, 0);
        for (int i = 1; i <= m; ++i)
            b[i] = (b[i - 1] * base + (a[i] - 'A' + 1)) % mod;
        hashmap.push_back(b);
    }

    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}