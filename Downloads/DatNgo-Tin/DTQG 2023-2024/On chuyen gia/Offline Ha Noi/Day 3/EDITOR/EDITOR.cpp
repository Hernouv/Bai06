#include <bits/stdc++.h>
using namespace std;

#define task "EDITOR"
#define ll long long
#define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)

template <class T>
inline bool maximize(T &r, const T &v)
{
    return r < v ? r = v, 1 : 0;
}
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }

const int N = 1e6 + 7;
const int oo = 1e9 + 7;
const int mod = 1e9 + 7;
const int mm = mod * mod;
const int base = 31;

int n;
string s;
int h[N], f[N], A[N];

struct BIT
{
    int n, bit[N];

    void init(int _n)
    {
        n = _n;
        fill(bit, bit + n + 3, oo);
    }

    void update(int x, int val)
    {
        for (; x; x -= (x & -x))
            minimize(bit[x], val);
    }

    int get(int x)
    {
        int ans = INT_MAX;
        for (; x <= n; x += (x & -x))
            minimize(ans, bit[x]);
        return ans;
    }
} bit;

int get(int l, int r)
{
    return (A[r] - A[l - 1] * h[r - l + 1] + mm) % mod;
}

void proc()
{
    cin >> s;
    n = s.size();
    For(i, 1, n) A[i] = (A[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod;
    bit.init(n);
    For(i, 1, n)
    {
        int lst = i, l = i + 1, r = n;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int j = mid - i + 1;
            if (j < i && get(i, mid) == get(1, j))
            {
                lst = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        int val = 0;
        if (i > 1)
            val = bit.get(i - 1);
        bit.update(lst, val + 1);
    }
    cout << bit.get(n) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    h[0] = 1;
    For(i, 1, N - 1) h[i] = (h[i - 1] * base) % mod;
    int t;
    cin >> t;
    while (t--)
        proc();
    return 0;
}