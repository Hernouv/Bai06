#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e3 + 7;

int n, m, ans = 0;
int h[N][N];
int l[N], r[N];

int cal(int x, int y)
{
    int s = y * (y + 1) / 2;
    s = (s * x) + ((x * (x - 1)) / 2) * y;
    return s;
}

void solve(int *a)
{
    stack<int> st;
    for (int i = 1; i <= m; ++i)
    {
        while (st.size() and a[i] < a[st.top()])
            st.pop();
        l[i] = (st.size() ? st.top() : 0);
        st.push(i);
    }
    st = stack<int>();
    for (int i = m; i >= 1; --i)
    {
        while (st.size() and a[i] <= a[st.top()])
            st.pop();
        r[i] = (st.size() ? st.top() : m + 1);
        st.push(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        ans += cal(i - l[i], r[i] - i) * (a[i] * (a[i] + 1) / 2);
    }
}

void not_main()
{
    cin >> n >> m;
    cerr << cal(2, 1) << '\n';

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            char x;
            cin >> x;
            if (x == '.')
                h[i][j] = h[i - 1][j] + 1;
            else
                h[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
        solve(h[i]);
    cout << ans;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}