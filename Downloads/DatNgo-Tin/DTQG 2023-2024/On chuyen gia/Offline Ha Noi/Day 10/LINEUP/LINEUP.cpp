#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1010, MOD = 1e9 + 7, P = 2, Q = 3;

int pq_pow[2 * MAXN][2 * MAXN];
int h[2 * MAXN][2 * MAXN];

int add(int a, int b)
{
    int res = a + b;
    if (res >= MOD)
        res -= MOD;
    return res;
}
int sub(int a, int b) { return add(a, MOD - b); }
int mul(int a, int b) { return (ll)a * b % MOD; }

void precalc(const vector<string> &a)
{
    for (int i = 0; i < 2 * MAXN; i++)
    {
        for (int j = 0; j < 2 * MAXN; j++)
        {
            if (i == 0 && j == 0)
                pq_pow[i][j] = 1;
            else if (i == 0)
                pq_pow[i][j] = mul(pq_pow[i][j - 1], Q);
            else
                pq_pow[i][j] = mul(pq_pow[i - 1][j], P);
        }
    }

    int n = a.size(), m = a[0].size();
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = 0; j < 2 * m; j++)
        {
            int val = mul(a[i % n][j % m] == '.', pq_pow[i][j]);
            h[i + 1][j + 1] = sub(add(val,
                                      add(h[i + 1][j], h[i][j + 1])),
                                  h[i][j]);
        }
    }
}

int get_h(int x, int y, int dx, int dy)
{
    return sub(add(h[x + dx][y + dy], h[x][y]),
               add(h[x][y + dy], h[x + dx][y]));
}

bool is_equal(int x1, int y1, int x2, int y2, int dx, int dy)
{
    int val1 = mul(get_h(x1, y1, dx, dy), pq_pow[x2][y2]);
    int val2 = mul(get_h(x2, y2, dx, dy), pq_pow[x1][y1]);
    return val1 == val2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    precalc(a);

    int sol_x = 0, sol_y = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            int lo_dx = 0, hi_dx = n;
            while (lo_dx + 1 < hi_dx)
            {
                int dx = (lo_dx + hi_dx) / 2;
                if (is_equal(sol_x, sol_y, x, y, dx, m))
                    lo_dx = dx;
                else
                    hi_dx = dx;
            }
            int dx = lo_dx;

            int lo_dy = 0, hi_dy = m;
            while (lo_dy + 1 < hi_dy)
            {
                int dy = (lo_dy + hi_dy) / 2;
                if (is_equal(sol_x + dx, sol_y, x + dx, y, 1, dy))
                    lo_dy = dy;
                else
                    hi_dy = dy;
            }
            int dy = lo_dy;

            if (a[(x + dx) % n][(y + dy) % m] <
                a[(sol_x + dx) % n][(sol_y + dy) % m])
            {
                sol_x = x;
                sol_y = y;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[(sol_x + i) % n][(sol_y + j) % m];
        cout << '\n';
    }

    return 0;
}