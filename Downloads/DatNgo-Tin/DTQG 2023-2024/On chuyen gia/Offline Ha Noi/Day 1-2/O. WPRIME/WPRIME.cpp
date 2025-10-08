#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int mod = 1000000;

int n, q, s, sum = 0;
int L, R, u, v;
int a[N], pref[400][80000];
int block_size, cnt = 0;
int pr[N], inv[N], nto[N];
vector<int> b[N];

int pos(int x) { return (x - 1) / block_size + 1; }

void erastos()
{
    pr[0] = pr[1] = 1;
    for (int p = 2; p * p < N; p++)
    {
        if (pr[p] == 0)
        {
            for (int k = p * p; k < N; k += p)
                pr[k] = p;
        }
    }
    for (int p = 2; p < N; ++p)
    {
        if (pr[p] == 0)
        {
            pr[p] = p;
            inv[p] = ++cnt;
            nto[cnt] = p;
        }
    }
}

void init()
{
    memset(pref, 0, sizeof pref);
    block_size = sqrt(n);

    for (int i = 1; i <= n; ++i)
    {
        int p = pos(i), x = a[i];

        while (x > 1)
        {
            int y = pr[x];
            int cnt2 = 0;
            while (x % y == 0)
            {
                ++cnt2;
                x /= y;
                b[i].push_back(y);
            }
            pref[p][inv[y]] += cnt2;
        }
        sort(b[i].begin(), b[i].end());
    }

    for (int i = 1; i <= pos(n); ++i)
        for (int j = 1; j <= cnt; ++j)
            pref[i][j] += pref[i][j - 1];
}

int calc(int l, int r)
{
    int ans = 0;
    for (int i = l; i <= r; ++i)
        ans += upper_bound(b[i].begin(), b[i].end(), v) - lower_bound(b[i].begin(), b[i].end(), u);
    return ans;
}

int calc()
{
    if (pos(R) - pos(L) <= 1)
        return calc(L, R);
    int l = lower_bound(nto + 1, nto + cnt + 1, u) - nto;
    int r = upper_bound(nto + 1, nto + cnt + 1, v) - nto - 1;
    if (l > r)
        return 0;

    int ans = calc(L, pos(L) * block_size) + calc((pos(R) - 1) * block_size + 1, R);
    for (int i = pos(L) + 1; i <= pos(R) - 1; ++i)
    {
        ans += pref[i][r] - pref[i][l - 1];
    }
    return ans;
}

namespace dbg
{
    int pre[100][100];
    void testPtich()
    {
        cerr << "DBG:\n";
        memset(pre, 0, sizeof pre);
        block_size = sqrt(n);
        for (int i = 7; i <= 9; ++i)
        {
            int p = pos(i), x = a[i];

            while (x > 1)
            {
                int y = pr[x];
                int cnt2 = 0;
                while (x % y == 0)
                {
                    ++cnt2;
                    x /= y;
                }
                cerr << y << ' ' << cnt2 << '\n';
                pre[p][inv[y]] += cnt2;
            }
        }
        for (int i = 1; i <= 100; ++i)
            pre[3][i] += pre[3][i - 1];

        cerr << '\n';
        for (int i = 1; i <= 23; ++i)
            cerr << pre[3][i] << ' ';
        cerr << '\n';
        cerr << "END.\n";
    }

    void testPtich1()
    {
        cerr << "DBG:\n";
        for (int i = 6; i <= 10; ++i)
        {
            cerr << a[i] << ": ";
            for (int j : b[i])
                cerr << j << ' ';
            cerr << '\n';
        }
        cerr << "END.\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    erastos();
    cin >> n >> q >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    init();

    while (q--)
    {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        L = 1 + min((x + sum * s) % n, (y + sum * s) % n);
        R = 1 + max((x + sum * s) % n, (y + sum * s) % n);
        u = 1 + min((z + sum * s) % mod, (t + sum * s) % mod);
        v = 1 + max((z + sum * s) % mod, (t + sum * s) % mod);

        int ans = calc();
        sum += ans;
        cout << ans << '\n';
    }
    return 0;
}