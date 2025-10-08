#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int nmax = 2e5 + 5;

int d0[3][nmax], d1[3][nmax];
ll ps0[3][nmax], ps1[3][nmax];
ll psi0[3][nmax], psi1[3][nmax];
int X[nmax], Y[nmax], T[nmax], B[nmax], L[nmax], R[nmax];
ll res[nmax];
int N, Q;

void mosaic()
{
    int nx = N;
    while (nx < 3)
    {
        X[nx] = 0;
        ++nx;
    }
    int ny = N;
    while (ny < 3)
    {
        Y[ny] = 0;
        ++ny;
    }

    for (int i = 0; i < nx; i++)
        d0[0][i] = X[i];
    for (int i = 0; i < ny; i++)
        d1[0][i] = Y[i];

    for (int i = 1; i < 3; i++)
    {
        d0[i][0] = Y[i];
        d1[i][0] = X[i];
        for (int j = 1; j < nx; j++)
        {
            d0[i][j] = (1 - d0[i - 1][j]) and (1 - d0[i][j - 1]);
        }
        for (int j = 1; j < ny; j++)
        {
            d1[i][j] = (1 - d1[i - 1][j]) and (1 - d1[i][j - 1]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < nmax; j++)
        {
            ps0[i][j] = (j ? ps0[i][j - 1] : 0) + d0[i][j];
            ps1[i][j] = (j ? ps1[i][j - 1] : 0) + d1[i][j];
            psi0[i][j] = (j ? psi0[i][j - 1] : 0) + d0[i][j] * j;
            psi1[i][j] = (j ? psi1[i][j - 1] : 0) + d1[i][j] * j;
        }
    }

    auto h = [&](int *d0, int *d1, ll *s0, ll *s1, ll *si0, ll *si1, int x, int y)
    {
        ll ans = 0;
        ans -= (si1[x - 1] - si1[x - y + 2]);
        ans -= (si0[y - 1] - si0[1]);
        ans += 1ll * (y - 2) * (s1[x - y + 2] - s1[2]);
        ans += 1ll * y * (s0[y - 1] - s0[1]);
        ans += 1ll * x * (s1[x - 1] - s1[x - y + 2]);
        return ans;
    };
    auto g = [&](int x, int y)
    {
        if (x < 0 or y < 0)
            return 0ll;
        ll ans = 0;
        if (x <= 2)
        {
            for (int i = 0; i <= x; i++)
                ans += ps0[i][y];
            return ans;
        }
        if (y <= 2)
        {
            for (int i = 0; i <= y; i++)
                ans += ps1[i][x];
            return ans;
        }
        for (int i = 0; i <= 2; i++)
            ans += ps0[i][y];
        for (int i = 0; i <= 2; i++)
            ans += ps1[i][x] - ps1[i][2];
        if (x >= y)
            ans += h(d0[2], d1[2], ps0[2], ps1[2], psi0[2], psi1[2], x, y);
        else
            ans += h(d1[2], d0[2], ps1[2], ps0[2], psi1[2], psi0[2], y, x);
        return ans;
    };

    for (int i = 0; i < Q; i++)
        res[i] += g(B[i], R[i]) - g(B[i], L[i] - 1) - g(T[i] - 1, R[i]) + g(T[i] - 1, L[i] - 1);
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    string s;
    cin >> s;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> X[i];
    for (int i = 0; i < N; ++i)
        cin >> Y[i];
    cin >> Q;
    for (int i = 0; i < Q; ++i)
        cin >> T[i] >> B[i] >> L[i] >> R[i];

    mosaic();
    cout << "Wm5rkGNobnYjFI7TIY17RAm6FAQ2LlO9\nOK\n";
    for (int i = 0; i < Q; ++i)
        cout << res[i] << '\n';

    return 0;
}