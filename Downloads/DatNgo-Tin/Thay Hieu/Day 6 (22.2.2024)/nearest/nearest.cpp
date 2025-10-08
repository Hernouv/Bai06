#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e6 + 10;
typedef pair<int, int> ii;
#define fi first
#define se second

stack<ii> h_st;
int h[nmax];
int L[nmax], R[nmax];
int n;

void not_main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    for (int i = 1; i <= n; ++i)
    {
        while (!h_st.empty() and h_st.top().fi <= h[i])
            h_st.pop();

        if (!h_st.empty())
            L[i] = h_st.top().se;

        h_st.emplace(h[i], i);
    }

    while (!h_st.empty())
        h_st.pop();

    for (int i = n; i >= 1; --i)
    {
        while (!h_st.empty() and h_st.top().fi <= h[i])
            h_st.pop();

        if (!h_st.empty())
            R[i] = h_st.top().se;

        h_st.emplace(h[i], i);
    }
    for (int i = 1; i <= n; ++i)
        cout << L[i] << ' ' << R[i] << '\n';
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("hnouv.inp", "r"))
    {
        freopen("hnouv.inp", "r", stdin);
        freopen("hnouv.out", "w", stdout);
    }
    not_main();
    return 0;
}