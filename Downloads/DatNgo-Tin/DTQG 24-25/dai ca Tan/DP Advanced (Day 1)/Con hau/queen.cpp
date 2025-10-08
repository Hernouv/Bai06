#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 1e3 + 10;

int vert[nmax][nmax];
int hori[nmax][nmax];
int diagL[nmax][nmax];
int diagR[nmax][nmax];

char grid[nmax][nmax];
int n, m;

void not_main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> grid[i][j];

    for (int i = 1; i <= m; ++i)
    {
        if (grid[1][i] == '.')
            vert[1][i] = 1;
        for (int j = 2; j <= n; ++j)
            if (grid[j][i] == '.')
                vert[j][i] = vert[j - 1][i] + 1;

        for (int j = n - 1; j >= 1; --j)
            if (grid[j][i] == '.')
                maximize(vert[j][i], vert[j + 1][i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (grid[i][1] == '.')
            hori[i][1] = 1;
        for (int j = 2; j <= m; ++j)
            if (grid[i][j] == '.')
                hori[i][j] = hori[i][j - 1] + 1;

        for (int j = m - 1; j >= 1; --j)
            if (grid[i][j] == '.')
                maximize(hori[i][j], hori[i][j + 1]);
    }

    for (int i = 1; i <= m; ++i)
    {
        if (grid[1][i] == '.')
            diagR[1][i] = 1;
        int j;
        for (j = 1; 1 + j <= n and i + j <= m; ++j)
            if (grid[1 + j][i + j] == '.')
                diagR[1 + j][i + j] = diagR[j][i + j - 1] + 1;
        --j;
        for (; j >= 0; --j)
            if (grid[1 + j][i + j] == '.')
                maximize(diagR[1 + j][i + j], diagR[2 + j][i + j + 1]);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (grid[i][1] == '.')
            diagR[i][1] = 1;
        int j;
        for (j = 1; i + j <= n and 1 + j <= m; ++j)
            if (grid[i + j][1 + j] == '.')
                diagR[i + j][1 + j] = diagR[i + j - 1][j] + 1;
        --j;
        for (; j >= 0; --j)
            if (grid[i + j][1 + j] == '.')
                maximize(diagR[i + j][1 + j], diagR[i + j + 1][2 + j]);
    }

    for (int i = 1; i <= m; ++i)
    {
        if (grid[1][i] == '.')
            diagL[1][i] = 1;
        int j;
        for (j = 1; 1 + j <= n and i - j >= 1; ++j)
            if (grid[1 + j][i - j] == '.')
                diagL[1 + j][i - j] = diagL[j][i - j + 1] + 1;
        --j;
        for (; j >= 0; --j)
            if (grid[1 + j][i - j] == '.')
                maximize(diagL[1 + j][i - j], diagL[2 + j][i - j - 1]);
    }
    for (int i = 2; i <= n; ++i)
    {
        if (grid[i][m] == '.')
            diagL[i][m] = 1;
        int j;
        for (j = 1; i + j <= n and m - j >= 1; ++j)
            if (grid[i + j][m - j] == '.')
                diagL[i + j][m - j] = diagL[i + j - 1][m - j + 1] + 1;
        --j;
        for (; j >= 0; --j)
            if (grid[i + j][m - j] == '.')
                maximize(diagL[i + j][m - j], diagL[i + j + 1][m - j - 1]);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (grid[i][j] == '#')
            {
                cout << 0 << ' ';
                continue;
            }
            cout << vert[i][j] + hori[i][j] + diagR[i][j] + diagL[i][j] - 3 << ' ';
        }
        cout << '\n';
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    not_main();
    return 0;
}