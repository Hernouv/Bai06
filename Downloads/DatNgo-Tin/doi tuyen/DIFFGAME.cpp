/**
 *  Created at 09:10, Monday November 27, 2023
 *  By ms24 <3
 */
// #pragma GCC optimize("Ofast,02,unroll-loops")
// #pragma GCC target("avx2,fma,popcnt,lzcnt,abm,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

#define task "DIFFGAME"
#define ll long long
// #define int ll
#define ii pair<int, int>
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uni(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define For(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define Fod(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
template <class T>
inline bool maximize(T &r, const T &v) { return r < v ? r = v, 1 : 0; }
template <class T>
inline bool minimize(T &r, const T &v) { return r > v ? r = v, 1 : 0; }
// #define cerr if (0) cerr
// #define CTIME

const int N = 1e6 + 7;

int n, m;
int a[N], f[N];

int powd(int x)
{
    return x * x;
}

void ttk32()
{
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    cin >> n >> m;
    For(i, 1, n)
    {
        cin >> a[i];
        set<int> st;
        Fod(j, i, 1)
        {
            st.insert(a[j]);
            minimize(f[i], f[j - 1] + powd(st.size()));
        }
    }
    cout << f[n];
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ttk32();
#ifdef CTIME
    cerr << "\nTime: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}