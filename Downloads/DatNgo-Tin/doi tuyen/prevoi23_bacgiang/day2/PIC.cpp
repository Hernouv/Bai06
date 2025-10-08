#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define i4 pair<ii, ii>
#define fi first
#define se second

template <class T>
inline bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T>
inline bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }

const int outbound = 1e9 + 7;

vector<i4> rectangles;
int mx1 = outbound, my1 = outbound, mx2 = -outbound, my2 = -outbound;
int n;

bool grid_s1[210][210];

void sub1()
{
    int borderline_length = 0;
    for (i4 rekt : rectangles)
    {
        int x1 = rekt.fi.fi + 101;
        int y1 = rekt.fi.se + 101;
        int x2 = rekt.se.fi + 101;
        int y2 = rekt.se.se + 101;
        for (int i = x1; i <= x2; ++i)
            for (int j = y1; j <= y2; ++j)
                grid_s1[i][j] = true;
    }

    mx1 += 101;
    my1 += 101;
    mx2 += 101;
    my2 += 101;

    for (int i = mx1 - 1; i <= mx2 + 1; ++i)
        for (int j = my1 - 1; j <= my2 + 1; ++j)
        {
            if (grid_s1[i][j])
            {
                if (!grid_s1[i - 1][j])
                    ++borderline_length;
                if (!grid_s1[i + 1][j])
                    ++borderline_length;
                if (!grid_s1[i][j - 1])
                    ++borderline_length;
                if (!grid_s1[i][j + 1])
                    ++borderline_length;
            }
            else
            {
                if (grid_s1[i - 1][j])
                    ++borderline_length;
                if (grid_s1[i + 1][j])
                    ++borderline_length;
                if (grid_s1[i][j - 1])
                    ++borderline_length;
                if (grid_s1[i][j + 1])
                    ++borderline_length;
            }
        }
    cout << borderline_length / 2;
}

void not_main()
{
    cin >> n;
    int a, b, c, d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c >> d;
        minimize(mx1, a);
        minimize(my1, b);
        maximize(mx2, c);
        maximize(my2, d);
        rectangles.push_back({{a, b}, {c, d}});
    }

    if (n <= 100 and mx1 >= -100 and my1 >= -100 and mx2 <= 100 and my2 <= 100)
    {
        sub1();
        return;
    }
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("PIC.INP", "r"))
    {
        freopen("PIC.INP", "r", stdin);
        freopen("PIC.OUT", "w", stdout);
    }
    not_main();
    return 0;
}