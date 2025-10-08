/**
 *  Created at 09:54, Friday November 03, 2023
 *  By ms24 <3
 */
#include <bits/stdc++.h>
using namespace std;

#define task "SQUARE"
#define ll long long
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

const int N = 67;

int t, n;
char a[N][N];
int row[N], col[N];

void ttk32()
{
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    cin >> n;
    For(i, 1, n)
    {
        For(j, 1, n)
        {
            cin >> a[i][j];
            if (a[i][j] == 'X' || a[i][j] == 'x')
                ++row[i], ++col[j];
        }
    }
    int cnt1 = 0;
    For(i, 1, n) if (row[i] == 1)++ cnt1;
    int cnt2 = 0, cnt3 = 0;
    For(i, 1, n)
    {
        cnt2 += (row[i] == 2);
        cnt3 += (col[i] == 2);
    }
    if (cnt2 != n - 1 || cnt3 != n - 1 && cnt1 != 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    For(i, 1, n)
    {
        if (row[i] == 1)
            continue;
        int cnt = 0;
        For(i1, 1, n)
        {
            if (i == i1)
                continue;
            bool ok = 1;
            For(j, 1, n) ok &= (a[i][j] == a[i1][j]);
            if (ok)
                ++cnt;
        }
        if (cnt != 1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "POSSIBLE\n";
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
    cin >> t;
    while (t--)
        ttk32();
    return 0;
}