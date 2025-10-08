#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int nmax = 55;

int r, s;
char seats[nmax][nmax];
int value[nmax][nmax];
int res = 0, decr = 0;

void not_main()
{
    cin >> r >> s;
    for (int i = 0; i <= r + 1; ++i)
        seats[i][0] = seats[i][s + 1] = '.';
    for (int i = 0; i <= s + 1; ++i)
        seats[0][i] = seats[r + 1][i] = '.';

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= s; ++j)
            cin >> seats[i][j];

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= s; ++j)
            if (seats[i][j] == 'o')
            {
                ++value[i - 1][j - 1];
                ++value[i][j - 1];
                ++value[i + 1][j - 1];
                ++value[i - 1][j];
                ++value[i + 1][j];
                ++value[i - 1][j + 1];
                ++value[i][j + 1];
                ++value[i + 1][j + 1];
            }

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= s; ++j)
            if (seats[i][j] == 'o')
            {
                if (seats[i - 1][j - 1] == 'o')
                    ++decr;
                if (seats[i][j - 1] == 'o')
                    ++decr;
                if (seats[i + 1][j - 1] == 'o')
                    ++decr;
                if (seats[i - 1][j] == 'o')
                    ++decr;
                if (seats[i + 1][j] == 'o')
                    ++decr;
                if (seats[i - 1][j + 1] == 'o')
                    ++decr;
                if (seats[i][j + 1] == 'o')
                    ++decr;
                if (seats[i + 1][j + 1] == 'o')
                    ++decr;
            }

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= s; ++j)
            if (seats[i][j] == '.')
                maximize(res, value[i][j]);

    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= s; ++j)
            if (seats[i][j] == 'o')
                res += value[i][j];

    cout << res - decr / 2;
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("HANDSHAKE.INP", "r"))
    {
        freopen("HANDSHAKE.INP", "r", stdin);
        freopen("HANDSHAKE.OUT", "w", stdout);
    }
    not_main();
    return 0;
}