#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[550][550], b[550][550], c[550][550];

void matrix_mul()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            for (int x = 1; x <= m; ++x)
                c[i][j] += a[i][x] * b[x][j];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // freopen("matrix_mul.inp", "r", stdin);
    // freopen("matrix_mul.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= k; ++j)
            cin >> b[i][j];

    matrix_mul();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; ++j)
            cout << c[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}