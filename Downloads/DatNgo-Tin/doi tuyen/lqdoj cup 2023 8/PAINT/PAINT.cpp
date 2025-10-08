#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int unpainted_pos[2010];

void sub1_process()
{
    b *= 2;
    int w = 1;

    while (a * w + b * w < n)
        ++w;

    cout << w;
}

void sub2_loop(int &w)
{
    int t_a = 1;
    int prev_paint_startPos = unpainted_pos[1];
    for (int i = 2; i <= n; ++i)
    {
        if (unpainted_pos[i] > prev_paint_startPos + w - 1)
        {
            ++t_a;
            prev_paint_startPos = unpainted_pos[i];
        }
        if (t_a > a)
        {
            ++w;
            sub2_loop(w);
        }
    }
}

void sub2_process()
{
    int w = n / a;
    if (n % a)
        ++w; // minimum w

    sub2_loop(w);

    cout << w;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    if (fopen("paint.inp", "r"))
    {
        freopen("paint.inp", "r", stdin);
        freopen("paint.out", "w", stdout);
    }

    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        cin >> unpainted_pos[i];

    bool sub1 = true;
    for (int i = 2; i <= n; ++i)
    {
        if (unpainted_pos[i] != unpainted_pos[i - 1] + 1)
        {
            sub1 = false;
            break;
        }
    }

    if (sub1)
        sub1_process();
    else
    {
        sort(unpainted_pos + 1, unpainted_pos + n + 1);
        if (!b)
            sub2_process();
    }
    return 0;
}