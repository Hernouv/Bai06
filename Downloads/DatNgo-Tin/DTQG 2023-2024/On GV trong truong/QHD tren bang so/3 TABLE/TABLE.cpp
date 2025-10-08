#include <bits/stdc++.h>
#define FOR(x, a, b) for (int x = a; x <= b; ++x)
#define FOD(x, a, b) for (int x = a; x >= b; --x)
#define REP(x, a, b) for (int x = a; x < b; ++x)
#define ll long long
#define fi first
#define se second
#define DEBUG(X)                          \
    {                                     \
        cout << #X << " = " << X << endl; \
    }
#define PR(A, n)             \
    {                        \
        cout << #A << " = "; \
        FOR(_, 1, n)         \
        cout << A[_] << " "; \
        cout << endl;        \
    }
#define PR0(A, n)            \
    {                        \
        cout << #A << " = "; \
        REP(_, 0, n)         \
        cout << A[_] << " "; \
        cout << endl;        \
    }

using namespace std;

const int maxn = 1e3 + 10;

stack<int> st;

int a[maxn][maxn], g[maxn][maxn], f[maxn][maxn], dp[maxn][maxn];
int L[maxn], R[maxn], H[maxn];
int n, m;

void Solve(int V1, int V2)
{
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    memset(H, 0, sizeof H);
    FOD(i, n, 1)
    {
        FOR(j, 1, m)
        if (a[i][j] == V1 || a[i][j] == V2)
            ++H[j];
        else
            H[j] = 0;
        while (st.size())
            st.pop();
        FOR(j, 1, m)
        {
            while (st.size() && H[st.top()] >= H[j])
                st.pop();
            if (st.empty())
                L[j] = 1;
            else
                L[j] = st.top() + 1;
            st.push(j);
        }
        while (st.size())
            st.pop();
        FOD(j, m, 1)
        {
            while (st.size() && H[st.top()] >= H[j])
                st.pop();
            if (st.empty())
                R[j] = m;
            else
                R[j] = st.top() - 1;
            st.push(j);
        }
        FOR(j, 1, m)
        g[i][H[j]] = max(g[i][H[j]], R[j] - L[j] + 1);
    }
    FOR(i, 1, n)
    FOD(j, n, 1)
    {
        g[i + 1][j - 1] = max(g[i + 1][j - 1], g[i][j]);
        g[i][j - 1] = max(g[i][j - 1], g[i][j]);
    }
    FOR(i, 1, n)
    FOR(j, i, n)
    f[i][j] = max(f[i][j - 1], (j - i + 1) * g[i][j - i + 1]);
    FOR(i, 1, n)
    FOR(j, i, n)
    dp[i][j] = max(dp[i][j], max(dp[i + 1][j], f[i][j]));
}

inline void Read(int &n)
{
    n = 0;
    char c;
    do
    {
        c = getchar();
    } while (!isdigit(c));
    do
    {
        n = n * 10 + c - 48;
        c = getchar();
    } while (isdigit(c));
}

inline void Write(int n)
{
    if (n == 0)
    {
        putchar('0');
        return;
    }
    char c[40];
    int cnt = 0;
    while (n)
    {
        c[++cnt] = n % 10 + 48;
        n /= 10;
    }
    FOD(i, cnt, 1)
    putchar(c[i]);
}

int main()
{
    freopen("TABLE.INP", "r", stdin);
    freopen("TABLE.OUT", "w", stdout);
    Read(n);
    Read(m);
    FOR(i, 1, n)
    FOR(j, 1, m)
    Read(a[i][j]);
    Solve(0, 1);
    Solve(1, 2);
    FOR(len, 1, n)
    {
        FOR(i, 1, n)
        {
            int j = i + len - 1;
            dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j]);
        }
    }
    int q;
    Read(q);
    while (q--)
    {
        int l, r;
        Read(l);
        Read(r);
        Write(dp[l][r]);
        putchar('\n');
    }
    return 0;
}
